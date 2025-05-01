# Experiment 06: Banker's Algorithm

This experiment implements the Banker's algorithm for safe resource allocation and deadlock avoidance in a multi-process environment.

## 🧪 Aim

To determine whether a system is in a safe state using:
- Maximum Resource Matrix
- Allocation Matrix
- Available Resources

## 🔢 Matrices Used

- **Max**: Maximum demand of each process
- **Alloc**: Current resource allocation to each process
- **Need**: Max - Alloc (calculated internally)
- **Available**: Currently available resources

## ⚙️ System Calls/Operations

- No external system calls required.
- Logic implemented through matrix operations and safety sequence checking.

## ▶️ How to Compile and Run

```bash
gcc bankers.c -o banker
./banker
```

## ✅ Sample Output

```
System is in a safe state.
Safe sequence is: 1 3 4 0 2
System is in a safe state
```

Or if not safe:
```
System is not in a safe state
```

## 🧠 Key Concepts Demonstrated

- Resource allocation safety
- Deadlock avoidance strategy
- Safe sequence generation for process execution

## 🎯 Result

Banker's algorithm was successfully implemented to determine system safety and prevent unsafe resource allocations.
