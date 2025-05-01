// Placeholder content for 03d-priority.c
#include <stdio.h>
#include <limits.h>

// Structure for a process
struct process {
    int pid;      // Process ID
    int bt;       // Burst Time
    int at;       // Arrival Time
    int priority; // Priority
};

// Function to find the waiting time for all processes
void findWaitingTime(struct process proc[], int n, int wt[]) {
    int rt[n]; // Remaining time
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;

    int complete = 0, t = 0;
    int min_priority = INT_MAX;
    int shortest = 0, finish_time;
    int check = 0;

    while (complete != n) {
        min_priority = INT_MAX;
        check = 0;

        // Find the process with highest priority (lowest number)
        for (int j = 0; j < n; j++) {
            if ((proc[j].at <= t) && (proc[j].priority < min_priority) && rt[j] > 0) {
                min_priority = proc[j].priority;
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) {
            t++;
            continue;
        }

        // Reduce remaining time by one
        rt[shortest]--;

        // If a process gets completely executed
        if (rt[shortest] == 0) {
            complete++;
            finish_time = t + 1;
            wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].at;
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }

        // Increment time
        t++;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(struct process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

// Function to calculate and print average times
void calculateAverageTime(struct process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);

    printf("\nProcess\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, proc[i].at, proc[i].priority, wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
}

// Main function
int main() {
    struct process proc[] = {{1, 6, 1, 2}, {2, 8, 1, 1}, {3, 7, 2, 3}, {4, 3, 3, 4}};
    int n = sizeof(proc) / sizeof(proc[0]);
    calculateAverageTime(proc, n);
    return 0;
}
