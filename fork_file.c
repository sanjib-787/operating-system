#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#define SIZE 200
int main(void)
{
	FILE *fp;
	char ch, buf[SIZE], str[SIZE], str1[SIZE];
	pid_t pid;
	char *argv[]={"./pid",NULL};
	pid = fork();
	fp = fopen("abc.txt","w");
	if(pid == 0) {
		printf("child content\n");
//		execv(*argv, argv);
		scanf("%s",str);
		fprintf(fp, "%s", str);
		fread(buf, SIZE, 1, fp);
		printf("%s", buf);
		fclose(fp);
	}
	else if (pid > 0){
		//wait(NULL);
		printf("parent content\n");
		fgets(str1,SIZE,stdin);
		*(str1 +(sizeof(str1)-1)) = '\0';
		fprintf(fp, "%s", str1);
		fread(buf, SIZE, 1, fp);
		printf("%s",buf);
		fclose (fp);
	} else {
		printf("child is not created.\n");
	}
}
