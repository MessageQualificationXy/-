#include<spider.h>
queue_t* Create_queue(int qmax){
	queue_t* q = NULL;
	if((q =(queue_t*)malloc(sizeof(queue_t)))==NULL){
		perror("create queue, malloc queue_t failed.");
		exit(0);
	}
	if((q->list = (url_t*)malloc(sizeof(url_t)*qmax))==NULL){
		perror("create queue, malloc list failed");
		exit(0);
	}
	q->front = 0;
	q->rear = 0;
	q->cur = 0;
	q->max = qmax;
	return q;
}
//入队
int Set_node(queue_t* q, url_t node){
	if(q->cur==q->max)
		return -1;
	q->list[q->front] = node;
	++(q->cur);
	q->front = (q->front +1)%q->max;
	return 0;
}
//出队
int Get_node(queue_t* q, url_t* node){
	if(q->cur == 0)
		return -1;
	*node = q->list[q->rear];
	--(q->cur);
	q->rear = (q->rear +1)%q->max;
	return 0;
}

