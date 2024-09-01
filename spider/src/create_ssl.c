#include<spider.h>
ssl_t* Create_ssl(int sock){
	ssl_t* ssl  = (ssl_t*)malloc(sizeof(ssl_t));
	SSL_load_error_strings();//加载ssl库中的错误处理方法
	SSL_library_init();//加载初始化库
	OpenSSL_add_ssl_algorithms();//加载加密算法，哈希函数
	ssl->sslctx = SSL_CTX_new(SSLv23_method());//创建ssl上下文信息，包含版本兼容性
	ssl->sslsock = SSL_new(ssl->sslctx);//创建安全套接字，参数为上下文
	SSL_set_fd(ssl->sslsock,sock);
	SSL_connect(ssl->sslsock);//发起认证
	printf("create openssl success, ssl = %p\n",ssl);
	return ssl;
}
	
