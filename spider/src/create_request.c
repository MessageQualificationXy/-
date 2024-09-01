#include<spider.h>
int Create_request(char* request, url_t tmp){
	bzero(request, 4096);
	sprintf(request,"GET %s HTTP/1.1\r\n"\
					"Accept:text/html,application/shtml+xml;q=0.9,image/webp;q=0.8\r\n"\
					"User-Agent:Mozilla/5.0 (X11; Linux x86_32)\r\n"\
					"Host:%s\r\n"\
					"Connection:close\r\n\r\n",tmp.origin,tmp.domain);
	printf("step 4, create request success:\n%s\n",request);
	return 0;
}
