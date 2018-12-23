#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_t id[2];

void *thread(void * data){
    printf("%s\n", data);
}


int main()
{
    pthread_create(&id[0], NULL, thread, "Hello!");
    pthread_create(&id[1], NULL, thread, "Bye");
    pthread_join(id[0], NULL);
    pthread_join(id[1], NULL);
    return 0;
}
