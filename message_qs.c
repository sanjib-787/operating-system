#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<mqueue.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(void)
{
	mqd_t mqd;
	char *cptr = "hello";
	struct mq_attr attr;
	attr.mq_flags = 0;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 8192;
	attr.mq_curmsgs = 0;
	mqd = mq_open("/mymq", O_CREAT | O_RDWR, 0744, &attr);
	if(mqd == -1){
		printf("error");
	}
	mq_send(mqd, cptr, strlen(cptr), 0);
	mq_unlink("/mymq");
	return 0;
}
