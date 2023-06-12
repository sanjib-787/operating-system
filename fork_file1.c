#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(void)
{
	FILE *fp;
	fp = fopen("file1.txt","a");
	char ch1, ch2;
	pid_t pid;
	pid = fork();
//	fp1 = fopen("file1.txt","a");
	if(pid == 0){
		printf("child content\n");
		ch1 = getchar();
		fprintf(fp,"ch %c\n",ch1);
		fclose(fp);
	} else if(pid > 0) {
		wait(NULL);
		printf("parent content\n");
		ch2 = getchar();
		fprintf(fp,"p %c\n",ch2);
		fclose(fp);
	} else {
		printf("child not created\n");
	}
}
