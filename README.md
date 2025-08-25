# 🖥️ Mini Process Manager (C)

A simple CLI-based process manager written in C.  
It lists running processes on Linux (PID, name, state, memory usage) and allows you to kill processes by PID.

---

## 🚀 Features
- List running processes from `/proc`
- Show:
  - **PID**
  - **Process name**
  - **State** (Running, Sleeping, etc.)
  - **Memory usage (KB)**
- Kill a process by entering its PID

---

## ⚡ Build & Run
Compile with `gcc`:
```bash
gcc proc_manager.c -o proc_manager
./proc_manager

 Example Output

1. List processes
2. Kill process
3. Exit
Choice: 1

PID    Name                 State  Memory(KB)
1234   bash                 S      2048
5678   firefox              R      120000

Kill a process:

Choice: 2
Enter PID to kill: 1234
Process 1234 terminated.


Requirements

Linux (uses /proc filesystem)
GCC (or any C compiler)
