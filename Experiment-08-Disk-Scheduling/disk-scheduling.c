// Placeholder content for disk-scheduling.c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 8

int requests[SIZE] = {98, 183, 37, 122, 14, 124, 65, 67};
int head = 53;

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int calculateTotalMovement(int req[], int n, int initialPos) {
    int totalMovement = 0;
    int currentPos = initialPos;
    for (int i = 0; i < n; i++) {
        totalMovement += abs(currentPos - req[i]);
        currentPos = req[i];
    }
    return totalMovement;
}

void FCFS() {
    printf("FCFS Total Head Movement: %d\n", calculateTotalMovement(requests, SIZE, head));
}

void SSTF() {
    int done[SIZE] = {0}, totalMovement = 0, currentPos = head, closest, minDist, idx;
    for (int i = 0; i < SIZE; i++) {
        minDist = INT_MAX;
        for (int j = 0; j < SIZE; j++) {
            if (!done[j] && abs(currentPos - requests[j]) < minDist) {
                closest = requests[j];
                minDist = abs(currentPos - requests[j]);
                idx = j;
            }
        }
        done[idx] = 1;
        totalMovement += minDist;
        currentPos = closest;
    }
    printf("SSTF Total Head Movement: %d\n", totalMovement);
}

void SCAN() {
    int totalMovement = 0, currentPos = head;
    int temp[SIZE + 1], n = 0;
    for (int i = 0; i < SIZE; i++)
        temp[n++] = requests[i];

    temp[n++] = 0; // End of disk
    sort(temp, n);

    int pos = 0;
    while (pos < n && temp[pos] < currentPos) pos++;

    // Left side
    for (int i = pos - 1; i >= 0; i--) {
        totalMovement += abs(currentPos - temp[i]);
        currentPos = temp[i];
    }
    // Right side
    for (int i = pos; i < n; i++) {
        totalMovement += abs(currentPos - temp[i]);
        currentPos = temp[i];
    }

    printf("SCAN Total Head Movement: %d\n", totalMovement);
}

void CSCAN() {
    int totalMovement = 0, currentPos = head;
    int temp[SIZE + 2], n = 0;
    for (int i = 0; i < SIZE; i++)
        temp[n++] = requests[i];

    temp[n++] = 0;
    temp[n++] = 199; // End of disk (assuming 0–199)

    sort(temp, n);

    int pos = 0;
    while (pos < n && temp[pos] < currentPos) pos++;

    // Move toward the end
    for (int i = pos; i < n; i++) {
        totalMovement += abs(currentPos - temp[i]);
        currentPos = temp[i];
    }

    // Jump to start
    totalMovement += abs(currentPos - 0);
    currentPos = 0;

    // Continue servicing from beginning
    for (int i = 0; i < pos; i++) {
        totalMovement += abs(currentPos - temp[i]);
        currentPos = temp[i];
    }

    printf("CSCAN Total Head Movement: %d\n", totalMovement);
}

int main() {
    printf("Initial head position at %d\n", head);
    FCFS();
    SSTF();
    SCAN();
    CSCAN();
    return 0;
}
