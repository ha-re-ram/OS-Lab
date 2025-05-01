// Placeholder content for 03a-fcfs.c
#include <stdio.h>

// Define a structure for processes
struct process {
    int pid; // Process ID
    int bt;  // Burst Time
};

// Function to find waiting time for all processes
void findWaitingTime(struct process proc[], int n, int wt[]) {
    wt[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = proc[i - 1].bt + wt[i - 1];
    }
}

// Function to calculate turn around time for all processes
void findTurnAroundTime(struct process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = proc[i].bt + wt[i];
    }
}

// Function to calculate average time
void calculateAverageTime(struct process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);

    printf("\nProcesses  Burst time  Waiting time  Turn around time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d\t\t %d\t\t %d\t\t %d\n", proc[i].pid, proc[i].bt, wt[i], tat[i]);
    }

    printf("\nAverage waiting time = %.2f", (float)total_wt / n);
    printf("\nAverage turn around time = %.2f\n", (float)total_tat / n);
}

int main() {
    struct process proc[] = {{1, 6}, {2, 8}, {3, 7}, {4, 3}};
    int n = sizeof(proc) / sizeof(proc[0]);

    calculateAverageTime(proc, n);
    return 0;
}
