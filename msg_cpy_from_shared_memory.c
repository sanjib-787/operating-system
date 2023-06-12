#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stddef.h>
int main(void)
{
	int fd;
	char *addr;
	struct stat sb;
	fd = shm_open("/shm_demo", O_RDONLY, 0);
	if(fd == -1) {
		printf("error in opening\n");
	}
	if (fstat(fd, &sb) == -1) {
		printf("error infstat\n");
	}
	addr = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED) {
		printf("error in addr\n");
	}
	if (close(fd) == -1){
		printf("error in closing\n");
	}
	printf("%s\n",addr);
	printf("\n");
}
