// Placeholder content for producer-consumer.c
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

pthread_mutex_t mutex;
sem_t full, empty;

void* producer(void* param) {
    int item;
    for (int i = 0; i < 10; i++) {
        sleep(rand() % 5);
        item = rand() % 100; // Produce an item

        sem_wait(&empty); // Wait for empty slot
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        printf("Producer %ld produced %d\n", (long)param, item);

        pthread_mutex_unlock(&mutex);
        sem_post(&full); // Signal full slot
    }
    pthread_exit(0);
}

void* consumer(void* param) {
    int item;
    for (int i = 0; i < 10; i++) {
        sleep(rand() % 5);

        sem_wait(&full); // Wait for full slot
        pthread_mutex_lock(&mutex);

        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        printf("Consumer %ld consumed %d\n", (long)param, item);

        pthread_mutex_unlock(&mutex);
        sem_post(&empty); // Signal empty slot
    }
    pthread_exit(0);
}

int main() {
    pthread_t tid[2]; // Thread identifiers

    // Initialize mutex and semaphores
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // Create producer and consumer threads
    pthread_create(&tid[0], NULL, producer, (void*)1L);
    pthread_create(&tid[1], NULL, consumer, (void*)2L);

    // Wait for threads to finish
    for (int i = 0; i < 2; i++) {
        pthread_join(tid[i], NULL);
    }

    // Clean up
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
