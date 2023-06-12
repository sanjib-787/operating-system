#include<stdio.h>
#include<unistd.h>
int main(void){
	pid_t pid;
	char *ar[]={"./hello",NULL};
	pid = vfork();
	if(pid == 0){
		printf("child process pid is:%d\n",getpid());
		execv(*ar, ar);
	} else{
		printf("parent process pid is:%d\n",getpid());
	}
}
