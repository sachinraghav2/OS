#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
int main()
{
	pid_t id;
	id = fork();
	if(0 == id)
	{
		char string[20];
		printf("Enter the name of c-file!\n");
		scanf("%s",string);
			printf("Creating objdump in asm.txt!\n");
			execl("/usr/bin/objdump", "objdump", "-S", string, ">", "asm.text", NULL);
			printf("Created.\n");
	}
	else
	{
		pid_t id;
		char c;
		int status, count=0;;
		id = wait(&status);
		FILE *fp;
		fp = fopen("asm.txt","r");
		if(fp == NULL)
		{
			perror("Error ");
			exit(0);
		}
		else
		{
			while((c=fgetc(fp)) != EOF)
			{
				if(c == ':')
					count++;
			}
		}
		printf("Number of instructions: %d\n",count);
	}
	return 0;
}
