#include <stdio.h>
void main() {
int n, i, j;
int burst_time[20], process[20], wait_time[20], turnaround_time[20];
int temp;
float total_wait = 0, total_turnaround = 0;
printf("Enter number of processes: ");
scanf("%d", &n);
for(i = 0; i < n; i++) {
printf("Enter burst time for process %d: ", i + 1);
scanf("%d", &burst_time[i]);
process[i] = i + 1; 
}
for(i = 0; i < n - 1; i++) {
for(j = i + 1; j < n; j++) {
if(burst_time[i] > burst_time[j]) {
temp = burst_time[i];
burst_time[i] = burst_time[j];
burst_time[j] = temp;
temp = process[i];
process[i] = process[j];
process[j] = temp;
}
}
}
wait_time[0] = 0;
for(i = 1; i < n; i++) {
wait_time[i] = 0;
for(j = 0; j < i; j++)
wait_time[i] += burst_time[j];
total_wait += wait_time[i];
}
for(i = 0; i < n; i++) {
turnaround_time[i] = burst_time[i] + wait_time[i];total_turnaround += turnaround_time[i];
}
printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
for(i = 0; i < n; i++) {
printf("P%d\t\t%d\t\t%d\t\t%d\n", process[i], burst_time[i], wait_time[i], turnaround_time[i]);
}
printf("\nAverage Waiting Time = %.2f", total_wait / n);
printf("\nAverage Turnaround Time = %.2f\n", total_turnaround / n);
}
