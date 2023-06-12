#include<stdio.h>
#include<unistd.h>
int main(void)
{
	pid_t pid1, pid2, pid3;
	int pp1,pp2;
	pid1 = fork();
	if(pid1 == 0){
		printf("1st child pid %d ppid %d\n",getpid(),getppid());
	} else {
		printf("grand parent pid %d ppid %d\n",getpid(),getppid());
		pid2 = fork();
		if(pid2 == 0){
			printf("2nd child pid %d ppid %d\n",getpid(),getppid());
		} else {
			printf("1st parent pid %d ppid %d\n",getpid(),getppid());
			pid3 = fork();
			if(pid3 == 0){
				printf("3rd child pid %d ppid %d\n",getpid(),getppid());
			} else {
				printf("2nd parent pid %d ppid %d\n",getpid(),getppid());
			}
		}
	}
}
