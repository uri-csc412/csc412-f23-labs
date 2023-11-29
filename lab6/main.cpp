#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>

// TODO: Define a 'Process' structure with necessary attributes
struct Process {
    // TODO: Implement the structure members
};

// TODO: Implement comparison for the priority queue for FCFS scheduling if necessary

// TODO: Declare global variables for shared resources among threads, if any

// Simulate the execution of a process. This will be executed by each thread.
void executeProcess(int pid) {
    // TODO: Implement functionality for process execution simulation
    // Hint: You might need synchronization constructs to handle shared resources
    
    // Simulating process execution. You may need to replace the following line with actual computations or function calls representing the process's task.
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Dummy execution time (you can adjust this as needed)
}

// implement FCFS scheduling here
void firstComeFirstServed(/* TODO: Define parameters if needed */) {
    // TODO: Implement the FCFS scheduling algorithm.
    // Hint: You may need a data structure to hold your processes as they arrive and are scheduled for execution.
}

// implement Round Robin scheduling here
void roundRobin(/* TODO: Define parameters if needed */) {
    // TODO: Implement the Round Robin scheduling algorithm.
    // Hint: Consider how you will handle the time quantum and the scheduling queue.
}

int main() {
    // TODO: Initialize process details. You might want to get these details from user input or a file.
    
    // TODO: Setup your environment - load processes, initialize variables, etc.

    // TODO: Start FCFS Scheduler. Make sure to signal threads to start when ready.

    // TODO: Reset the ready state for the next scheduling algorithm, if necessary.

    // TODO: Start Round Robin Scheduler. Consider how you'll manage the time quantum and signal threads.

    return 0; // Exit the program
}
