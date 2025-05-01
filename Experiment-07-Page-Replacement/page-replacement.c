// Placeholder content for page-replacement.c
#include <stdio.h>
#include <stdlib.h>

#define FRAME_SIZE 3
#define REF_LENGTH 9

int refs[REF_LENGTH] = {7, 0, 1, 2, 0, 3, 0, 4, 2}; // Example reference string
int frames[FRAME_SIZE];
int time[FRAME_SIZE]; // For LRU

void printFrames() {
    for (int i = 0; i < FRAME_SIZE; i++) {
        if (frames[i] == -1)
            printf("_ ");
        else
            printf("%d ", frames[i]);
    }
    printf("\n");
}

int findLRU() {
    int minimum = time[0], pos = 0;
    for (int i = 1; i < FRAME_SIZE; i++) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int pageReplacementFIFO() {
    int pos = 0, faults = 0;
    for (int i = 0; i < FRAME_SIZE; i++) frames[i] = -1;

    for (int i = 0; i < REF_LENGTH; i++) {
        int found = 0;
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j] == refs[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            frames[pos] = refs[i];
            pos = (pos + 1) % FRAME_SIZE;
            faults++;
            printFrames();
        }
    }
    return faults;
}

int pageReplacementOptimal() {
    int faults = 0;
    for (int i = 0; i < FRAME_SIZE; i++) frames[i] = -1;

    for (int i = 0; i < REF_LENGTH; i++) {
        int found = 0;
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j] == refs[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            int j;
            for (j = 0; j < FRAME_SIZE; j++) {
                if (frames[j] == -1) {
                    frames[j] = refs[i];
                    break;
                }
            }
            if (j == FRAME_SIZE) {
                int future[FRAME_SIZE];
                for (j = 0; j < FRAME_SIZE; j++) {
                    future[j] = 1000;
                    for (int k = i + 1; k < REF_LENGTH; k++) {
                        if (frames[j] == refs[k]) {
                            future[j] = k;
                            break;
                        }
                    }
                }
                int max = future[0], pos = 0;
                for (j = 1; j < FRAME_SIZE; j++) {
                    if (future[j] > max) {
                        max = future[j];
                        pos = j;
                    }
                }
                frames[pos] = refs[i];
            }
            faults++;
            printFrames();
        }
    }
    return faults;
}

int pageReplacementLRU() {
    int faults = 0;
    for (int i = 0; i < FRAME_SIZE; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for (int i = 0; i < REF_LENGTH; i++) {
        int found = 0;
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j] == refs[i]) {
                found = 1;
                time[j] = i;
                break;
            }
        }
        if (!found) {
            int pos = findLRU();
            frames[pos] = refs[i];
            time[pos] = i;
            faults++;
            printFrames();
        }
    }
    return faults;
}

int main() {
    printf("FIFO Page Replacement:\n");
    int fifo_faults = pageReplacementFIFO();
    printf("Total page faults with FIFO: %d\n\n", fifo_faults);

    printf("Optimal Page Replacement:\n");
    int optimal_faults = pageReplacementOptimal();
    printf("Total page faults with Optimal: %d\n\n", optimal_faults);

    printf("LRU Page Replacement:\n");
    int lru_faults = pageReplacementLRU();
    printf("Total page faults with LRU: %d\n", lru_faults);

    return 0;
}
