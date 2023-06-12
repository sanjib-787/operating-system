#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#define SIZE 100
int main(void)
{
	int res1, i, j;
	char *cptr;
	char *cptr1;
	char *name;
	char *cli_name;
	cptr = (char *) malloc(sizeof(cptr) * SIZE);
	cptr1 = (char *) malloc(sizeof(cptr) * SIZE);
	name = (char *) malloc(sizeof(cptr) * SIZE);
	cli_name = (char *) malloc(sizeof(cptr) * SIZE);
	printf("enter client name:\n");
	fgets(cli_name, SIZE, stdin);
	*(cli_name + (strlen(cli_name) -1 )) = '\0';
	while(1) {
		res1 = open("fifo1", O_RDONLY);
		read(res1, cptr, SIZE);
		read(res1, name, SIZE);
		printf("from %s: %s\n",name, cptr);
		i = strcmp("bye", cptr);
		if(i == 0){
//			exit(EXIT_SUCCESS);
			break;
		}
		close(res1);
		res1 = open("fifo1",O_WRONLY);
		printf("%s: ", cli_name);
		fgets(cptr1,SIZE,stdin);
		*(cptr1+(strlen(cptr1)-1))='\0';
		write(res1, cptr1, SIZE);
		write(res1, cli_name, SIZE);
		j = strcmp("bye", cptr1);
		if(j == 0){
//			exit(EXIT_SUCCESS);
			break;
		}
		close(res1);
	}
	return 0;

}
