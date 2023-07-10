#include<stdio.h>

int main() {
  int time, burst_time[10], at[10], sum_burst_time = 0, smallest, n, i;
  int sumt = 0, sumw = 0;
  printf("enter the no of processes : ");
  scanf("%d", & n);
  for (i = 0; i < n; i++) {
    printf("the arrival time for process P%d : ", i + 1);
    scanf("%d", & at[i]);
    printf("the burst time for process P%d : ", i + 1);
    scanf("%d", & burst_time[i]);
    sum_burst_time += burst_time[i];
  }
  burst_time[9] = 9999;
  for (time = 0; time < sum_burst_time;) {
    smallest = 9;
    for (i = 0; i < n; i++) {
      if (at[i] <= time && burst_time[i] > 0 && burst_time[i] < burst_time[smallest])
        smallest = i;
    }
    printf("P[%d]\t|\t%d\t|\t%d\n", smallest + 1, time + burst_time[smallest] - at[smallest], time - at[smallest]);
    sumt += time + burst_time[smallest] - at[smallest];
    sumw += time - at[smallest];
    time += burst_time[smallest];
    burst_time[smallest] = 0;
  }
  printf("\n\n average waiting time = %f", sumw * 1.0 / n);
  printf("\n\n average turnaround time = %f", sumt * 1.0 / n);
  return 0;
}


Enter the total number of Processes: 4

Please Enter the  Burst Time and Priority of each process:

Enter the details of the process A 
Enter the burst time: 1
Enter the priority: 1

Enter the details of the process B 
Enter the burst time: 5
Enter the priority: 1

Enter the details of the process C 
Enter the burst time: 1
Enter the priority: 1

Enter the details of the process D 
Enter the burst time: 6
Enter the priority: 1


Process_name     Burst Time      Waiting Time     Turnaround Time
------------------------------------------------------------
          A               1              0               1
-----------------------------------------------------------
          B               5              1               6
-----------------------------------------------------------
          C               1              6               7
-----------------------------------------------------------
          D               6              7               13
-----------------------------------------------------------


 Average Waiting Time : 3.500000
 Average Turnaround Time: 6.750000
[1] + Done                       "/usr/bin/gdb" --interpreter=mi --tty=${DbgTerm} 0<"/tmp/Microsoft-MIEngine-In-0zcy5ln1.zuq" 1>"/tmp/Microsoft-MIEngine-Out-jhu1fvvc.5gq"
@sanjanacrao ➜ /workspaces/OS (main) $ 
