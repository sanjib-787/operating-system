#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(void){
	int res;
	char *str1, *str2;
	res = mkfifo("myfifo",0777);
	if(res == 0){
		printf("success");
	}
	str1 = (char *)malloc(sizeof(char) * 10);
	str2 = (char *)malloc(sizeof(char) * 10);
	while(1){
		res = open("myfifo",O_WRONLY);
		printf("sender: ");
		fgets(str1, 10, stdin);
		write(res, str1, 10);
		if(strcmp("bye\n",str1) == 0){
			break;
		}
		close(res);
	}
}
