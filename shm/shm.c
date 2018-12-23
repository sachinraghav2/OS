#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
	char *p;
	int id= shmget(IPC_PRIVATE, 20, IPC_CREAT | 0664);
	printf("id: %d \n",id);
	p=shmat(id,NULL,0);
	printf("addr: %p\n",p);
	strcpy(p,"Hello");
	printf("%s\n",p);
	shmdt(p);
	//printf("%s\n",p);
	//shmctl(id, IPC_ORMID, (struct buf *)0);
	return 0;
}
