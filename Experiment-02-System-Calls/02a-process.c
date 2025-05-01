#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;

    // Create a new process
    pid = fork();
    if (pid == -1) {
        // if fork() returns -1, an error occurred
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d\n", getpid());
        printf("Child Process: Parent PID = %d\n", getppid());
        // Execute an action here. For example, sleep for 2 seconds
        sleep(2);
        printf("Child Process: Exiting...\n");
        exit(EXIT_SUCCESS);
    }
    else {
        // Parent process
        printf("Parent Process: PID = %d\n", getpid());
        printf("Parent Process: Child PID = %d\n", pid);
        // Wait for the child to complete
        waitpid(pid, &status, 0);
        printf("Parent Process: Child %d finished execution\n", pid);
    }
    return EXIT_SUCCESS;
}
