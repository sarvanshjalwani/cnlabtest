
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>

int main(){
    int sock;
    struct sockaddr_in server;
    socklen_t len;
    char ch;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(8891);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr*)&server, sizeof(server));

    len = sizeof(server);
    recvfrom(sock, &ch, 1, 0, (struct sockaddr*)&server, &len);

    printf("Received: %c\n", ch);
    return 0;
}
