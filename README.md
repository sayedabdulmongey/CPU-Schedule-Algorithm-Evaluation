# CPU Schedule Algorithm Evalution

The Algorithms in this repo is : <br />
 1. First Come First Serve (FCFS) <br />
 2. Shortest Job First (SJF) <br />
 3. Shortest Remaining Job First (SRJF) <br />
 4. Round Robin <br />

# FCFS Scheduling Algorithm

## Overview

The First-Come-First-Serve (FCFS) scheduling algorithm is one of the simplest and most straightforward scheduling algorithms used in operating systems. In FCFS, the process that arrives first is the one that gets executed first. It follows a non-preemptive scheduling approach, meaning that once a process starts its execution, it continues until it completes without any interruptions.

## How FCFS Works

1. **Arrival of Processes:**
   - As processes arrive, they are added to the ready queue.
   - The ready queue is a data structure that holds all the processes that are ready to execute.

2. **Execution Order:**
   - The process at the front of the ready queue is selected for execution.
   - The selected process runs until it completes its execution or is blocked by an I/O operation.

3. **Completion and Arrival:**
   - Once a process finishes its execution, the next process in the ready queue becomes the new running process.

4. **No Preemption:**
   - FCFS is non-preemptive, meaning a process cannot be interrupted or stopped once it starts executing.

## Pros and Cons

### Pros:
- Simplicity: FCFS is easy to understand and implement.
- No starvation: Every process gets a fair chance to execute.

### Cons:
- **Convoy Effect:** Short processes might get stuck waiting behind a long process, causing a convoy effect.
- **Average Waiting Time:** FCFS can lead to a high average waiting time, especially if there are significant variations in process burst times.

## Usage

FCFS is suitable for scenarios where simplicity is crucial, and there is no need for complex scheduling strategies. However, it may not be ideal for systems where minimizing average waiting time is a critical factor.

## Example

Consider the following processes with their arrival times and burst times:

| Process | Arrival Time | Burst Time |
|---------|--------------|------------|
| P1      | 0            | 8          |
| P2      | 1            | 4          |
| P3      | 2            | 3          |

The FCFS order of execution would be P1 -> P2 -> P3.
