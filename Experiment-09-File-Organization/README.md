# Experiment 09: File Organization Techniques

This experiment demonstrates three different file organization techniques:
- Sequential
- Random (Hashed)
- Serial (Unordered)

## 🧪 Aim

To implement and visualize how records are organized in memory using different file organization strategies.

## 📁 Record Structure

Each record contains:
- An `int` key
- A `char[]` data field

```c
typedef struct {
    int key;
    char data[20];
} Record;
```

## 📘 Organization Methods

### 🔹 Sequential
- Records are inserted in order of their keys.
- Simple and predictable.
  
### 🔹 Random
- Uses a simple hash function `(i * 3) % n` for index placement.
- Simulates direct access file organization.

### 🔹 Serial
- Records are inserted with unordered keys.
- Simulates the behavior of unordered flat files.

## ▶️ How to Compile and Run

```bash
gcc file-org.c -o fileorg
./fileorg
```

## ✅ Sample Output

```
Sequential File Organization:
Record 0: Key = 0, Data = Data1
Record 1: Key = 1, Data = Data2
...

Random File Organization:
Record 0: Key = 0, Data = Data1
Record 1: Key = 3, Data = Data4
...

Serial File Organization:
Record 0: Key = 5, Data = Data1
Record 1: Key = 6, Data = Data2
...
```

(Note: Actual output may vary depending on insertion logic and hash function.)

## 🧠 Key Concepts Demonstrated

- Comparison of record storage strategies
- Data placement using direct and unordered methods
- Impact of structure on data retrieval

## 🎯 Result

Sequential, Random, and Serial file organization techniques were successfully implemented and compared.
