
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
    int sock, client;
    struct sockaddr_in server, client_addr;
    socklen_t c;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8889);

    bind(sock, (struct sockaddr *)&server, sizeof(server));
    listen(sock, 5);

    while(1){
        c = sizeof(struct sockaddr_in);
        client = accept(sock, (struct sockaddr *)&client_addr, &c);

        if(fork()==0){
            char fname[100], buffer[1024];
            recv(client, fname, 100, 0);

            int fd = open(fname, O_RDONLY);
            if(fd<0){
                send(client, "File not found", 14, 0);
            } else {
                int n;
                while((n=read(fd, buffer, sizeof(buffer)))>0){
                    send(client, buffer, n, 0);
                }
                close(fd);
            }
            close(client);
            exit(0);
        }
    }
}
