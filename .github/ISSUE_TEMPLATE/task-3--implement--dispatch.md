---
name: 'Task 3: Implement `dispatch()`  member method'
about: Task 3 for Students
title: 'Task 3: Implement `dispatch()` member method'
labels: enhancement
assignees: ''

---

**Description**

Implement the `dispatch()` member function.  The purpose of the dispatch is
to check if the cpu is currently idle, and if it is, it should dispatch the
next process that is at the head of the ready queue.  It can be the case that
the ready queue is empty, and thus in that case `dispatch()` would do nothing
since no process is currently ready to be dispatched, and the cpu would still be
idle after returning from the failed dispatch.

**Suggested Solution**


**Additional Requirements**

- You are required to correctly handle cases where there are no processes ready to be dispatched.  When no process is ready, the cpu should remain idle after the attempted dispatch.
