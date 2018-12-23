#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
pthread_rwlock_t read_lock;
void *ir_read(void * data){
    printf("Inside ir_read, outside rd lock\n");
    pthread_rwlock_rdlock(&read_lock);
    printf("Inside ir_read, inside rd lock\n");
    sleep(3);
    pthread_rwlock_unlock(&read_lock);
}


void *use_ir_read(void * data){
    printf("Inside use_ir_read, outside rd lock\n");
    pthread_rwlock_rdlock(&read_lock);
    printf("Inside use_ir_read, inside rd lock\n");
    sleep(6);
    pthread_rwlock_unlock(&read_lock);
}


void *config_ir_read(void * data){
    printf("Inside config_ir_read, outside wr lock\n");
    pthread_rwlock_wrlock(&read_lock);
    printf("Inside config_ir_read, inside wr lock\n");
    pthread_rwlock_unlock(&read_lock);
}


int main()
{
    pthread_t ir_id, use_ir_id, config_ir_id;
    pthread_rwlock_init(&read_lock, NULL);
    pthread_create(&ir_id, NULL, ir_read, NULL);
    pthread_create(&use_ir_id, NULL, use_ir_read, NULL);
    pthread_create(&config_ir_id, NULL, config_ir_read, NULL);
    pthread_join(ir_id, NULL);
    pthread_join(use_ir_id, NULL);
    pthread_join(config_ir_id, NULL);
    return 0;
}
