#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<stdio.h>
void *fun1 ( void *ptr );
void *fun2 ( void *ptr);
int shared = 1;
sem_t s;
int main ( void *ptr )
{
	sem_init ( &s, 0, 1 );
	pthread_t tid [ 2 ];
	if ( pthread_create ( &tid [ 0 ], NULL, &fun1, NULL ) != 0 ) {
		printf("Failed in creating thread 1\n");
	}
	if ( pthread_create ( &tid [ 1 ], NULL, &fun2, NULL ) != 0 ) {
		printf("Failed in creating thread 1\n");
	}
	pthread_join ( tid [ 0 ], NULL );
	pthread_join ( tid [ 1 ], NULL );
	return 0;
}

void *fun1 ( void *ptr )
{
	int x;
	sem_wait ( &s );
	x = shared;
	printf("Thread 1 saw shared as %d\n", x );
	x++;
	shared = x;
	printf("Thread 1 modified shared as %d\n", x );
	sleep (1);
	sem_post( &s );
}

void *fun2 ( void *ptr )
{
	int x;
	sem_wait ( &s );
	x = shared;
	printf("Thread 2 saw shared as %d\n", x );
	x--;
	shared = x;
	printf("Thread 2 modified shared as %d\n", x );
	sleep (1);
	sem_post( &s );
}
	
		
