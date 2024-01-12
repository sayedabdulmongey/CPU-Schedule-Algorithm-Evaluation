# CPU Schedule Algorithm Evalution

The Algorithms in this repo is : <br />
 1. First Come First Serve (FCFS) <br />
 2. Shortest Job First (SJF) <br />
 3. Shortest Remaining Job First (SRJF) <br />
 4. Round Robin <br />

## FCFS Scheduling Algorithm

### Overview

The First-Come-First-Serve (FCFS) scheduling algorithm is one of the simplest and most straightforward scheduling algorithms used in operating systems. In FCFS, the process that arrives first is the one that gets executed first. It follows a non-preemptive scheduling approach, meaning that once a process starts its execution, it continues until it completes without any interruptions.

### How FCFS Works

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

### Pros and Cons

#### Pros:
- Simplicity: FCFS is easy to understand and implement.
- No starvation: Every process gets a fair chance to execute.

#### Cons:
- **Convoy Effect:** Short processes might get stuck waiting behind a long process, causing a convoy effect.
- **Average Waiting Time:** FCFS can lead to a high average waiting time, especially if there are significant variations in process burst times.

### Usage

FCFS is suitable for scenarios where simplicity is crucial, and there is no need for complex scheduling strategies. However, it may not be ideal for systems where minimizing average waiting time is a critical factor.

### Example

Consider the following processes with their arrival times and burst times:

| Process | Arrival Time | Burst Time |
|---------|--------------|------------|
| P1      | 0            | 8          |
| P2      | 1            | 4          |
| P3      | 2            | 3          |

The FCFS order of execution would be P1 -> P2 -> P3.
---

# Shortest Job First (SJF) Scheduling Algorithm

## Overview

The Shortest Job First (SJF) scheduling algorithm is a non-preemptive algorithm that selects the process with the shortest burst time for execution. It aims to minimize the total processing time and reduce the average waiting time for processes.

### How SJF Works

1. **Arrival of Processes:**
   - As processes arrive, they are added to the ready queue.
   - The ready queue is a data structure that holds all the processes that are ready to execute.

2. **Execution Order:**
   - The process with the shortest burst time is selected for execution first.
   - If two processes have the same burst time, FCFS order is used to break the tie.

3. **Completion and Arrival:**
   - Once a process finishes its execution, the next process with the shortest burst time becomes the new running process.

4. **Preemption:**
   - SJF is non-preemptive, meaning a process cannot be interrupted or stopped once it starts executing.

### Pros and Cons

#### Pros:
- **Minimizes Waiting Time:** SJF aims to minimize the waiting time and total processing time by prioritizing short jobs.

#### Cons:
- **Predicting Burst Time:** Difficulty in accurately predicting the burst time of processes in advance.
- **Starvation:** Long processes may face starvation if short processes keep arriving.

## Usage

SJF is suitable for scenarios where predicting or estimating the burst time of processes is feasible. It works well when there is a mix of short and long processes.

### Example

Consider the following processes with their arrival times and burst times:

| Process | Arrival Time | Burst Time |
|---------|--------------|------------|
| P1      | 0            | 6          |
| P2      | 2            | 8          |
| P3      | 4            | 3          |
| P4      | 6            | 5          |

The SJF order of execution would be P1 -> P3 -> P4 -> P2.

---

# Shortest Remaining Job First (SRJF) Scheduling Algorithm

## Overview

The Shortest Remaining Job First (SRJF) scheduling algorithm is a preemptive version of the Shortest Job First (SJF) algorithm. It selects the process with the shortest remaining burst time for execution, potentially preempting the currently running process.

### How SRJF Works

1. **Arrival of Processes:**
   - As processes arrive, they are added to the ready queue.
   - The ready queue is a data structure that holds all the processes that are ready to execute.

2. **Execution Order:**
   - The process with the shortest remaining burst time is selected for execution.
   - If two processes have the same remaining burst time, the tie is broken based on the process that arrived first.

