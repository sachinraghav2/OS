#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int a,b;
sem_t in2sum, sum2in;
void *inthread(void *data)
{
	while(1){
	sem_wait(&sum2in);
		scanf("%d",&a);
		scanf("%d",&b);
	sem_post(&in2sum);
	}
}

void *sumthread(void *data)
{
	while(1){
	sem_wait(&in2sum);
	printf("sum = %d\n", a+b);
	sem_post(&sum2in);
	}
}

int main()
{
	sem_init( &in2sum, 0, 0);
	sem_init( &sum2in, 0, 1);
	pthread_t inid, sumid;
	pthread_create( &inid, NULL, inthread, NULL);
	pthread_create( &sumid, NULL, sumthread, NULL);
	pthread_join(inid, NULL);
	pthread_join(sumid, NULL);
	sem_destroy(&in2sum);
	sem_destroy(&sum2in);
	return 0;
}
