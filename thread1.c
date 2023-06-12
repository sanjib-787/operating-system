#include<stdio.h>
#include<pthread.h>
void* threadfun(void *args)
{
//	while(1){
		printf("hello sanjib I am thread\n");
//	}
}
int main(void)
{
	pthread_t ptid;
	pthread_t ptid1;
	int ret, ret1;

	ret = pthread_create(&ptid, NULL, &threadfun, NULL);
	ret1 = pthread_create(&ptid1, NULL, &threadfun, NULL);
	if(ret==0){
		printf("Thread created successfully.\n");
	} else {
		printf("Thread not created.\n");
		return 0; /*return from main*/
	}
/*	while(1)
	{
		printf("I am main function.\n");
	}*/
    return 0;
}
