// Placeholder content for 03b-sjf.c
#include <stdio.h>

// Structure for process
struct process {
    int pid; // Process ID
    int bt;  // Burst Time
};

// Function to sort processes by Burst Time (ascending order)
void sortByBurstTime(struct process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].bt > proc[j + 1].bt) {
                // Swap processes
                struct process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

// Calculate waiting time for all processes
void findWaitingTime(struct process proc[], int n, int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = proc[i - 1].bt + wt[i - 1];
    }
}

// Calculate turn around time for all processes
void findTurnAroundTime(struct process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = proc[i].bt + wt[i];
    }
}

// Calculate and print average times
void calculateAverageTime(struct process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    sortByBurstTime(proc, n);
    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);

    printf("\nSJF Scheduling:\n");
    printf("Process  Burst Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d\t    %d\t\t  %d\t\t   %d\n", proc[i].pid, proc[i].bt, wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
}

int main() {
    struct process proc[] = {{1, 6}, {2, 8}, {3, 7}, {4, 3}};
    int n = sizeof(proc) / sizeof(proc[0]);

    calculateAverageTime(proc, n);
    return 0;
}
// This code implements the Shortest Job First (SJF) CPU scheduling algorithm.