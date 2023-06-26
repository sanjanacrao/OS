#include<stdio.h>
typedef struct {
    int processId;
    int burstTime;
    int priority;
}Process;

void fcfs(Process processes[],int n){
    int waitingTime = 0;
    float totalWaitingTime = 0;
    float averageWaitingtime;
    printf("\nFCFS Scheduling Algorithm:\n");
    for (int i=0;i<n;i++){
        printf("Process %d is running.\n",processes[i].processId);
        waitingTime += processes[i].burstTime;
        printf("Process %d finished. waiting time:%d\n",processes[i].processId,waitingTime);
        totalWaitingTime += waitingTime;
    }
    averageWaitingtime = totalWaitingTime/n;
    printf("Average waiting Time: %.2f\n",averageWaitingtime);
}
void sjn(Process processes[],int n){
    int totalTime = 0;
    int waitingTime = 0;
    float totalWaitingTime = 0;
    float averageWaitingTime;
    printf("\nSJN Scheduling Algorithm:\n");
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(processes[j].burstTime>processes[j+1].burstTime){
                Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
                }
        }
    }
for ( int i = 0; i < n; i++){
    printf("Preocess %d is running.\n",processes[i].processId);
    waitingTime += totalTime;
    totalTime += processes[i].burstTime;
    printf("Process %d finished. Waiting Time: %d\n",processes[i].processId,waitingTime);
    totalWaitingTime += waitingTime; 
}
averageWaitingTime = totalWaitingTime /n;
printf("Average Waiting time : %.2f\n",averageWaitingTime);
}
void priorityScheduling(Process processes[],int n){
    int waitingTime = 0;
    float totalWaitingTime = 0;
    float averageWaitingTime;

    printf("\npriority Scheduling Algorithm:\n");
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if(processes[j].priority>processes[j+1].priority){
                Process temp = processes[j];
                processes[j]=processes[j+1];
                processes[j+1]=temp;
            }

        }

    }
    for ( int i = 0; i < n; i++){
    printf("Preocess %d is running.\n",processes[i].processId);
    waitingTime += processes[i].burstTime;
    printf("Process %d finished. Waiting Time: %d\n",processes[i].processId,waitingTime);
    totalWaitingTime += waitingTime; 
}
averageWaitingTime = totalWaitingTime /n;
printf("Average Waiting time : %.2f\n",averageWaitingTime);
    
}
int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    Process processes[n];

    for (int i=0;i<n;i++){
        printf("\n Enter details for process %d:\n",i+1);
        processes[i].processId = i+1;
        printf("Enter burst time: ");
        scanf("%d",&processes[i].burstTime);
        printf("Enter Priority: ");
        scanf("%d",&processes[i].priority);
    }
    fcfs(processes,n);
    sjn(processes,n);
    priorityScheduling(processes,n);

    return 0;
}
