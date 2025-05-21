#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>int counter = 0;
sem_t semaphore; 
void* increment(void* arg) {
for (int i = 0; i < 100000; i++) {
sem_wait(&semaphore); 
counter++;
sem_post(&semaphore); 
}
return NULL;
}
int main() {
pthread_t t1, t2;
sem_init(&semaphore, 0, 1);
pthread_create(&t1, NULL, increment, NULL);
pthread_create(&t2, NULL, increment, NULL);
pthread_join(t1, NULL);
pthread_join(t2, NULL);
printf("Final counter value: %d\n", counter);
sem_destroy(&semaphore);
return 0;
}
