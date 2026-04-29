
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>

int main(){
    int sock;
    struct sockaddr_in server;
    char ch;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(8890);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Enter character: ");
    scanf(" %c", &ch);

    sendto(sock, &ch, 1, 0, (struct sockaddr*)&server, sizeof(server));
    return 0;
}
