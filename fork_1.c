#include<stdio.h>
#include<unistd.h>
int main(void)
{
	fork();
	printf("hello\n");
	return 0;
}
