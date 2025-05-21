#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
pid_t pid = fork(); 
if (pid < 0) {
perror("Fork failed");
return 1;
}
if (pid == 0) {
printf("Child: PID = %d\n", getpid());
sleep(2); 
exit(0);
} else {
printf("Parent: PID = %d, waiting for child...\n", getpid());
wait(NULL);
printf("Parent: Child finished. Exiting.\n");
}
return 0;
}
