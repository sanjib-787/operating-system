#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	int istack = 222;
	pid_t childpid;
	childpid = vfork();
	if(childpid == -1) {
		printf("fork not created\n");
	} else if (childpid == 0) {
		sleep(3);
		printf("child pid %d\n",getpid());
		write(STDOUT_FILENO,"child executing\n", 16);
		istack *= 3;
		_exit(EXIT_SUCCESS);
	} else {
		printf("parent pid %d\n",getpid());
		write(STDOUT_FILENO, "Parent executing\n", 17);
		printf("istack=%d\n", istack);
		exit(EXIT_SUCCESS);
	}
}
