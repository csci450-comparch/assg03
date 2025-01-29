---
name: 'Task 1: Implement memory access functions'
about: Task 1 for Students
title: 'Task 1: Implement memory access functions'
labels: enhancement, good first issue
assignees: ''

---

**Description**

Implement the `mem_read()` and `mem_write()` memory access helpe functions for
the LC-3 microcode simulator.  These functions simulate datapath operations that cause
data to go out of cpu to memory or to come back from memory into the cpu registers.

`mem_read()` takes an `uint16_t` as input which is interpreted as a 16-bit address.
The value in the LC-3 vm memory should be fetched and returned as a result from
this function.   All words in the LC-3 machine are `uint16_t` 16-bit values, so this
function returns an `uint16_t` as a result of calling it.

`mem_write` moves data in the opposite direction.  This is a void function.  It takes
a memory address as its first parameter, and a value as its second parameter. Both
parameters are `uint16_t` types.  The value given as the second parameter should be
written into the LC-3 memory at the indicated address.


**Suggested Solution**


**Additional Requirements**

