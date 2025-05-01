// Placeholder content for ipc-sharedmemory-pipe.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int segment_id;
    char* shared_memory;
    const int size = 4096;
    char* message = "Hello from Shared Memory!";
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create the shared memory segment
    segment_id = shmget(IPC_PRIVATE, size, S_IRUSR | S_IWUSR);
    if (segment_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // ----- Child Process -----
        shared_memory = (char*) shmat(segment_id, NULL, 0);
        if (shared_memory == (char *) -1) {
            perror("shmat");
            exit(EXIT_FAILURE);
        }

        printf("Child reads: %s\n", shared_memory);

        // Send confirmation via pipe
        close(pipefd[0]); // Close read end
        char* confirmation = "Message received via pipe!";
        write(pipefd[1], confirmation, strlen(confirmation) + 1);
        close(pipefd[1]);

        shmdt(shared_memory); // Detach
    } else {
        // ----- Parent Process -----
        shared_memory = (char*) shmat(segment_id, NULL, 0);
        strncpy(shared_memory, message, size);
        printf("Parent wrote: %s\n", message);

        wait(NULL); // Wait for child to finish

        // Read confirmation from child
        close(pipefd[1]); // Close write end
        char buffer[100];
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Parent reads: %s\n", buffer);
        close(pipefd[0]);

        // Clean up
        shmdt(shared_memory);
        shmctl(segment_id, IPC_RMID, NULL);
    }

    return 0;
}
