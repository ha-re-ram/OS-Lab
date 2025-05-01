// Placeholder content for file-org.c
#include <stdio.h>
#include <stdlib.h>

#define RECORDS 5

typedef struct {
    int key;
    char data[20];
} Record;

Record database[RECORDS];

// Function to display records
void displayRecords() {
    for (int i = 0; i < RECORDS; i++) {
        printf("Record %d: Key = %d, Data = %s\n", i, database[i].key, database[i].data);
    }
}

// Sequential insertion
void sequentialInsert() {
    for (int i = 0; i < RECORDS; i++) {
        database[i].key = i;
        sprintf(database[i].data, "Data%d", i + 1);
    }
}

// Random insertion based on a hash function
void randomInsert() {
    int index;
    for (int i = 0; i < RECORDS; i++) {
        index = (i * 3) % RECORDS;  // Simple hash function
        database[index].key = i;
        sprintf(database[index].data, "Data%d", i + 1);
    }
}

// Serial insertion simulating unordered keys
void serialInsert() {
    for (int i = 0; i < RECORDS; i++) {
        database[i].key = i + 5;  // Random starting key
        sprintf(database[i].data, "Data%d", i + 1);
    }
}

int main() {
    printf("Sequential File Organization:\n");
    sequentialInsert();
    displayRecords();

    printf("\nRandom File Organization:\n");
    randomInsert();
    displayRecords();

    printf("\nSerial File Organization:\n");
    serialInsert();
    displayRecords();

    return 0;
}
