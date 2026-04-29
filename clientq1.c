
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(){
    int sock;
    struct sockaddr_in server;
    char msg[100], reply[100];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    printf("Enter address: ");
    scanf("%s", msg);

    send(sock, msg, strlen(msg), 0);
    recv(sock, reply, 100, 0);

    printf("Server reply: %s\n", reply);

    close(sock);
    return 0;
}
