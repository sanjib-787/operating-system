#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main(void)
{
	int res;
	char *str1, *str2;
	str1 = (char *)malloc(sizeof(char) * 10);
	str2 = (char *)malloc(sizeof(char) * 10);
	while(1){
		res = open("myfifo",O_RDONLY);
		read(res, str1, 10);
		printf("%s",str1);
		if(strcmp("bye\n",str1) == 0){
			break;
		}
		close(res);
	}

}
