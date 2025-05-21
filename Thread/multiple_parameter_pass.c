#include <stdio.h>
#include <pthread.h>
typedef struct {
int x;
int y;
} Args;
void* add(void* arg) {
Args* args = (Args*) arg;
int result = args->x + args->y;
printf("Sum: %d\n", result);
return NULL;
}
int main() {
pthread_t thread;
Args args = {5, 7};
pthread_create(&thread, NULL, add, &args);
pthread_join(thread, NULL);
return 0;
}
