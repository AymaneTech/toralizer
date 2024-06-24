#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PROXY "127.0.0.1"
#define PROXYPORT 9050

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

typedef struct proxy_request {
  int8 vn;
  int8 cd;
  int16 dstport;
  int32 dstrip;
  unsigned char userid[8];
} Req;

typedef struct proxy_response {
  int8 vn;
  int8 cd;
  int16 _;
  int32 __;
} Res;
