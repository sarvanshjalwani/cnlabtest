
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int sock;
    struct sockaddr_in server;
    char fname[100], buffer[1024];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8889);

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    printf("Enter filename: ");
    scanf("%s", fname);

    send(sock, fname, strlen(fname), 0);

    int fd = creat("received_file", 0666);
    int n;
    while((n = recv(sock, buffer, sizeof(buffer), 0)) > 0){
        write(fd, buffer, n);
    }

    close(fd);
    close(sock);
    return 0;
}
