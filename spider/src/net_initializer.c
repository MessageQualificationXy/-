#include<spider.h>
int Net_initializer(){
	int sockfd;
	if((sockfd = socket(AF_INET, SOCK_STREAM ,0))==-1){
		perror("sock failed");
		exit(0);
	}
	struct sockaddr_in myaddr;
	bzero(&myaddr,sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_port+htons(9090);
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	printf("step 2,net_initializer success\n");
	return sockfd;
}
