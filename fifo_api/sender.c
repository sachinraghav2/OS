#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 64

int main()
{
	int fd,result;
	char buff[SIZE];
	result = mkfifo("desd", S_IRUSR|S_IWUSR);
	if( -1 == result)
	{
		perror("Error ");
		exit(1);
	}
	fd = open("desd", O_WRONLY);
	if( -1 == fd)
	{
		perror("Error ");
		exit(1);
	}
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
	
