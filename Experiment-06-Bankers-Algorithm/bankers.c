// Placeholder content for bankers.c
#include <stdio.h>
#include <stdlib.h>

#define P 5 // Number of processes
#define R 3 // Number of resources

// Function declarations
void calculateNeed(int need[P][R], int max[P][R], int alloc[P][R]);
int isSafe(int avail[], int max[][R], int alloc[][R], int need[][R]);

int main() {
    int avail[R] = {3, 3, 2}; // Available instances of resources

    int max[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    }; // Maximum demand of each process

    int alloc[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    }; // Amount currently allocated

    int need[P][R]; // Remaining needs of each process

    calculateNeed(need, max, alloc);
    int safe = isSafe(avail, max, alloc, need);

    printf("System is %s\n", safe ? "in a safe state" : "not in a safe state");

    return 0;
}

// Function to calculate need matrix
void calculateNeed(int need[P][R], int max[P][R], int alloc[P][R]) {
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

// Function to check if system is in a safe state
int isSafe(int avail[R], int max[P][R], int alloc[P][R], int need[P][R]) {
    int finish[P] = {0};
    int safeSeq[P];
    int work[R];

    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    int count = 0;
    while (count < P) {
        int found = 0;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                if (j == R) {
                    for (int k = 0; k < R; k++)
                        work[k] += alloc[p][k];

                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is not in a safe state\n");
            return 0;
        }
    }

    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < P; i++)
        printf("%d ", safeSeq[i]);
    printf("\n");

    return 1;
}
