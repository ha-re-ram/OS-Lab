# Experiment 03: CPU Scheduling Algorithms

This experiment demonstrates various CPU scheduling algorithms by calculating waiting time and turnaround time for a set of processes.

---

## 🔹 03a – First Come First Serve (FCFS)

### 🧪 Aim

To simulate the FCFS scheduling algorithm and calculate:
- Waiting Time (WT)
- Turnaround Time (TAT)
- Averages of WT and TAT

### ▶️ How to Compile and Run

```bash
gcc 03a-fcfs.c -o fcfs
./fcfs
```

### 📈 Description

Processes are scheduled in the order of their arrival. Simple queue-based scheduling.

---

## 🔹 03b – Shortest Job First (SJF)

### 🧪 Aim

To implement the non-preemptive SJF algorithm by sorting processes based on burst time.

### ▶️ How to Compile and Run

```bash
gcc 03b-sjf.c -o sjf
./sjf
```

### 📈 Description

Processes with shorter burst times are prioritized. Reduces average waiting time.

---

## 🔹 03c – Shortest Remaining Time First (SRTF)

### 🧪 Aim

To simulate the preemptive version of SJF called SRTF, where the process with the least remaining time executes next.

### ▶️ How to Compile and Run

```bash
gcc 03c-srtf.c -o srtf
./srtf
```

### 📈 Description

Continuously checks for shortest remaining burst time among arrived processes. Offers better responsiveness for short jobs.

---

## 🔹 03d – Priority Scheduling

### 🧪 Aim

To schedule processes based on assigned priorities (lower value = higher priority).

### ▶️ How to Compile and Run

```bash
gcc 03d-priority.c -o priority
./priority
```

### 📈 Description

Each process is assigned a priority, and the CPU is allocated to the process with the highest priority available at the time.

---

## 🔹 03e – Round Robin (RR)

### 🧪 Aim

To simulate the Round Robin algorithm using time quantum for fair scheduling.

### ▶️ How to Compile and Run

```bash
gcc 03e-roundrobin.c -o rr
./rr
```

### 📈 Description

Each process gets a fixed time slice (quantum). Useful for time-sharing systems. Context switching occurs after each quantum.

---

## 📌 Common Output

Each program displays:
- Process ID, Burst Time, (and optionally Arrival Time & Priority)
- Waiting Time
- Turnaround Time
- Average WT and TAT

## 🎯 Result

All CPU scheduling algorithms were successfully implemented and tested for their efficiency in scheduling based on different strategies.
