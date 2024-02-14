---
name: 'Task 4: Implement `cpuEvent)` simulation member method'
about: Task 4 for Students
title: 'Task 4: Implement `cpuEvent()` simulation member method'
labels: enhancement
assignees: ''

---

**Description**

Implement basic `cpuEvent()` CPU cycles.  The `cpuEvent()` is relatively
simple.  The system time should be incremented by 1 every time a CPU event
occurs.  Also, if a process is currently running on the CPU, its `timeUsed`
should be incremented by 1 and its `quantumUsed` as well.  You should use the
`cpuCycle()` member function of the `Process` class to do the work needed to
increment the time used and quantum used of the current running process.

**Suggested Solution**


**Additional Requirements**



