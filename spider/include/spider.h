#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<regex.h>
#include<sys/mman.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<openssl/ssl.h>
#include<openssl/err.h>
#define result_max 100000
int analytical_shutdown;//解析开关，1解析，0关闭
int result_fd;//html存储文件的描述符
int result_number;//当前爬取数量

typedef struct{
	SSL* sslsock;//ssl套接字
	SSL_CTX* sslctx;//ssl上下文
}ssl_t;

typedef struct{
	char origin[8192];
	char domain[1024];
	char path[1024];
	char file[1024];
	int type;
	int port;
	char ip[16];
}url_t;

typedef struct{
	url_t* list;
	int front;
	int rear;
	int cur;
	int max;
}queue_t;
int Analytical_url(url_t* tmp);//url解析模块
int Net_initializer();//网络初始化
int Connection(int sockfd, url_t tmp);//完成tcp链接
int Create_request(char*, url_t);
int Get_status_code(char*);
int Download(int sockfd, const char* request, url_t tmp, ssl_t* ssl);

ssl_t* Create_ssl(int sockfd);//生成安全套接字，并完成安全握手
int Save_result(const char* h1, const char* desc, const char* link);//存储
int Analytical_html(queue_t* e, queue_t* p, url_t tmp);//html解析
int Remove_duplication(queue_t* e, queue_t* p, const char* newlink);//去重验证，返回1表示无重复
int Set_node(queue_t*, url_t node);//入队
int Get_node(queue_t*, url_t* node);//出队
queue_t* Create_queue(int qmax);//创建初始化队列








