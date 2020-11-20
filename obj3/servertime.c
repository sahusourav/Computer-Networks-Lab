#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<time.h>
#define SERV_TCP_PORT 5037
int main(int argc,char**argv)
{
    int sockfd,newsockfd,clength;
    struct sockaddr_in serv_addr,cli_addr;
    char buffer[4096];
    time_t tick;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=INADDR_ANY;
    serv_addr.sin_port=htons(SERV_TCP_PORT);
    printf("\nStart");
    bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    printf("\nServer Listening...");
    printf("\n");
    listen(sockfd,5);
    clength=sizeof(cli_addr);
    newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clength);
    printf("\nRequest Accepted");
    printf("\n");
    tick=time(NULL);
    snprintf(buffer,sizeof(buffer),"%s",ctime(&tick));
    printf("%s",buffer);
    write(newsockfd,buffer,100);
    printf("\n");
    close(sockfd);
    return 0;
}
