#ifndef _C302_H_
#define _C302_H_

#define SERVER_STRING "Server: C302 by Fumiama/1.0\r\n"
#define HTTP302 "HTTP/1.0 302 Moved Temporarily\r\n"
#define LOCATION "Location: "
#define HTTP302HEAD HTTP302 SERVER_STRING LOCATION

#define HTTP200 "HTTP/1.0 200 OK\r\n"
#define H400 "HTTP/1.0 400 BAD REQUEST\r\nContent-Type: text/html\r\n\r\n<P>%s\r\n"
#define H404 "HTTP/1.0 404 NOT FOUND\r\nContent-Type: text/html\r\n\r\n<HTML><TITLE>Not Found</TITLE>\r\n<BODY><P>%s\r\n</BODY></HTML>\r\n"
#define H500 "HTTP/1.0 500 Internal Server Error\r\nContent-Type: text/html\r\n\r\n<P>%s\r\n"
const char* types[] = {H400, H404, H500};
const unsigned char typel[] = {59, 111, 69};
enum ERRCODE {HTTP400, HTTP404, HTTP500};
typedef enum ERRCODE ERRCODE;

static const char* urls[] = {
    "https://bocchi.rocks/assets/img/page/character/hitori/main.png",   // 後藤ひとり
    "https://bocchi.rocks/assets/img/page/character/nijika/main.png",   // 伊地知虹夏
    "https://bocchi.rocks/assets/img/page/character/ryo/main.png",      // 山田リョウ
    "https://bocchi.rocks/assets/img/page/character/ikuyo/main.png"     // 喜多郁代
};

static const unsigned short urlsl[] = {62, 62, 59, 61};

#endif
