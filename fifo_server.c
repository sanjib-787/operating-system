#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#define SIZE 100
int main(void)
{
	int res, i, j;
	char *cptr;
	char *cptr1;
	char *name;
	char *cli_name;
	cptr = (char *)malloc(sizeof(cptr) * SIZE);
	cptr1 = (char *)malloc(sizeof(cptr) * SIZE);
	name = (char *)malloc(sizeof(cptr) * SIZE);
	cli_name = (char *)malloc(sizeof(cptr) * SIZE);
	printf("enter sender name:\n");
	fgets(name,SIZE,stdin);
	*(name + (strlen(name) - 1))='\0';
	while(1){
		res = open("fifo1",O_WRONLY);
		printf("%s: ",name);
		fgets(cptr, SIZE, stdin);
		*(cptr + (strlen(cptr) - 1))='\0';
		write(res, cptr, SIZE);
		write(res, name, SIZE);
		i = strcmp("bye",cptr);
		if(i == 0){
			break;
		//	exit(EXIT_SUCCESS);
		}
		close(res);
		res = open("fifo1", O_RDONLY);
		read(res, cptr1, SIZE);
		read(res, cli_name, SIZE);
		printf("from %s: %s\n", cli_name, cptr1);
		j = strcmp("bye", cptr1);
//		if(j == 0){
//			break;
		//	exit(EXIT_SUCCESS);
//		}
		close(res);
	}
	return 0;
}
