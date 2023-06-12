#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#define SIZE 20
int main(void)
{
	int pipefds[2];
	int pipefds1[2];
	int sts, sts1;
	pid_t pid;
	char *wmsg, *rmsg;
	wmsg = (char *)malloc(sizeof(char)*SIZE);
	rmsg = (char *)malloc(sizeof(char)*SIZE);
	sts = pipe(pipefds);
	sts1 = pipe(pipefds1);
	if(sts == -1 && sts1 == -1) {
		printf("files are not created.\n");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if(pid == -1){
		printf("fork not created\n");
		exit(EXIT_FAILURE);
	} else if(pid == 0) {
		close(pipefds[0]);
		close(pipefds1[1]);
		printf("child process\n");
//		printf("enter a message from child\n");
//		fgets(wmsg,SIZE,stdin);
//		write(pipefds[1], wmsg, SIZE);
//		printf("wmsg from pipe:%s",wmsg);
		read(pipefds1[0], rmsg, SIZE);
		printf("rmsg from pipe 1: %s\n",rmsg);
	} else {
		close(pipefds[1]);
		close(pipefds1[0]);
		printf("parent process\n");
		printf("enter a message from parent\n");
		fgets(wmsg,SIZE,stdin);
		write(pipefds1[1], wmsg, SIZE);
		printf("wmsg from pipe1:%s",wmsg);
//		read(pipefds[0], rmsg, SIZE);
//		printf("rmsg from pipe: %s\n",rmsg);
	}
}
