#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#define SIZE 100
int main(void)
{
	int fd, len;
	char *addr, *cptr;
	cptr = (char *)malloc(sizeof(char) * SIZE);
	printf("enter data:\n");
	fgets(cptr, SIZE, stdin);
	fd = shm_open("/shm_demo",O_CREAT | O_RDWR, 0600);
	if(fd == - 1) {
		printf("error in creating shared memory");
	}
	len = strlen(cptr);
	ftruncate(fd, len);
	printf("Resized to %ld bytes\n", (long) len);
	addr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED){
		printf("error in address");
	}
	if (close(fd) == -1){
		printf("close");
	}
	munmap(addr,len);
	printf("copying %ld bytes\n", (long) len);
//	memcpy(addr, cptr, len);
}
