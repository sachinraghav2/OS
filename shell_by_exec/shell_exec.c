#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define SIZE 16
char add_on[]= "/bin/";
int main(int argc, char *argv[])
{
	
	printf("\n**********************MyShell-v1.0***************************\n\n");
	execl("/bin/sh", "sh",NULL);
	/*pid_t id;
	id = fork();
	if(0 == id)
	{
		char buff[SIZE], buff1[SIZE];
		strcpy(buff1, add_on);
		//printf("\n**********************MyShell-v1.0***************************\n\n");
		printf(">$ ");
		scanf("%s",buff);
		strcat(buff1,buff);
		execv(buff1,buff1,NULL);
	}
	else
	{
		pid_t wait_id;
		int status;
		wait_id = wait(&status);
		execl("./a.out","./a.out",NULL);
	}*/
	return 0;
}
