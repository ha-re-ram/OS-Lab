// Placeholder content for 03c-srtf.c
#include <stdio.h>
#include <limits.h>

// Structure for a process
struct process {
    int pid; // Process ID
    int bt;  // Burst Time
    int at;  // Arrival Time
};

// Function to find waiting time of all processes
void findWaitingTime(struct process proc[], int n, int wt[]) {
    int rt[n]; // Remaining time
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    int check = 0;

    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((proc[j].at <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) {
            t++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        if (rt[shortest] == 0) {
            complete++;
            check = 0;
            finish_time = t + 1;
            wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].at;
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(struct process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

// Function to calculate average time
void calculateAverageTime(struct process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);

    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\tCompletion Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        int compl_time = tat[i] + proc[i].at;
        printf("  %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", proc[i].pid, proc[i].bt, proc[i].at, wt[i], tat[i], compl_time);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turn Around Time: %.2f\n", (float)total_tat / n);
}

// Main function
int main() {
    struct process proc[] = {{1, 6, 1}, {2, 8, 1}, {3, 7, 2}, {4, 3, 3}};
    int n = sizeof(proc) / sizeof(proc[0]);

    calculateAverageTime(proc, n);
    return 0;
}

