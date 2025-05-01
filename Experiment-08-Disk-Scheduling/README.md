# Experiment 08: Disk Scheduling Algorithms

This experiment simulates different disk scheduling algorithms to calculate total head movement for a sequence of disk I/O requests.

## 🧪 Aim

To implement and compare the following disk scheduling strategies:
- FCFS (First Come First Serve)
- SSTF (Shortest Seek Time First)
- SCAN (Elevator Algorithm)
- C-SCAN (Circular SCAN)

## 💾 Disk Setup

- Initial Head Position: `53`
- Request Sequence: `{ 98, 183, 37, 122, 14, 124, 65, 67 }`
- Disk Range: `0 to 199` (for C-SCAN)

## 📘 Algorithms Explained

### 🔹 FCFS – First Come First Serve
- Services requests in the order they arrive.
- May result in long head movements.

### 🔹 SSTF – Shortest Seek Time First
- Selects the request closest to the current head position.
- Reduces seek time but may lead to starvation.

### 🔹 SCAN – Elevator Algorithm
- Moves the head in one direction servicing all requests, then reverses.
- Covers both ends of the queue efficiently.

### 🔹 C-SCAN – Circular SCAN
- Moves in one direction servicing requests, then jumps to the start without servicing during the return.
- Ensures uniform wait time.

## ▶️ How to Compile and Run

```bash
gcc disk-scheduling.c -o disk
./disk
```

## ✅ Sample Output

```
Initial head position at 53
FCFS Total Head Movement: 640
SSTF Total Head Movement: 236
SCAN Total Head Movement: 208
CSCAN Total Head Movement: 382
```

(Actual numbers may vary based on implementation details.)

## 🧠 Key Concepts Demonstrated

- Disk head optimization
- Trade-offs in seek time vs fairness
- Head movement efficiency across strategies

## 🎯 Result

All four disk scheduling algorithms were successfully implemented and tested. Their performances were compared based on total head movement.
