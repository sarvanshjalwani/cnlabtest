
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>

int main(){
    int sock;
    struct sockaddr_in server;
    char vote[10], reply[100];

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(8893);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Enter vote (1-3): ");
    scanf("%s", vote);

    sendto(sock, vote, strlen(vote), 0, (struct sockaddr*)&server, sizeof(server));

    socklen_t len = sizeof(server);
    recvfrom(sock, reply, 100, 0, (struct sockaddr*)&server, &len);

    printf("%s\n", reply);
    return 0;
}
