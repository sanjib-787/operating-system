#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<mqueue.h>
#include<string.h>
#include<semaphore.h>
int shared = 1;
sem_t s;
int main(void)
{
	sem_init(&s, 1, 0);
	mqd_t mqd;
	char *buffer;
	char *cptr;
	struct mq_attr attr;
	ssize_t numRead;
	buffer = (char *)malloc(sizeof(char) * 100);
	cptr = (char *)malloc(sizeof(char) * 100);
	mqd = mq_open("/mymq", O_RDWR);
	if (numRead == -1){
		printf("mq_receive error");
	}
	while(1){
//		sem_wait(&s);
//		shared++;
		numRead = mq_receive(mqd, buffer, attr.mq_msgsize, 0);
		if (numRead == -1) {
			printf("message not receiving");
		}
		printf("from sender: %s\n",buffer);
//		sem_post(&s);
//		sem_wait(&s);
//		shared--;
		printf("Receiver:");
		fgets(cptr,100,stdin);
		mq_send(mqd, cptr, strlen(cptr), 0);
//		sem_post(&s);
	}
}
