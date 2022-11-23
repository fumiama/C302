#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/uio.h>
#include <time.h>
#include "c302.h"

static void http_error(ERRCODE code, char* msg) {
    uint32_t len = strlen(msg) + typel[code];
    char* str = malloc(len);
    sprintf(str, types[code], msg);
    const struct iovec iov[2] = {{&len, sizeof(uint32_t)}, {str, len}};
    writev(1, (const struct iovec *)&iov, 2);
    free(str);
}

// Usage: c302 method query_string
int main(int argc, char **argv) {
    if (argc != 3) {
        http_error(HTTP500, "Argument Count Error.");
        return 1;
    }
    srand(time(NULL));
    unsigned int i = rand() % (sizeof(urls)/sizeof(char*));
    const struct iovec iov[3] = {{HTTP302HEAD, sizeof(HTTP302HEAD)}, {(void *)urls[i], urlsl[i]}, {"\r\n\r\n", 4}};
    writev(1, (const struct iovec *)&iov, 3);
    return 0;
}
