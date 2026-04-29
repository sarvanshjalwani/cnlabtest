
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(){
    int sock;
    struct sockaddr_in server;
    char buffer[100];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8892);

    connect(sock, (struct sockaddr*)&server, sizeof(server));

    printf("Enter expression (e.g. 20 5 +): ");
    fgets(buffer, sizeof(buffer), stdin);

    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, 100, 0);

    printf("Result: %s\n", buffer);
    return 0;
}
