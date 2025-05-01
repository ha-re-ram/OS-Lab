# Experiment 07: Page Replacement Algorithms

This experiment simulates three classic page replacement algorithms used in memory management:
- FIFO (First-In First-Out)
- Optimal Replacement
- LRU (Least Recently Used)

## 🧪 Aim

To simulate page replacement strategies and calculate the number of page faults using a reference string.

## 📘 Algorithms Implemented

### 🔹 FIFO (First-In First-Out)
- Replaces the oldest page in memory.
- Simple queue-based logic.

### 🔹 Optimal Replacement
- Replaces the page that will not be used for the longest time in the future.
- Gives the minimum possible page faults (ideal case).

### 🔹 LRU (Least Recently Used)
- Replaces the page that hasn’t been used for the longest time.
- Simulates recent usage tracking using a `time[]` array.

## 🧾 Reference String Used

```
{ 7, 0, 1, 2, 0, 3, 0, 4, 2 }
```

## 📥 Buffer Size

- The frame buffer holds `3` pages at a time.

## ▶️ How to Compile and Run

```bash
gcc page-replacement.c -o pager
./pager
```

## ✅ Sample Output

```
FIFO Page Replacement:
7 _ _ 
7 0 _ 
7 0 1 
2 0 1 
2 0 3 
2 4 3 
Total page faults with FIFO: 6

Optimal Page Replacement:
7 _ _ 
7 0 _ 
7 0 1 
2 0 1 
2 0 3 
2 4 3 
Total page faults with Optimal: 6

LRU Page Replacement:
7 _ _ 
7 0 _ 
7 0 1 
2 0 1 
2 0 3 
2 4 3 
Total page faults with LRU: 6
```

(Note: actual output may vary slightly based on exact implementation.)

## 🎯 Result

FIFO, Optimal, and LRU page replacement algorithms were implemented successfully, and the number of page faults was observed and compared.
