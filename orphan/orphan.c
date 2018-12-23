#include<stdio.h>
#include<unistd.h>

int main()
{
 	pid_t id;//opaque  datatypes
	printf("before fork pid=%d & ppid=%d\n",getpid(),getppid());
	printf("ID:%d\n",id);
	id=fork();
	if(0==id)
	{
	printf("child pid =%d & ppid=%d\n",getpid(), getppid());
	printf("ID:%d\n",id);
	sleep(1);
	printf("now i become orphan\n");
	printf("child pid=%d & ppid=%d\n",getpid(),getppid());
	printf("ID:%d\n",id);
	}
	else
{
	printf("parent pid =%d & ppid=%d\n",getpid(),getppid());
	printf("ID:%d\n",id);
}
return 0;

}
