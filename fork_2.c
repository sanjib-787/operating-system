#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int global_var1 = 10;
int global_var2 = 20;
int main(void)
{
	int result;
	pid_t pid;
	pid = fork();
	if(pid == 0){
		result = global_var1 + global_var2;
		global_var1 = 40;
		printf("child\n");
		printf("%d\n",global_var1);
		exit(0);
	} else {
		getchar();
		//sleep(100);
		printf("parent\n");
		printf("%d\n",global_var1);
		wait(NULL);
	}
}
//how to avoid zombies
