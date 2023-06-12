#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define SIZE 20
int main(void)
{
	int pipefds[2];
	int sts;
	pid_t pid, pid2;
	char *wmsg, *rmsg;
	wmsg = (char *)malloc(sizeof(char)*SIZE);
	rmsg = (char *)malloc(sizeof(char)*SIZE);
	printf("enter a message\n");
	fgets(wmsg,SIZE,stdin);
	sts = pipe(pipefds);
	if(sts == -1) {
		printf("files are not created.\n");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if(pid == -1){
		printf("fork not created\n");
		exit(EXIT_FAILURE);
	} else if(pid == 0) {
		printf("child process\n");
		read(pipefds[0], rmsg, SIZE);
		printf("rmsg from child: %s\n",rmsg);
	} else {
		printf("parent process\n");
		write(pipefds[1], wmsg, SIZE);
		printf("wmsg from parent:%s",wmsg);
	}
}
