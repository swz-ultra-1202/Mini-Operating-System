# Mini Operating System in C++

This is a console-based mini operating system developed in C++. It simulates core operating system functionalities like process creation, termination, memory management, and includes various utility applications.

Built using **WSL (Ubuntu 20.04)** and compatible with native Linux environments and Linux-based virtual machines.

---

## Features

- Add a new process at runtime  
- Terminate a running process  
- Display the PCB (Process Control Block) table  
- Allocate memory, RAM, and CPU cores to processes  
- Simulate 18+ utility applications with resource management

---

## Menu Applications

| Option | Application Name             | Resources Required                 |
|--------|------------------------------|------------------------------------|
| 1      | Calculator                   | 1 Core, 125 MB HDD, 3 MB RAM       |
| 2      | Calendar                     | 1 Core, 50 MB HDD, 2 MB RAM        |
| 3      | Clock                        | 1 Core, 25 MB HDD, 1 MB RAM        |
| 4      | Notepad                      | 1 Core, 30 MB HDD, 5 MB RAM        |
| 5      | File Delete                  | 1 Core, 25 MB HDD, 5 MB RAM        |
| 6      | Horse Bet Game               | 1 Core, 100 MB HDD, 15 MB RAM      |
| 7      | System Info                  | 1 Core, 20 MB HDD, 2 MB RAM        |
| 8      | PCB Table                    | 1 Core, 50 MB HDD, 5 MB RAM        |
| 9      | Mini Instagram               | 1 Core, 75 MB HDD, 8 MB RAM        |
| 10     | List Current Directory       | 1 Core, 10 MB HDD, 2 MB RAM        |
| 11     | Terminate Process            | 1 Core, 30 MB HDD, 4 MB RAM        |
| 12     | Schedule Tasks               | 1 Core, 40 MB HDD, 5 MB RAM        |
| 13     | Tic Tac Toe                  | 1 Core, 50 MB HDD, 5 MB RAM        |
| 14     | Math Quiz                    | 1 Core, 60 MB HDD, 4 MB RAM        |
| 15     | Guess the Number             | 1 Core, 30 MB HDD, 3 MB RAM        |
| 16     | Resource Monitor (CPU/RAM)   | 1 Core, 40 MB HDD, 6 MB RAM        |
| 17     | IQ Checker                   | 1 Core, 50 MB HDD, 4 MB RAM        |
| 18     | Typing Test                  | 1 Core, 50 MB HDD, 5 MB RAM        |
| 19     | Shutting Down                | -                                  |

---

## Installation and Usage

### Requirements

- Linux or WSL (Ubuntu 20.04 or later)  
- `g++` compiler  
- `cmake` and `make` tools

### Build Instructions

1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-username/mini-os-cpp.git
   cd mini-os-cpp


2.Create build directory and compile:
mkdir build
cd build
cmake ..
make
3.Run the OS with custom resource configuration:
./CrashOS <CPU_CORES> <RAM_MB> <HDD_GB>
Example:
./CrashOS 8 256 8
-This will start the mini OS with:
-> 8 CPU cores
-> 256 MB RAM
-> 8 GB HDD


Author:
M.Shah Nawaz
Email: shahnawaz.swz1202@gmail.com
