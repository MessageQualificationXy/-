#include<spider.h>
#define result_max 100000
int Save_result(const char* h1,const char* desc,const char* link){
	char result[20000];
	bzero(result,sizeof(result));
	//爬虫未爬取写入文件，html首部信息
	const char* start = "<html>\r\n<head>\r\n<meta http-equiv=\"Content-Type\" content=\"text/html;charset=utf-8\">\r\n</head>\r\n<table boder=\"1\" cellspacing=\"1\" cellpadding=\"1\"  width=\"1900\">\r\n<caption>百度百科词条数据</caption>\r\n<tr><th>编号</th><th>标题</th><th>介绍</th><th>超链接</th></tr>\r\n";
	//爬取完毕，文件写入尾部信息
	const char* end = "</table>\r\n</html>\r\n";
	if(result_number == 0){
		write(result_fd, start, strlen(start));
		return 0;
	}
	if(result_max == result_number){
		write(result_fd,end,strlen(end));
		close(result_fd);
		return 0;
	}
	sprintf(result,"<tr><td>%d</td><td>%s<td><td>%s<td><td><a href=\"%s\">%s</a></td></tr>\r\n",result_number,h1,desc,link,link);
	write(result_fd,result,strlen(result));
	return 0;
}
