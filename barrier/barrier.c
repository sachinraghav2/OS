#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
pthread_barrier_t bar_id;
unsigned int count=3;
void *lcd_init(void *data){
    printf("In LCD_int now.\n");
    sleep(5);
    pthread_barrier_wait(&bar_id);
    printf("Lcd Initialized!\n");
}

void *ir_init(void *data){
    printf("In ir_int now.\n");
    sleep(2);
    pthread_barrier_wait(&bar_id);
    printf("ir Initialized!\n");
}

void *update_init(void *data){
    printf("In update_int now.\n");
    sleep(7);
    pthread_barrier_wait(&bar_id);
    printf("update Initialized!\n");
}

int main()
{
    pthread_t lcd_id, ir_id, update_id;
    pthread_barrier_init(&bar_id,NULL,count);
    pthread_create(&lcd_id, NULL, lcd_init, NULL);
    pthread_create(&ir_id, NULL, ir_init, NULL);
    pthread_create(&update_id, NULL, update_init, NULL);
    pthread_join(lcd_id,NULL);
    pthread_join(ir_id,NULL);
    pthread_join(update_id,NULL);
    pthread_barrier_destroy(&bar_id);
    return 0;
}
