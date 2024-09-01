#include<spider.h>
int Download(int sockfd, const char* request, url_t tmp, ssl_t* ssl){
	char buffer[8192];
	char response[4096];
	int len;
	int code;
	int fd;
	bzero(buffer,sizeof(buffer));
	bzero(response,sizeof(response));
	if(!ssl){//http
		//发送请求
		if((send(sockfd,request,strlen(request),MSG_NOSIGNAL))==-1){
			perror("send request failed");
			exit(0);
		}else{
			printf("step 5,send request success\n");
		}
		int size = 8192;
		int offset = 0;
		len = recv(sockfd,buffer,sizeof(buffer),0);
		char* pos = NULL;
		if((pos = strstr(buffer,"\r\n\r\n"))==NULL){
			printf("strstr find line failed\n");
			exit(0);
		}
		snprintf(response,pos-buffer+4,"%s",buffer);
		printf("step 6, get response success:\n%s\n",response);
		code = Get_status_code(response);
		if(code == 200){
			fd = open(tmp.file,O_RDWR|O_CREAT,0664);
			write(fd,pos+4,len-(pos-buffer+4));
			bzero(buffer,sizeof(buffer));
			while((len = recv(sockfd,buffer,sizeof(buffer),0))>0){
				write(fd,buffer,len);
			}
			close(fd);
			close(sockfd);
			printf("step 7, download success, repsonse code %d\n",code);
			return 0;
		}else{
			printf("step 7, download failed, respone code %d\n",code);
			close(sockfd);
			return -1;
		}
	}else{//https
		//发送请求
		if((SSL_write(ssl->sslsock,request,strlen(request)))==-1){
			perror("send request failed");
			exit(0);
		}else{
			printf("step 5,send request success\n");
		}
		int size = 8192;
		int offset = 0;
		len = SSL_read(ssl->sslsock,buffer,sizeof(buffer));
		char* pos = NULL;
		if((pos = strstr(buffer,"\r\n\r\n"))==NULL){
			printf("strstr find line failed\n");
			exit(0);
		}
		snprintf(response,pos-buffer+4,"%s",buffer);
		printf("step 6, get response success:\n%s\n",response);
		code = Get_status_code(response);
		if(code == 200){
			fd = open(tmp.file,O_RDWR|O_CREAT,0664);
			write(fd,pos+4,len-(pos-buffer+4));
			bzero(buffer,sizeof(buffer));
			while((len = SSL_read(ssl->sslsock,buffer,sizeof(buffer)))>0){
				write(fd,buffer,len);
			}
			close(fd);
			close(sockfd);
			free(ssl);
			ssl = NULL;
			printf("step 7, download success, repsonse code %d\n",code);
			return 0;
		}else{
			printf("step 7, download failed, respone code %d\n",code);
			close(sockfd);
			free(ssl);
			ssl=NULL;
			return -1;
		}
	}
}














