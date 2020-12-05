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
	char sendline[1024], res;
	struct sockaddr_in servaddr;
	printf("Enter the message>>");
	fgets(sendline, 1024, stdin);
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(5035);
	len = sizeof(servaddr);
	sendto(sockfd, sendline, MAXLINE, 0, (struct sockaddr*)&servaddr, len);
	int flag;
	recvfrom(sockfd, &flag, sizeof(int), 0, NULL, NULL);
	//printf("%s\n", result);
	if(flag)
		printf("Palindrome string\n");
	else
		printf("Not a Palindrome\n");

	return 0;
}
