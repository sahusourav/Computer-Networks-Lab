#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#define SERVER_TCP_PORT 5035

int main(int argc, char**argv)
{
	int sockfd, newsockfd, clength, n, k;
	char buffer[200];

	struct sockaddr_in serv_addr, cli_addr;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(SERVER_TCP_PORT);
	
	printf("Start\n");
	bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	printf("Listening...\n");
	
	printf("Accepted...\b\n");
	printf("Enter 'Bye' to end chat.\n");
	while(1)
	{
	listen(sockfd, 5);
	clength = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clength);
	n = read(newsockfd, buffer, 200);
	buffer[n] = 0;
	printf("Server received the message: %s\n", buffer);
	printf("Enter a message for client:\n");
	fgets(buffer, sizeof(buffer), stdin);
	write(newsockfd, buffer, 200);
	if(!strncmp(buffer, "Bye", 3))
			break;
	} 
	close(sockfd);
	
	return 0;
}
