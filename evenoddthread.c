#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
pthread_mutex_t mutex;
pthread_cond_t cond;
static int avail = 0;
void *even (void *n)
{
	pthread_mutex_lock ( &mutex );
	avail++;
	int *a ;
	a = (int *) n;
	for(int i = 0; i < *a; i++){
		if(i % 2 == 0){
			printf("%d ",i);
		}	
	}
	printf("\n");
	pthread_cond_signal(&cond);
	pthread_mutex_unlock ( &mutex );
}
void *odd (void *n)
{
	pthread_mutex_lock ( &mutex );
	while(avail == 0){
		pthread_cond_wait(&cond, &mutex);
	}
	while(avail > 0){
	int *a ;
	a = (int *) n;
	for(int i = 0; i < *a; i++){
		if(i % 2 == 1){
			printf("%d ",i);
		}	
	}
	printf("\n");
	avail--;
	}
	pthread_mutex_unlock ( &mutex );
}

int main(void)
{
	pthread_t t1, t2;
	int s, n = 500;
	s = pthread_create(&t1, NULL, &even, &n);
	s = pthread_create(&t2, NULL, &odd, &n);
	s = pthread_join(t1, NULL);
	s = pthread_join(t2, NULL);
	pthread_exit(&t1);
	pthread_exit(&t2);
}
