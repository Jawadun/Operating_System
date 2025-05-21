#include <stdio.h>
#include <pthread.h>
void* sayHello(void* arg) {
printf("Hello from thread!\n");
return NULL;
}
int main() {
pthread_t thread_id; 
if (pthread_create(&thread_id, NULL, sayHello, NULL) != 0) {
perror("Failed to create thread");
return 1;
}
if (pthread_join(thread_id, NULL) != 0) {
perror("Failed to join thread");
return 2;
}
printf("Back in main.\n");
return 0;
}
