
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>

int main(){
    int sock;
    struct sockaddr_in server, client;
    socklen_t len;
    char vote[10], reply[100];

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(8893);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr*)&server, sizeof(server));

    len = sizeof(client);
    recvfrom(sock, vote, 10, 0, (struct sockaddr*)&client, &len);

    int v = atoi(vote);
    if(v>=1 && v<=3){
        sprintf(reply,"Vote recorded for Candidate %d", v);
    } else {
        strcpy(reply,"Invalid vote");
    }

    sendto(sock, reply, strlen(reply), 0, (struct sockaddr*)&client, len);
    return 0;
}
