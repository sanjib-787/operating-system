#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void){
	pid_t pid;
	int status;
	int pipefds[2];
	char *wmsg, *rmsg;
	wmsg = (char *)malloc(sizeof(wmsg) * 10);
	rmsg = (char *)malloc(sizeof(wmsg) * 10);
	status = pipe(pipefds);
	pid = fork();
	if(pid == -1) {
		printf("fork not created\n");
		exit(EXIT_FAILURE);
	} else if( pid == 0 ) {
		printf("enter data from child:\n");
		fgets(wmsg, 10, stdin);
		write(pipefds[1], wmsg, 10);
		close( pipefds [ 1 ]);
	} else {
		read(pipefds[0], rmsg, 10);
		printf("read in parent %s",rmsg);
	}

}
