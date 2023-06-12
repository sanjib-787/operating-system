#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(void)
{
	int res;
	res = mkfifo("fifo1",0777);
	printf("named pipe created\n");
	return 0;
}
