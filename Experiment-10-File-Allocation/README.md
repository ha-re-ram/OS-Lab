# Experiment 10: File Allocation Strategies

This experiment demonstrates the three primary file allocation strategies used in file systems:
- Sequential Allocation
- Indexed Allocation
- Linked Allocation

## 🧪 Aim

To simulate how files are stored on disk using various allocation methods, ensuring space is managed efficiently and access is maintained.

## 💾 Disk Setup

- Disk is simulated as an integer array of size `10`.
- Value `0` indicates an unallocated block.
- File IDs are used to mark allocated blocks.

## 📘 Allocation Techniques

### 🔹 Sequential Allocation

- Allocates consecutive disk blocks for each file.
- Easy to implement and access.
- May lead to external fragmentation.

```c
sequentialAllocation(fileID, fileSize);
```

### 🔹 Indexed Allocation

- A separate index block holds all the pointers to the file blocks.
- Reduces fragmentation and allows direct access.

```c
int blocks[] = {3, 4, 5};
indexedAllocation(fileID, blocks);
```

### 🔹 Linked Allocation

- Each block points to the next block (simulated here using a circular loop).
- Efficient use of disk space.
- Slower access time due to traversal.

```c
linkedAllocation(fileID, startBlock, fileSize);
```

## ▶️ How to Compile and Run

```bash
gcc file-allocation.c -o filealloc
./filealloc
```

## ✅ Sample Output

```
Sequential Allocation for File 1:
Disk State: 1 1 1 0 0 0 0 0 0 0 

Indexed Allocation for File 2:
Disk State: 1 1 1 2 2 2 0 0 0 0 

Linked Allocation for File 3:
Disk State: 1 1 1 2 2 2 3 3 3 0 
```

(Note: Disk layout may vary depending on availability.)

## 🧠 Key Concepts Demonstrated

- File storage techniques in operating systems
- Impact of allocation strategy on disk utilization and access speed
- Handling of fragmentation and space management

## 🎯 Result

Sequential, Indexed, and Linked file allocation strategies were successfully implemented and compared for their effectiveness.
