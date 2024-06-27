#include "toralize.h"
#include <stdio.h>

int print_err(char *err) {
  perror(err);
  return (-1);
}

int main(int argc, char *argv[]) {

  char *host;
  int port;
  int s;
  sock sock;

  if (argc < 3) {
    fprintf(stderr, "Usage : %s <host> <port> \n", argv[0]);
    return -1;
  }

  host = argv[1];
  port = atoi(argv[2]);

  s = socket(AF_INET, SOCK_STREAM, 0);

  if (s < 0)
    print_err("socket");

  sock.sin_family = AF_INET;
  sock.sin_port = htons(PROXYPORT);
  sock.sin_addr.s_addr = inet_addr(PROXY);

  if (connect(s, (SA *)&sock, sizeof(sock)))
    print_err("connect");

  printf("connected to proxy \n");

  close(s);

  return 0;
}
