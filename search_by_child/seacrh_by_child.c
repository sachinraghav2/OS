#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#define SIZE 20
int found,count;

int main()
{
	int wstatus;
	char buff[SIZE], string[SIZE],c[1];
	pid_t id;
	printf("Enter string: ");
	scanf("%s",string);
	
	id = fork();
	if(0 == id)
	{
		/*int fd, j=0;
		fd = open("words", O_RDONLY);
		if(fd<0)
			perror("Error ");
		while(1)
		{
			read(fd, c, 1);
			if( c[0] == '\n')
			{
				count++;
				buff[j]='\0';
				printf("%s\n", buff);
				if(strcmp(string,buff) == 0)
				{
					printf("Found at %d\n", count);
					j=0;
					exit(1);
				}
				j=0;
			}
			else
				buff[j++]=c[0];
		}*/	
		
	}
	else
	{
		int j=0;
		pid_t id;
		off_t a,pos;
		id=fork();
		if( 0 == id)
		{
			printf("in child 2\n");
			int fd;
			fd = open("words", O_RDONLY);
			if(fd<0)
				perror("Error ");
			else
			{
				a=lseek(fd, 0, SEEK_END);
				printf("%ld\n",a);
				for(int i=0; i<20 ; i++)
				{
					read(fd, c, 1);
					printf("%c\n",c[0]);
					if( c[0] == '\n')
					{
						read(fd,c,1);
						while((c[0]!='\n') && (c[0] !=EOF))
						{
							buff[j++]=c[0];
							read(fd,c,1);
							pos++;
						}
						buff[j]='\0';
						printf("\n%s\n",buff);
						if(strcmp(buff,string)==0)
						{
							printf("Found at %d\n", count);
							j=0;
							exit(1);
							
						}
						a=lseek(fd, -pos, SEEK_CUR);
						printf("fd in strcmp at %ld\n",a);
						j=0;
					}
					else
					{
						printf("%s\n",buff);
							
						a=lseek(fd, -1, SEEK_CUR);
					
						printf("fd at%ld\n",a);
					
						//j=0;
					}
				}
					
						
			}
		}
		else
		{
			printf("Parent is waiting!\n");
			wait(&wstatus);
			printf("Child exited! Parent done waiting\n");
			//wait(&wstatus);
			//printf("Child 2 exited! Parent done waiting\n");
		}
	}
	return 0;
}
