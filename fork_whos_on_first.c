#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>
#define GN_GT_0		01
int main(int argc, char *argv[])
{
	int numchildren, j;
	pid_t childpid;
	if (argc > 1 && strcmp(argv[1], "--help") == 0)
		usageErr("%s [num-children]\n", argv[0]);
	numchildren = (argc > 1) ? getenv(argv[1], GN_GT_0, "num-children") : 1;
	setbuf(stdout, NULL);
	for (j = 0; j < numchildren; j++) {
		switch (childpid = fork()) {
			case -1:
				exit(EXIT_SUCCESS);
			case 0:
				printf("%d child\n", j);
				_exit(EXIT_SUCCESS);
			default:
				printf("%d parent\n", j);
				wait(NULL); /* Wait for child to terminate */
			break;
		}
	}
	exit(EXIT_SUCCESS);

}
