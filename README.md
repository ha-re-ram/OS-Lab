# Operating Systems Lab Manual

This repository contains C programs and documentation for Operating Systems lab experiments. Each experiment focuses on a core OS concept, implemented and tested in C.

## 📚 Lab Details

- **Subject Code**: U21CS404  
- **Course**: Operating Systems Lab  
- **Department**: Computer Science and Engineering  
- **Language Used**: C  
- **Platform**: GCC/Linux Environment  

## 🧪 Experiments

| No. | Experiment Title                           | Description |
|-----|--------------------------------------------|-------------|
| 01  | Basics of UNIX Commands                    | Learn essential UNIX/Linux commands and editors. |
| 02  | System Calls                               | Implement process and file-related system calls. |
| 03  | CPU Scheduling Algorithms                  | Simulate FCFS, SJF, SRTF, Priority, Round Robin. |
| 04  | Inter Process Communication (IPC)          | Demonstrate pipes and shared memory usage. |
| 05  | Producer–Consumer Problem                  | Solve synchronization using threads and semaphores. |
| 06  | Banker's Algorithm                         | Deadlock avoidance using resource allocation logic. |
| 07  | Page Replacement Algorithms                | Implement FIFO, Optimal, and LRU algorithms. |
| 08  | Disk Scheduling Algorithms                 | Simulate FCFS, SSTF, SCAN, and C-SCAN. |
| 09  | File Organization Techniques               | Demonstrate sequential, random, and serial storage. |
| 10  | File Allocation Strategies                 | Simulate sequential, indexed, and linked allocation. |

## ⚙️ How to Compile and Run

Use `gcc` or any C compiler:

```bash
gcc filename.c -o output
./output
```

Example:

```bash
gcc 03a-fcfs.c -o fcfs
./fcfs
```

> Ensure relevant files like `example.txt` exist for file handling experiments.

## 🛠️ Requirements

- GCC Compiler  
- Linux Terminal or WSL  
- POSIX-compliant system calls  

## 🤝 Contributions

Feel free to fork and improve the documentation or code. Suggestions are welcome!
