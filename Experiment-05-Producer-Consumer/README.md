# Experiment 05: Producer–Consumer Problem

This experiment implements the classic Producer–Consumer problem using threads, mutexes, and semaphores to demonstrate synchronization.

## 🧪 Aim

To develop a C program that synchronizes producer and consumer threads using:
- **POSIX Threads (pthreads)**
- **Mutex Locks**
- **Semaphores**

## ⚙️ Components Used

- `pthread_create`, `pthread_join` – for creating and synchronizing threads
- `pthread_mutex_lock`, `pthread_mutex_unlock` – mutual exclusion for buffer access
- `sem_init`, `sem_wait`, `sem_post`, `sem_destroy` – semaphore operations

## 🔁 Logic

- A fixed-size buffer is shared between producer and consumer.
- The **producer** adds 10 random items to the buffer.
- The **consumer** removes 10 items from the buffer.
- **Semaphores** ensure bounded buffer constraints:
  - `empty` controls producer (waits if buffer is full)
  - `full` controls consumer (waits if buffer is empty)

## ▶️ How to Compile and Run

```bash
gcc producer-consumer.c -lpthread -o prodcon
./prodcon
```

## ✅ Sample Output

```
Producer 1 produced 34
Consumer 2 consumed 34
Producer 1 produced 67
Consumer 2 consumed 67
...
```

(Note: Output may vary due to random sleep and values)

## 🧠 Key Concepts Demonstrated

- Thread synchronization
- Critical section protection
- Bounded buffer implementation

## 🎯 Result

The Producer–Consumer synchronization problem was successfully solved using threads, mutexes, and semaphores.
