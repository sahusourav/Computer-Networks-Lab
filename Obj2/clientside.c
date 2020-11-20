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
	int sockfd, len, n, k;
	
	struct sockaddr_in cli_addr;
	//struct hostent *server;
	len = sizeof(cli_addr);
	char buffer[200];
	while(1)
	{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	cli_addr.sin_family = AF_INET;
	cli_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	cli_addr.sin_port = htons(SERV_TCP_PORT);

	printf("Ready for sending...\n");
	connect(sockfd, (struct sockaddr*)&cli_addr, len);
	printf("Enter a message for server:\n");
	fgets(buffer, 200, stdin);
	write(sockfd, buffer, sizeof(buffer));
	n = read(sockfd, buffer, sizeof(buffer));
	buffer[n] = 0;
	printf("Message from server side:%s\n", buffer);
	if(!strncmp(buffer, "Bye", 3))
		break;
	}
	
	close(sockfd);

	return 0;
}

