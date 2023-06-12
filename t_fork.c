#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
static int idata = 111;
int main(int argc, char *argv[])
{
	int istack = 222;
	pid_t childpid;
	childpid = fork();
	if(childpid == -1) {
		printf("fork not created\n");
	} else if (childpid == 0) {
		idata *= 3;
		istack *= 3;
		printf("child pid %d\n",getpid());
	} else {
		sleep(5);
		printf("parent pid %d\n",getpid());
	}
	printf("PID = %d %s idata = %d istack = %d \n",getpid(), (childpid == 0) ? "(child)" : "(parent)" , idata, istack);
	exit(EXIT_SUCCESS);
}
