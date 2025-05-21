#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t mutex, wrt;
int read_count = 0;
int shared_data = 0; 
void* reader(void* arg) {
int f = ((int)(long)arg);
while (1) {
sem_wait(&mutex);
read_count++;
if (read_count == 1)
sem_wait(&wrt); 
printf("Reader %d: read shared_data = %d\n", f, shared_data);
sleep(1); 
sem_wait(&mutex);
read_count--;
if (read_count == 0)
sem_post(&wrt); 
sem_post(&mutex);
sleep(1);
}
}
void* writer(void* arg) {
int f = ((int)(long)arg);
while (1) {
sem_wait(&wrt);
shared_data++;
printf("Writer %d: wrote shared_data = %d\n", f, shared_data);
sleep(2);
sem_post(&wrt);
sleep(1);
}
}
int main() {
pthread_t r[5], w[2];
sem_init(&mutex, 0, 1);
sem_init(&wrt, 0, 1);
for (long i = 0; i < 5; i++)
pthread_create(&r[i], NULL, reader, (void*)i);
for (long i = 0; i < 2; i++)
pthread_create(&w[i], NULL, writer, (void*)i);
for (int i = 0; i < 5; i++)
pthread_join(r[i], NULL);for (int i = 0; i < 2; i++)
pthread_join(w[i], NULL);
sem_destroy(&mutex);
sem_destroy(&wrt);
return 0;
}
