#include<spider.h>
int Analytical_html(queue_t* e,queue_t* p,url_t tmp){
	int fd;
	char* ptr = NULL;
	char* cp_ptr = NULL;
	int fsize;//文件大小
	url_t node;
	fd = open(tmp.file,O_RDONLY);
	fsize = lseek(fd,0,SEEK_END);
	//映射网页源码数据
	if((ptr = mmap(NULL,fsize,PROT_READ,MAP_PRIVATE,fd,0))==MAP_FAILED){
		perror("mmap failed");
		exit(0);
	}
	close(fd);
	cp_ptr = ptr;
	//正则匹配
	regex_t hreg,dreg,ureg;
	char* hstr = "<h1[^>]\\+\\?>\\([^<]\\+\\?\\)</h1>";
	char* dstr = "<meta name=\"description\" content=\"\\([^\"]\\+\\?\\)\">";
	char* ustr = "<a[^>]\\+\\?href=\"\\(/item/[^\"]\\+\\?\\)\"[^>]\\+\\?>[^<]\\+\\?</a>";
	regcomp(&hreg,hstr,0);
	regcomp(&dreg,dstr,0);
	regcomp(&ureg,ustr,0);
	regmatch_t hmatch[2];
	regmatch_t dmatch[2];
	regmatch_t umatch[2];
	char h1[1024];char desc[8192];char link[8192];
	bzero(h1,sizeof(h1));
	bzero(desc,sizeof(desc));
	bzero(link,sizeof(link));
	
	//匹配标题与描述
	if((regexec(&hreg,ptr,2,umatch,0))==0)
		snprintf(h1,hmatch[1].rm_eo-hmatch[1].rm_so+1,"%s",ptr+hmatch[1].rm_so);
	if((regexec(&dreg,ptr,2,dmatch,0))==0)
		snprintf(desc,dmatch[1].rm_eo-dmatch[1].rm_so+1,"%s",ptr+dmatch[1].rm_so);
	//持久化
	++result_number;
	Save_result(h1,desc,tmp.origin);
	//解析新链接(shutdown ?)
	if(analytical_shutdown){
		while((regexec(&ureg,ptr,2,umatch,0))==0){
			snprintf(link,umatch[1].rm_eo-umatch[1].rm_so+24,"https://baike.baidu.com%s",ptr+umatch[1].rm_so);
			if(Remove_duplication(e,p,link)){
				strcpy(node.origin,link);
				Set_node(e,node);
			}
			bzero(link,sizeof(link));
			ptr+=umatch[0].rm_eo;
			if(e->cur+1 == e->max){
				printf("e_queue, its full, breaking\n");
				break;
			}
		}
	}
	unlink(tmp.file);

}




