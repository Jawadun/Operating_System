#include <stdio.h>
#include <limits.h>
int main() {
int n, i, smallest, time = 0, count = 0;
int arrival[10], burst[10], remaining[10], wait[10], turnaround[10];
float total_wait = 0, total_turnaround = 0;
printf("Enter number of processes: ");
scanf("%d", &n);
for(i = 0; i < n; i++) {
printf("Enter arrival time for process %d: ", i + 1);
scanf("%d", &arrival[i]);
printf("Enter burst time for process %d: ", i + 1);
scanf("%d", &burst[i]);
remaining[i] = burst[i]; 
}
while(count < n) {
smallest = -1;
int min_time = INT_MAX;
for(i = 0; i < n; i++) {
if(arrival[i] <= time && remaining[i] > 0 && remaining[i] < min_time) {
min_time = remaining[i];
smallest = i;
}
}
if(smallest == -1) {
time++;
continue;
}
remaining[smallest]--;
time++;
if(remaining[smallest] == 0) {
count++;
int finish_time = time;
turnaround[smallest] = finish_time - arrival[smallest];
wait[smallest] = turnaround[smallest] - burst[smallest];
total_wait += wait[smallest];total_turnaround += turnaround[smallest];
}
}
printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
for(i = 0; i < n; i++) {
printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, arrival[i], burst[i], wait[i], turnaround[i]);
}
printf("\nAverage Waiting Time = %.2f", total_wait / n);
printf("\nAverage Turnaround Time = %.2f\n", total_turnaround / n);
return 0;
}
