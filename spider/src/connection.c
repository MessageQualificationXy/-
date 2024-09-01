#include<spider.h>
int Connection(int sockfd, url_t tmp){
	struct sockaddr_in server_addr;
	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(tmp.port);
	inet_pton(AF_INET, tmp.ip,&server_addr.sin_addr.s_addr);
	if((connect(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr)))==-1){
		perror("connection failed");
		exit(0);
	}
	printf("step 3, connection web [%s] success\n",tmp.ip);
}
