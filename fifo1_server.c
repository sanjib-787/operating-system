#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(void)
{
	int res,fd;
	res = mkfifo("fifo2",0777);
	printf("named fifo created\n");
	fd = open("fifo1",O_RDWR);
	printf("sender: ");
	fgets(cptr, SIZE, stdin);
	write(res, cptr, SIZE);
	close(fd)
	return 0;
}
