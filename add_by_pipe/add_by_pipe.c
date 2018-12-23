#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#define SIZE 128
void extractnum(int *nptr, char buff[])
{	
	for(int i=0; i<SIZE ; i++)
	{
		*nptr += (buff[i]-'0');
		if((buff[i+1]=='\n') || (buff[i+1]=='\0'))
			break;
		*nptr *= 10;
	}
}

void sum(int a, int b)
{
	printf("Sum = %d\n",a+b);
}

int main()
{
	int fd[2];
	char buff[SIZE];
	pid_t id;
	pipe(fd);
	id=fork();
	if(0 == id)
	{
		int a=0,b=0;
		close(fd[1]);
		printf("child op, received :\n");
		read(fd[0], buff, 4);
		extractnum(&a,buff);
		printf("a : %d\n",a);
		read(fd[0], buff,4);
		
		//printf("%s\n", buff);
		extractnum( &b,buff);
		printf("b : %d\n",b);
		sum(a,b);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		printf("Parent op! Sending data.\n");
		write(fd[1], "117\n", 4);
		write(fd[1], "228\n", 4);
		close(fd[1]);
	}
	return 0;
}
