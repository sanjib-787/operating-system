#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(void)
{
	pid_t pid;
	pid = fork();
	if(pid == 0){
		//wait(NULL);
		printf("child content\n");
		printf("child pid %d\n",getpid());
		printf("child ppid%d\n",getppid());
	} else if ( pid > 0 ){
		wait(NULL);
		printf("parent\n");
		printf("parent pid %d\n",getpid());
		//printf("parent %d\n",getppid());
		//exit(EXIT_SUCCESS);
	}
}
