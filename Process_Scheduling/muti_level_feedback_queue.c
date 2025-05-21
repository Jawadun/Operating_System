#include <stdio.h>
#define MAX 10
int processes[MAX], burst[MAX], rem[MAX], n;
void round_robin(int q[], int size, int tq, int start_time) {
int time = start_time;
int done[MAX] = {0};
while (1) {
int all_done = 1;
for (int i = 0; i < size; i++) {
int pid = q[i];
if (rem[pid] > 0) {
all_done = 0;
if (rem[pid] <= tq) {
time += rem[pid];
printf("P%d executed from %d to %d\n", pid + 1, time - rem[pid], time);
rem[pid] = 0;
done[pid] = 1;
} else {
printf("P%d executed from %d to %d (preempted)\n", pid + 1, time, time + tq);
rem[pid] -= tq;
time += tq;
}
}
}
if (all_done) break;
}
}
void fcfs(int q[], int size, int start_time) {
int time = start_time;
for (int i = 0; i < size; i++) {
int pid = q[i];
if (rem[pid] > 0) {printf("P%d executed from %d to %d\n", pid + 1, time, time + rem[pid]);
time += rem[pid];
rem[pid] = 0;
}
}
}
int main() {
int i, q1[MAX], q2[MAX], q3[MAX];
int n1 = 0, n2 = 0, n3 = 0;
printf("Enter number of processes: ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
processes[i] = i;
printf("Enter burst time for process P%d: ", i + 1);
scanf("%d", &burst[i]);
rem[i] = burst[i];
if (burst[i] <= 4) {
q1[n1++] = i;
} else if (burst[i] <= 8) {
q2[n2++] = i;
} else {
q3[n3++] = i;
}
}
printf("\n--- Executing Queue 1 (Round Robin, Quantum=4) ---\n");
round_robin(q1, n1, 4, 0);
printf("\n--- Executing Queue 2 (Round Robin, Quantum=8) ---\n");
round_robin(q2, n2, 8, 0);
printf("\n--- Executing Queue 3 (FCFS) ---\n");
fcfs(q3, n3, 0);
printf("\nAll processes executed.\n");
return 0;
}
