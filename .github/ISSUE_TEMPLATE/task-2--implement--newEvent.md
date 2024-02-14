---
name: 'Task 2: Implement `newEvent()`  member function'
about: Task 2 for Students
title: 'Task 2: Implement `newEvent()` member function'
labels: enhancement
assignees: ''

---

**Description**

Implement the `newEvent()` function.  The `newEvent()` function is called
whenever a "new"  occurs in the simulation.  Basically you need to create a new
process, assign it the correct next process id, make the process ready, and add
it to the end of your ready queue.

**Suggested Solution**


**Additional Requirements**

- You will need to have a functioning process control block here, so that get process by
  process id returns the correct new `Process` object that you create in this task.

