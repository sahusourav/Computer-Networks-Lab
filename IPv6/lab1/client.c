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
	
	struct sockaddr_in6 cli_addr;
	//struct hostent *server;
	len = sizeof(cli_addr);
	char buffer;

	sockfd = socket(AF_INET6, SOCK_STREAM, 0);
	cli_addr.sin6_family = AF_INET6;
	inet_pton(AF_INET6, "::1", &cli_addr.sin6_addr);
	cli_addr.sin6_port = htons(SERV_TCP_PORT);

	printf("Ready for sending...\n");
	connect(sockfd, (struct sockaddr*)&cli_addr, len);
	printf("Enter the letter to send\n");
	printf("Client:\n");
	scanf("%c", &buffer);
	write(sockfd, &buffer, sizeof(buffer));
	read(sockfd, &buffer, sizeof(buffer));

	printf("Next ASCII letter: %c\n", buffer);

	close(sockfd);

	return 0;
}
