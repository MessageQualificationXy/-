#include<spider.h>
int Remove_duplication(queue_t* e, queue_t* p, const char* link){
	//环形队列，环形遍历，采用尾部追头部
	int flag;
	flag = e->rear;
	while(flag%e->max != e->front){
		if(strncmp(e->list[flag].origin,link,strlen(link))==0)
			return 0;
		flag++;
	}
	flag = p->rear;
	while(flag%p->max != p->front){
		if(strncmp(p->list[flag].origin,link,strlen(link))==0)
			return 0;
		flag++;
	}
	return 1;
}
