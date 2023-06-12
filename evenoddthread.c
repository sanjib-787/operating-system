#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
pthread_mutex_t mutex;
pthread_cond_t cond;
static int avail = 0;
sem_t s;
void *even(void * n) {
//	pthread_mutex_lock(&mutex); //mutex
//	avail++;					//condition variable
	sem_wait(&s);
	int *a;
	a = (int*) n;
	printf("even number:\n");
	for(int i = 0; i <= *a; i++){
		if(i % 2 == 0){
			printf("%d ",i);
		}
	}
	printf("\n");
	sem_post(&s);
//	pthread_mutex_unlock(&mutex); 	//mutex
//	pthread_cond_signal(&cond);		//condotion variable
}
void *odd( void * n) {
//	pthread_mutex_lock(&mutex);				//mutex
//	while(avail == 0){						//condotion variable
//		pthread_cond_wait(&cond, &mutex);	//condotion variable
//	}										//condotion variable
//	while(avail > 0){
	sem_wait(&s);
		int *a;
		a = (int*) n;
		printf("odd number:\n");
		for(int i = 0; i <= *a; i++){
			if(i % 2 == 1){
				printf("%d ",i);
			}
		}
		printf("\n");
		avail--;//condotion variable
	sem_post(&s);
//	}
//	pthread_mutex_unlock(&mutex);		//mutex

}
int main(void){
	sem_init(&s, 0, 1);
	pthread_t t1, t2;
	int s,n = 500;
//	printf("enter a range:\n");
//	scanf("%d",&n);	
	s = pthread_create(&t1, NULL, &even, &n);
	if(s != 0){
		printf("error in creating");
	}
//	pthread_exit(&t1);

	s = pthread_create(&t2, NULL, &odd, &n);
	if(s != 0){
		printf("error in creating");
	}
//	s = pthread_join(t1,NULL);

	s = pthread_join(t1,NULL);
	if(s != 0){
		printf("error in joining");
	}

	s = pthread_join(t2,NULL);
	if(s != 0){
		printf("error in joining");
	}

}
