
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include <stdlib.h>


int main(){
    int sock, client;
    struct sockaddr_in server, client_addr;
    socklen_t c;
    char buffer[100], name[100];
    FILE *fp;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    bind(sock, (struct sockaddr *)&server, sizeof(server));
    listen(sock, 1);

    c = sizeof(struct sockaddr_in);
    client = accept(sock, (struct sockaddr *)&client_addr, &c);

    recv(client, buffer, 100, 0);

    fp = fopen("data.txt", "r");
    int addr;
    int found = 0;
    while(fscanf(fp, "%d %s", &addr, name) != EOF){
        if(addr == atoi(buffer)){
            send(client, name, strlen(name), 0);
            found = 1;
            break;
        }
    }
    if(!found){
        send(client, "Address not found", 17, 0);
    }

    fclose(fp);
    close(client);
    close(sock);
    return 0;
}
