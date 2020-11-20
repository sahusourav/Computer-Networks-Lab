#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#define SERV_TCP_PORT 5035

int main()
{
	int sockfd, len, n;
	
	struct sockaddr_in cli_addr;
	//struct hostent *server;
	len = sizeof(cli_addr);
	char buffer[200];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	cli_addr.sin_family = AF_INET;
	cli_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	cli_addr.sin_port = htons(SERV_TCP_PORT);

	printf("Ready for sending...\n");
	connect(sockfd, (struct sockaddr*)&cli_addr, len);
	printf("Enter the message to send\n");
	printf("Client:\n");
	fgets(buffer, 200, stdin);
	write(sockfd, buffer, sizeof(buffer));
	n = read(sockfd, buffer, sizeof(buffer));

	buffer[n] = 0;

	printf("Serverecho:%s\n", buffer);
	close(sockfd);

	return 0;
}