3. **Completion and Arrival:**
   - The process continues to execute until its burst time is fully consumed.
   - New processes can arrive, and the scheduler may preempt the currently running process if a shorter one becomes available.

4. **Preemption:**
   - SRJF is preemptive, meaning processes can be interrupted and moved back to the ready queue before their completion if a shorter job arrives.

### Pros and Cons

#### Pros:
- **Minimizes Waiting Time:** Aims to minimize the waiting time by prioritizing processes with the shortest remaining burst time.

#### Cons:
- **Predicting Burst Time:** Difficulty in accurately predicting the burst time of processes in advance.
- **Increased Context Switching:** Preemption may lead to higher context-switching overhead.

## Usage

SRJF is suitable for scenarios where predicting or estimating the burst time of processes is feasible and the benefits of reduced waiting time outweigh the costs of increased context switching.

### Example

Consider the following processes with their arrival times and burst times:

| Process | Arrival Time | Burst Time |
|---------|--------------|------------|
| P1      | 0            | 6          |
| P2      | 2            | 8          |
| P3      | 4            | 3          |
| P4      | 6            | 5          |

The SRJF order of execution would depend on the remaining burst times at different points in time as the processes execute.
---


# Round Robin (RR) Scheduling Algorithm

## Overview

Round Robin is a preemptive scheduling algorithm that assigns a fixed time unit (time quantum or time slice) to each process in the system. Once a process's allocated time is consumed, it is moved to the back of the queue, and the next process in the queue is given a chance to execute.

### How RR Works

1. **Arrival of Processes:**
   - As processes arrive, they are added to the ready queue.
   - The ready queue is a data structure that holds all the processes that are ready to execute.

2. **Execution Order:**
   - Each process is assigned a fixed time quantum for execution.
   - When a process's time quantum expires, it is moved to the end of the queue, and the next process in line gets a chance to execute.

3. **Completion and Arrival:**
   - The process continues to cycle through the ready queue until it completes its execution.

4. **Preemption:**
   - RR is preemptive, meaning processes can be interrupted and moved back to the ready queue before their completion if their time quantum expires.

### Pros and Cons

#### Pros:
- **Fairness:** Ensures all processes get a fair share of CPU time.
- **Responsive:** Good for time-sharing systems.

#### Cons:
- **High Context Switching:** The overhead of frequent context switching may impact performance.
- **Poor for Long Processes:** Long processes may face delays until they get another turn.

## Usage

Round Robin is suitable for scenarios where fairness and responsiveness are essential, such as in time-sharing systems.

### Example

Consider the following processes with their arrival times and burst times:

| Process | Arrival Time | Burst Time |
|---------|--------------|------------|
| P1      | 0            | 5          |
| P2      | 1            | 3          |
| P3      | 3            | 8          |
| P4      | 5            | 2          |

Assuming a time quantum of 2, the RR order of execution would be P1 -> P2 -> P3 -> P4 -> P1 -> P2 -> P3 -> P1 -> ...
---
---
## Process Structure Explanation

The `process` structure is designed to represent information about a computing process. Let's break down its components:

- **`name`**: This field holds the name of the process, providing a unique identifier.

- **`arrival_time`**: A vector that can store multiple arrival times for the process. This is useful in scenarios where a process may have multiple phases of arrival.

- **`total_burst_time`**: Represents the total amount of time the process requires for its execution. This value is constant and does not change during the process's execution.

- **`remaining_burst_time`**: Keeps track of the remaining time needed for the process to complete its execution. This value is dynamic and gets updated as the process runs.

- **`dispatch_time`**: Another vector that records dispatch (start) times. It helps in keeping track of when the process begins its execution.

Additionally, there is a commented-out `operator<` function. This function, when uncommented, provides a way to customize the comparison between two processes. In the provided example, it compares processes based on their remaining burst time in descending order. However, the comparison logic can be modified based on specific requirements, such as prioritizing processes by arrival time or other criteria.

This `process` structure is designed to be flexible and adaptable to various scheduling scenarios, allowing for a comprehensive representation of process-related information.

