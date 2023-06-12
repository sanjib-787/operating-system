#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int glob = 0;
pthread_mutex_t mutex;
void *threadfun(void *arg)
{
//	pthread_mutex_lock(&mutex);
	int loc, n;
	n = *(int *) arg;
	for(int i = 0; i < n; i++) {
		loc = glob;
		loc++;
		glob = loc;
	}
	printf("global variable %d\n", glob);
	printf("function: %ld\n", pthread_self());
	return 0;
//	pthread_mutex_unlock(&mutex);
}
int main(void) {
	pthread_t t1, t2;
	int s, arg;
	arg = 10;
	s = pthread_create(&t1, NULL, threadfun, &arg);
	printf("thread1 %ld\n", t1);
	if(s != 0){
		printf("error in create1");
	}
	s = pthread_join(t1, NULL);
	if(s != 0){
		printf("error in join1");
	}
	s = pthread_create(&t2, NULL, threadfun, &arg);
	printf("thread2 %ld\n",t2);
	if(s != 0){
		printf("error in create2");
	}
	
	s = pthread_join(t2, NULL);
	if(s != 0){
		printf("error in join2");
	}
	pthread_exit(&t2);

}
