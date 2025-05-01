# Experiment 04: Inter Process Communication (IPC)

This experiment demonstrates how two processes (parent and child) communicate using:
- **Shared Memory**
- **Pipes**

## 🧪 Aim

To develop a C program that shows Inter-Process Communication by:
- Writing a message from parent to child using shared memory.
- Sending an acknowledgment back from child to parent using a pipe.

## 🧱 System Calls Used

- `shmget()`, `shmat()`, `shmdt()`, `shmctl()` – Shared memory segment handling.
- `pipe()` – For creating unidirectional communication channel.
- `fork()`, `wait()` – To create and synchronize parent-child processes.
- `write()`, `read()` – For pipe communication.

## ▶️ How to Compile and Run

```bash
gcc ipc-sharedmemory-pipe.c -o ipc
./ipc
```

## 🧪 Expected Output

```
Parent wrote: Hello from Shared Memory!
Child reads: Hello from Shared Memory!
Parent reads: Message received via pipe!
```

## 🔄 Flow Summary

1. Parent creates shared memory and writes a message.
2. Child attaches to shared memory and reads the message.
3. Child writes confirmation through pipe.
4. Parent reads confirmation.
5. Shared memory is detached and cleaned up.

## 🎯 Result

Inter-process communication was successfully implemented using shared memory and pipes in a parent-child setup.
