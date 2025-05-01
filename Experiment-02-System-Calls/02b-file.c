#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fileDescriptor;
    const char *text = "Hello, Hareram!\n";

    // Open the file for writing (create if it doesn't exist, truncate if it does)
    fileDescriptor = open("data.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fileDescriptor < 0) {
        perror("Failed to open the file");
        return EXIT_FAILURE;
    }

    // Write the text to the file
    ssize_t bytesWritten = write(fileDescriptor, text, strlen(text));
    if (bytesWritten < 0) {
        perror("Failed to write to the file");
        close(fileDescriptor);
        return EXIT_FAILURE;
    }

    // Close the file
    if (close(fileDescriptor) < 0) {
        perror("Failed to close the file");
        return EXIT_FAILURE;
    }

    printf("Data written successfully to data.txt\n");
    return EXIT_SUCCESS;
}
