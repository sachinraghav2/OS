#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread (void *data)
{
	printf("This is thread!\n");
}

int main()
{
	pthread_t tid;
	printf("Creating thread!\n");
	pthread_create(&tid, NULL, thread, NULL);
	printf("Thread created!\n");
	pthread_join(tid,NULL);
	return 0;
}
