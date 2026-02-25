# CST-315_Assignment-2
**Course:** CST 315 Operating Systems
**Programmer:** Komal Khan 

# Monitor in C++ **[monitor.cpp](monitor.cpp)**
# Semaphore in C++ **[semaphore.cpp](semaphore.cpp)**

## How to run
### Prerequisites
- Kate text editor
- Ubuntu Linux (24.04.1)

### Steps
# Semaphore
1. Write the code in Kate text editor then save the file in the directory as semaphore.cpp
2. Use the g++ (C++ compiler to run the code)
3. In Linux type: g++ semaphore.cpp -o semaphore -pthread -std=c++20 (g++ is compiler, semaphore.cpp is the source file, -o semaphore is the output the executable file, pthread links posix, stdc++20 is for compiling the code in new standard)
4. Then type to run ./ semaphore  (specify the path where the file is located)

### Output:
Producer and consumer (use of synchronization with shared buffer)

# Monitor

## How to run
### Steps
1. Write code in Kate save file as monitor.cpp
2. Open Linux terminal and type g++ monitor.cpp -o monitor -pthread
3. ./monitor to execute the code

### Output:
Producer and consumer (how montior controls access to shared data)
