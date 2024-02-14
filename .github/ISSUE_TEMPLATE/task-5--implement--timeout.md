---
name: 'Task 5: Implement `timeout()` simulation member method'
about: Task 5 for Students
title: 'Task 5: Implement `timeout()` simulation member method'
labels: enhancement
assignees: ''

---

**Description**

Implement the `timeout()` function.  This is the other implicit action needed
for your simulation.  The basic thing that `timeout()` should do is to test if
the quantumUsed of the current running process is equal to or has exceeded the
system time slice quantum.  If it has, then the process needs to be timed out,
which means it goes back to a ready state and is returned back to the tail of
the ready queue.

**Suggested Solution**


**Additional Requirements**

- You are required to use the `isQuantumExceeded()` and `timeout()` member methods of the `Process` class/instance in the implementation of the simulations timeout procedure.

