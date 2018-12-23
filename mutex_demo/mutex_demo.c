#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t countMutex;
int count;

void *incthread(void * data)
{
    while(1)
    {
      pthread_mutex_lock(&countMutex);
              count++;
        printf("Inc-count = %d\n", count);
      pthread_mutex_unlock(&countMutex);
    }
}

void *decthread(void * data)
{
  while(1)
  {
      pthread_mutex_lock(&countMutex);
          count--;
      printf("Dec-count= %d\n",count);
      pthread_mutex_unlock(&countMutex);
  }
}

int main()
{

    pthread_t inc_id, dec_id;
    pthread_mutex_init( &countMutex, NULL);
    pthread_create( &inc_id, NULL, incthread, NULL);
    pthread_create( &dec_id, NULL, decthread, NULL);
    pthread_join(inc_id,NULL);
    pthread_join(dec_id,NULL);
    pthread_mutex_destroy(&countMutex);
//2    pthread_mutex_destroy(&countMutex);
    return 0;
}
