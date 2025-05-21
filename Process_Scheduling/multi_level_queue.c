#include <stdio.h>
#define MAX 10
void round_robin(int n, int bt[], int tq) {
int rem_bt[MAX], wt[MAX], tat[MAX], time = 0;
for (int i = 0; i < n; i++) rem_bt[i] = bt[i];
printf("\n[Queue 1 - Round Robin Scheduling]\n");
printf("Process\tBurst\tWaiting\tTurnaround\n");
int remain = n, flag;
while (remain > 0) {flag = 1;
for (int i = 0; i < n; i++) {
if (rem_bt[i] > 0) {
flag = 0;
if (rem_bt[i] <= tq) {
time += rem_bt[i];
rem_bt[i] = 0;
wt[i] = time - bt[i];
tat[i] = wt[i] + bt[i];
printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
remain--;
} else {
rem_bt[i] -= tq;
time += tq;
}
}
}
if (flag) break;
}
}
void fcfs(int n, int bt[]) {
int wt[MAX], tat[MAX], time = 0;
printf("\n[Queue 2 - FCFS Scheduling]\n");
printf("Process\tBurst\tWaiting\tTurnaround\n");
for (int i = 0; i < n; i++) {
wt[i] = time;
tat[i] = wt[i] + bt[i];
time += bt[i];
printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
}
}
int main() {
int sys_n, user_n, sys_bt[MAX], user_bt[MAX], tq;
printf("Enter number of system processes: ");
scanf("%d", &sys_n);
for (int i = 0; i < sys_n; i++) {
printf("Enter burst time for system process %d: ", i + 1);
scanf("%d", &sys_bt[i]);
}
printf("Enter time quantum for system queue (Round Robin): ");
scanf("%d", &tq);
printf("\nEnter number of user processes: ");
scanf("%d", &user_n);for (int i = 0; i < user_n; i++) {
printf("Enter burst time for user process %d: ", i + 1);
scanf("%d", &user_bt[i]);
}
round_robin(sys_n, sys_bt, tq);
fcfs(user_n, user_bt);
return 0;
}
