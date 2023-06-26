#include<stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = bt[i-1] + wt[i-1];
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes   Burst time   Waiting time   Turn around time\n");

    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d ", (i + 1));
        printf("       %d ", bt[i]);
        printf("       %d", wt[i]);
        printf("       %d\n", tat[i]);
    }
    float s = (float)total_wt / (float)n;
    float t = (float)total_tat / (float)n;
    printf("Average waiting time = %.2f\n", s);
    printf("Average turnaround time = %.2f\n", t);
}

int main()
{
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burst_time[n];

    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1;
    }

    findavgTime(processes, n, burst_time);
    return 0;
}
