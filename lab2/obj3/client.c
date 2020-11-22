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
	int num, arr[2];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	cli_addr.sin_family = AF_INET;
	cli_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	cli_addr.sin_port = htons(SERV_TCP_PORT);

	printf("Ready for sending...\n");
	connect(sockfd, (struct sockaddr*)&cli_addr, len);
	printf("Enter the number to be send>>\n");
	scanf("%d", &num);
	write(sockfd, &num, sizeof(int));
	
	printf("Receiving numbers again from server side...");
	read(sockfd, arr, sizeof(arr));
	printf("Received numbers are:\n2 * %d = %d\t%d * %d = %d\n", num, arr[0], num, num, arr[1]);
	
	printf("Sending sum of received numbers...\n");
	int sum = arr[0] + arr[1];
	write(sockfd, &sum, sizeof(int));

	close(sockfd);

	return 0;
}

