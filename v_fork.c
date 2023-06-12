#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(void)
{
	char *argc[] = {"./threads",NULL};
	pid_t pid;
	pid = vfork();
	printf("hello\n");
	if(pid == -1){
		printf("error");
		exit(1);
	} else if(pid == 0) {
		wait(NULL);
		printf("hello from child\n");
		execv(argc[0], argc);
		exit(EXIT_SUCCESS);
	} else{
		printf("hello from parent\n");
	}
}
