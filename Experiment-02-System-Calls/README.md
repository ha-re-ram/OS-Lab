# Experiment 02: Programs on System Calls

This experiment demonstrates the use of essential UNIX system calls for process and file management.

## 📌 Subpart - 02a: Process Management System Calls

### 🧪 Aim

To create a C program that demonstrates the use of `fork()`, `waitpid()`, and `getpid()` for process creation and synchronization.

### 📄 Code Summary

- `fork()`: Creates a new process (child).
- `getpid()` and `getppid()`: Fetch process and parent process IDs.
- `waitpid()`: Ensures parent waits for the child to complete before exiting.

### ▶️ How to Compile and Run

```bash
gcc 02a-process.c -o process
./process
```

### ✅ Expected Output

You will see messages from both the parent and child processes including their respective PIDs, with the parent waiting for the child to finish.

Example:
```
Parent Process: PID = 1234
Parent Process: Child PID = 1235
Child Process: PID = 1235
Child Process: Parent PID = 1234
Child Process: Exiting...
Parent Process: Child 1235 finished execution
```

## 🎯 Result

The process creation and synchronization using system calls was successfully implemented and executed.

## 📌 Subpart - 02b: File Handling System Calls

### 🧪 Aim

To write a C program that opens, reads, and closes a file using system calls: `open()`, `read()`, and `close()`.

### 📄 Code Summary

- `open("example.txt", O_RDONLY)`: Opens a file for reading.
- `read()`: Reads up to 99 characters into a buffer.
- `close()`: Closes the file descriptor safely.

### 📁 Note

Ensure a file named `example.txt` exists in the same directory with some sample text.

### ▶️ How to Compile and Run

```bash
gcc 02b-file.c -o filecall
./filecall
```

### ✅ Expected Output

Displays the content read from `example.txt`. Example:

```
Content read from the file:
Hello, this is a test file for system call demonstration.
```

If the file doesn't exist, an appropriate error will be shown.

## 🎯 Result

The file operations using `open()`, `read()`, and `close()` system calls were successfully demonstrated.
