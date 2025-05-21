#include <stdio.h>
int main() {
int i, n, time, remain, flag = 0, tq;
int wait_time = 0, turnaround_time = 0;
int arrival[10], burst[10], remaining[10];
printf("Enter number of processes: ");
scanf("%d", &n);
remain = n;
for(i = 0; i < n; i++) {
printf("Enter arrival time for process %d: ", i+1);
scanf("%d", &arrival[i]);
printf("Enter burst time for process %d: ", i+1);
scanf("%d", &burst[i]);
remaining[i] = burst[i];
}
printf("Enter Time Quantum: ");
scanf("%d", &tq);
printf("\nProcess\tTurnaround Time\tWaiting Time\n");
for(time = 0, i = 0; remain != 0;) {
if(remaining[i] > 0 && arrival[i] <= time) {
if(remaining[i] <= tq) {
time += remaining[i];
remaining[i] = 0;
flag = 1;
} else {
remaining[i] -= tq;time += tq;
}
if(remaining[i] == 0 && flag == 1) {
remain--;
int wt = time - arrival[i] - burst[i];
int tat = time - arrival[i];
printf("P%d\t%d\t\t%d\n", i + 1, tat, wt);
wait_time += wt;
turnaround_time += tat;
flag = 0;
}
}
i = (i + 1) % n;
int all_idle = 1;
for (int j = 0; j < n; j++) {
if (remaining[j] > 0 && arrival[j] <= time) {
all_idle = 0;
break;
}
}
if (all_idle) time++;
}
printf("\nAverage Waiting Time = %.2f", (float)wait_time / n);
printf("\nAverage Turnaround Time = %.2f\n", (float)turnaround_time / n);
return 0;
}
