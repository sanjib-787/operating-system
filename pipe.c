#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int pipefd[2];
	int status;
	char msg[2][10]={"hello","sanjib"};
	char readmsg[10];
	status = pipe(pipefd);
	if(status == -1) {
		printf("pipe not created \n");
		exit(EXIT_FAILURE);
	}
	printf("%s\n",msg[0]);
	printf("%d\n",sizeof(msg[0]));
	write(pipefd[1], msg[0], sizeof(msg[0]));
	read(pipefd[0], readmsg, sizeof(readmsg));
	printf("%s\n",readmsg);
}
