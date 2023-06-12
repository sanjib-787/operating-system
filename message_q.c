#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<mqueue.h>
#include<string.h>
#include<semaphore.h>
#define SIZE 100
int shared = 1;
sem_t s;
int main(void)
{
	sem_init(&s, 1, 0);
	mqd_t mqd;
	int len;
	char *cptr, *buffer;
	struct mq_attr attr;
	attr.mq_flags = 0;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 8192;
	attr.mq_curmsgs = 0;
	cptr = (char *)malloc(sizeof(char) * attr.mq_msgsize);
	buffer = (char *)malloc(sizeof(char) * attr.mq_msgsize);
	*(cptr + (strlen(cptr) - 1)) = '\0';
	mqd = mq_open("/mymq",O_CREAT | O_RDWR, 0744, &attr);
	if(mqd == -1) {
		printf("error in open");
	}
/*	if (mq_getattr(mqd, &attr) == -1)
		printf("mq_getattr error\n");
	printf("Maximum # of messages on queue: %ld\n", attr.mq_maxmsg);
	printf("Maximum message size: %ld\n", attr.mq_msgsize);
	printf("# of messages currently on queue: %ld\n", attr.mq_curmsgs);*/
	while(1) {
//		sem_wait(&s);
//		shared++;
		printf("sender:");
		fgets(cptr,SIZE,stdin);
		len = strlen(cptr);
		mq_send(mqd, cptr, strlen(cptr), 0);
//		sem_post(&s);
//		sem_wait(&s);
//		shared--;
		mq_receive(mqd, buffer, attr.mq_msgsize, 0);
		printf("from Receiver: %s",buffer);
//		sem_post(&s);
	}
	mq_unlink("/mymq");
}
