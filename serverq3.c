
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>

int main(){
    int sock;
    struct sockaddr_in server, client1, client2;
    socklen_t len;
    char ch;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(8890);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr*)&server, sizeof(server));

    len = sizeof(client1);
    recvfrom(sock, &ch, 1, 0, (struct sockaddr*)&client1, &len);

    ch = ch - 1;

    client2.sin_family = AF_INET;
    client2.sin_port = htons(8891);
    client2.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(sock, &ch, 1, 0, (struct sockaddr*)&client2, sizeof(client2));
    return 0;
}
