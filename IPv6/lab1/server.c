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
	int sockfd, newsockfd, clength;
	char buffer;

	struct sockaddr_in6 serv_addr, cli_addr;
	
	sockfd = socket(AF_INET6, SOCK_STREAM, 0);
	serv_addr.sin6_family = AF_INET6;
	serv_addr.sin6_addr = in6addr_any;
	serv_addr.sin6_port = htons(SERVER_TCP_PORT);
	
	printf("Start\n");
	bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	printf("Listening...\n");
	listen(sockfd, 5);
	clength = sizeof(cli_addr);

	while(1)
	{
		printf("\nWaiting...\n");
		newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clength);
		printf("Accepted...\b\n");

		read(newsockfd, &buffer, sizeof(buffer));
		printf("Client message: %c\n", buffer);
		buffer++;
		write(newsockfd, &buffer, sizeof(char));
	}

	close(sockfd);
	
	return 0;
}
