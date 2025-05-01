// Placeholder content for 03e-roundrobin.c
#include <stdio.h>
struct process {
    int pid; // Process ID
    int bt;  // Burst Time
    int at;  // Arrival Time
    int wt;  // Waiting Time
    int tat; // Turnaround Time
};

void findWaitingTime(struct process proc[], int n, int quantum) {
    int rem_bt[n];
    int t = 0; // Current time

    // Initialize remaining burst times
    for (int i = 0; i < n; i++)
        rem_bt[i] = proc[i].bt;

    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && proc[i].at <= t) {
                done = 0;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    proc[i].wt = t - proc[i].bt - proc[i].at;
                    rem_bt[i] = 0;
                }
            }
        }

        // All done
        if (done == 1)
            break;
    }
}

void findTurnAroundTime(struct process proc[], int n) {
    for (int i = 0; i < n; i++)
        proc[i].tat = proc[i].wt + proc[i].bt;
}

void calculateAverageTime(struct process proc[], int n, int quantum) {
    findWaitingTime(proc, n, quantum);
    findTurnAroundTime(proc, n);

    int total_wt = 0, total_tat = 0;

    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, proc[i].at, proc[i].wt, proc[i].tat);
    }

    printf("\nAverage waiting time = %.2f", (float)total_wt / n);
    printf("\nAverage turnaround time = %.2f\n", (float)total_tat / n);
}

int main() {
    struct process proc[] = {{1, 6, 1}, {2, 8, 1}, {3, 7, 2}, {4, 3, 3}};
    int n = sizeof(proc) / sizeof(proc[0]);
    int quantum = 2;

    calculateAverageTime(proc, n, quantum);
    return 0;
}
