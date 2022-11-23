#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/uio.h>
#include <time.h>
#include "c302.h"

static void http_error(errcode_enum_t code, char* msg) {
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
    uint32_t i = rand() % (sizeof(urls)/sizeof(char*));
    uint32_t len = sizeof(HTTP302HEAD)-1 + urlsl[i] + 4 + sizeof(CONTENT)-1;
    const struct iovec iov[5] = {
        {(void *)&len, sizeof(uint32_t)},
        {HTTP302HEAD, sizeof(HTTP302HEAD)-1},
        {(void *)urls[i], urlsl[i]},
        {"\r\n\r\n", 4},
        {CONTENT, sizeof(CONTENT)-1}
    };
    return  writev(1, (const struct iovec *)&iov, 5) != len+sizeof(uint32_t);
}
