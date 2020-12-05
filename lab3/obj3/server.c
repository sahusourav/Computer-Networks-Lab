//implemnt udp c-se program to check if the given string is a palindrome or not
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
	int flag = 1;
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
	// Reversing string
	int slen = strlen(msg) - 1;
	for(int i = 0, j = slen - 1; i < j; i++, j--)
	{
		if(msg[i] != msg[j])
		{
			flag = 0;
			break;
		}
	}
	sendto(sockfd, &flag, sizeof(int), 0, (struct sockaddr*)&cliaddr, len);

	return 0;
}
