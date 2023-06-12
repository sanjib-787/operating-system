#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int gvar = 10;
int main(void)
{
	int lvar = 20;
	int var;
	FILE *fp;
	printf("enter data:\n");
	scanf("%d",&var);
	pid_t pid;
	fp = fopen("experiment.txt","w");
	pid = fork();
	if(pid < 0) {
		printf("fork not created\n");
		exit(EXIT_FAILURE);
	} else if(pid == 0) {
		gvar = 100;
		lvar = 200;
		var = 300;
		fputs("organization",fp);
		printf("child gvar %d\n",gvar);
		printf("child lvar %d\n",lvar);
		printf("child var %d\n",var);
	} else {
		wait(NULL);
		fputs("capgemini",fp);
		printf("parent gvar %d\n",gvar);
		printf("parent lvar %d\n",lvar);
		printf("parent var %d\n",var);
	}

}
