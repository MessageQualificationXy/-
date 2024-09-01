#include<spider.h>
int Analytical_url(url_t* tmp){
	int start;
	bzero(tmp->domain,1024);
	bzero(tmp->path,1024);
	bzero(tmp->file,1024);
	bzero(tmp->ip,16);
	char* htp[] = {"http://","https://",NULL};
	if(strncmp(tmp->origin,htp[0],strlen(htp[0]))==0){
		tmp->type = 0;
		tmp->port = 80;
		start = strlen(htp[0]);
	}else{
		tmp->type = 1;
		tmp->port = 443;
		start = strlen(htp[1]);
	}
	char* regstr = "\\([^/]\\+\\?\\)\\(/.*/\\)\\(.*\\)";
	int rnum = 4;
	regex_t reg;
	regmatch_t match[4];
	regcomp(&reg, regstr, 0);
	//匹配
	if((regexec(&reg,tmp->origin+start,rnum,match,0))==0){
		snprintf(tmp->domain,match[1].rm_eo-match[1].rm_so+1,"%s",tmp->origin+start+match[1].rm_so);
		snprintf(tmp->path,match[2].rm_eo-match[2].rm_so+1,"%s",tmp->origin+start+match[2].rm_so);
		snprintf(tmp->file,match[3].rm_eo-match[3].rm_so+1,"%s",tmp->origin+start+match[3].rm_so);
	}
	//获取
	struct hostent* ent = NULL;
	if((ent = gethostbyname(tmp->domain))==NULL){
		printf("get host by name failed\n");
		exit(0);
	}
	inet_ntop(AF_INET,ent->h_addr_list[0],tmp->ip,16);//将地址表中的第一个ip转为字符串存储
	printf("step 1, analytical success: origin=%s\ndomain=%s\npath=%s\nfile=%s\nip=%s\ntype=%d\nport=%d\n",tmp->origin,tmp->domain,tmp->path,tmp->file,tmp->ip,tmp->type,tmp->port);
	return 0;
}














