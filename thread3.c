#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
int glob = 5;
void * fun1(void *arg)
{
	int num;
	num = *(int *) arg;
	num++;
	printf("local fun1: %d\n",num);
	while(glob<100){
		glob++;
		printf("fun1: %d\t id: %ld\n",glob, pthread_self());
		if(glob == 50){
			//exit(EXIT_SUCCESS);
			break;
		}
	}
}
/*void * fun2(void *arg)
{
	int num;
	num = *(int *) arg;
	num += 5;
	printf("local fun2: %d\n",num);
	while(glob){
		sleep(3);
		glob++;
		printf("fun2: %d\n",glob);
		if(glob == 50){
			break;
		}
	}

}
void * fun3(void *arg)
{
	int num;
	num = *(int *) arg;
	num += 10;
	printf("local fun3: %d\n",num);
	while(glob){
		sleep(3);
		glob++;
		printf("fun3: %d\n",glob);
		if(glob == 50){
			break;
		}
	}
}*/
int main(void)
{
	pthread_t t1, t2, t3;
	int s, arg, num;
	arg = 100;
		sleep(3);
	s = pthread_create(&t1, NULL, fun1, &arg);
	s = pthread_create(&t2, NULL, fun1, &arg);
	s = pthread_create(&t3, NULL, fun1, &arg);
	s = pthread_join(t1, NULL);
	s = pthread_join(t2, NULL);
	s = pthread_join(t3, NULL);
	sleep ( 3 );
	printf("t1 = %ld\n", t1 );
	printf("t2 = %ld\n", t2 );
	printf("t3 = %ld\n", t3 );
}
