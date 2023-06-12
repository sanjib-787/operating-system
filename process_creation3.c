#include<stdio.h>
#include<unistd.h>
int glob = 5;
int fun1(){
	while(glob){
		sleep(3);
		glob++;
		printf("fun1: %d\n",glob);
		printf("fun1_local: %d\n",local);
		if(glob == 10){
			break;
		}
	}	
}
int fun2(){
	while(glob){
		sleep(3);
		glob++;
		printf("fun2: %d\n",glob);
		printf("fun2_local: %d\n",local);
		if(glob == 10){
			break;
		}
	}	
}
int fun3(){
	while(glob){
		sleep(3);
		glob++;
		printf("fun3: %d\n",glob);
		printf("fun3_local: %d\n",local);
		if(glob == 10){
			break;
		}
	}	
}
int main(void)
{
	pid_t pid1, pid2, pid3;
	pid1 = fork();
	int local = 100;
	if(pid1 == 0) {
		printf("child:\n");
		fun1();
	}else{
		printf("parent1:\n");
		pid2 = fork();
		if(pid2 == 0){
			printf("child2:\n");
			fun2();
		} else {
			printf("parent2:\n");
			fun3();
		}
	}
}
