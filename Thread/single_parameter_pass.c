#include <stdio.h>
#include <pthread.h>
void* printNumber(void* arg) {
int num = *((int*)arg); 
printf("Thread received number: %d\n", num);
return NULL;
}
int main() {
pthread_t thread;
int value = 42;
pthread_create(&thread, NULL, printNumber, &value);pthread_join(thread, NULL);
return 0;
}
