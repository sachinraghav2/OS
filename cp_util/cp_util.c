#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int agrc, char *argv[])
{
	char buff[128];
	int fdr,fdw, char_read, char_wrote;
	fdr=open(argv[1], O_RDONLY, S_IRUSR);
	
	if(fdr==-1)
	{
		perror("Error in read file\n");
		exit(1);
	}
	
	fdw=open(argv[2], O_WRONLY | O_CREAT, S_IWUSR|S_IRUSR);
	if(fdw==-1)
	{
		perror("Error in write file\n");
		exit(1);
	}
	while(1)
	{
		char_read=read(fdr,buff,sizeof(buff));
		if(char_read==0)
		{
			printf("Reached EOF!!!\n");
			break;
		}
		else
		{
			char_wrote=write(fdw, buff, char_read);
			printf("Wrote %d chars.\n",char_wrote);
		}
	}
	close(fdr);
	close(fdw);
	return 0;
}
