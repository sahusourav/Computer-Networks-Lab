// to implement an echo client - server using UDP
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdio.h>
#define MAXLINE 1024

int main()
{
	int sockfd, n;
	socklen_t len;
	char msg[1024];
	struct sockaddr_in servaddr, cliaddr;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(5035);
	
	bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	printf("\n\nBinded");
	printf("\n\nListening...\n");

	len = sizeof(cliaddr);
	recvfrom(sockfd, msg, MAXLINE, 0, (struct sockaddr*)&cliaddr, &len);
	printf("\nClient's message: %s\n", msg);
	sendto(sockfd, msg, MAXLINE, 0, (struct sockaddr*)&cliaddr, len);

	return 0;
}
