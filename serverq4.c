
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(){
    int sock, client;
    struct sockaddr_in server, client_addr;
    socklen_t c;
    char buffer[100];
    int a,b,res;
    char op;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8892);

    bind(sock,(struct sockaddr*)&server,sizeof(server));
    listen(sock,1);

    c=sizeof(struct sockaddr_in);
    client=accept(sock,(struct sockaddr*)&client_addr,&c);

    recv(client,buffer,100,0);
    sscanf(buffer,"%d %d %c",&a,&b,&op);

    if(op=='+') res=a+b;
    else if(op=='-') res=a-b;
    else if(op=='*') res=a*b;
    else if(op=='/'){
        if(b==0){
            send(client,"Division by zero",16,0);
            return 0;
        }
        res=a/b;
    } else {
        send(client,"Invalid operator",16,0);
        return 0;
    }

    sprintf(buffer,"%d",res);
    send(client,buffer,strlen(buffer),0);

    close(client);
    close(sock);
    return 0;
}
