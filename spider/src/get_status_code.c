#include<spider.h>
int Get_status_code(char* response){
	//HTTP/1.1 404 Not\r\n
	char* regstr = "HTTP/1.1 \\([^\r\n]\\+\\?\\)\r\n";
	regex_t reg;
	regmatch_t match[2];
	regcomp(&reg, regstr,0);
	char str_status[100];
	int status;
	if((regexec(&reg,response,2,match,0))==0){
		snprintf(str_status,match[1].rm_eo-match[1].rm_so+1,"%s",response+match[1].rm_so);
		sscanf(str_status,"%d ",&status);
		return status;
	}else{
		regfree(&reg);
		return -1;
	}
}
