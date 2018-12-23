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
	fd = open("sac", O_WRONLY);
	printf("Enter string: ");
	scanf("%s",buff);
	if( fd<0)
		perror("Error ");
	else
	{
		write(fd, buff, SIZE);
		printf("Sender sent: %s\n",buff);
	}
	close(fd);
	return 0;
}
