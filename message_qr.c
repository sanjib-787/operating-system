#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<mqueue.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(void)
{
	mqd_t mqd;
	char *cptr;
	cptr = (char *)malloc(sizeof(char) * 10);
	struct mq_attr attr;
	mqd = mq_open("/mymq", O_RDWR);
	mq_receive(mqd, cptr, attr.mq_msgsize, 0);
	printf("%s", cptr);
}
