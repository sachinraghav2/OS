#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define SIZE 64

int main()
{
	int fd;
	char buff[SIZE];
	
	fd = open("sac", O_RDONLY);
	if( fd<0)
		perror("Error ");
	else
		read(fd, buff, SIZE);
	printf("Receiver received: %s",buff);
	close(fd);
	return 0;
}
