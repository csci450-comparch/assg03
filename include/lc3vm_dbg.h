/** @file lc3vm_dbg.h
 * @brief LC-3 VM Debug / Test
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Spring 2024
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for LC-3 helper functions, useful
 * for debug and unit testing, functions to display memory
 * and registers, and show numbers as binary/hex etc.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef LC3VM_DBG_H
#define LC3VM_DBG_H

void fprintf_binary(FILE *f, uint16_t num);
void fprintf_inst(FILE *f, uint16_t instr);
void fprintf_mem(FILE *f, uint16_t *mem, uint16_t from, uint16_t to);
void fprintf_mem_nonzero(FILE *f, uint16_t *mem, uint32_t stop);
void fprintf_reg(FILE *f, uint16_t *reg, int idx);
void fprintf_reg_all(FILE *f, uint16_t *reg, int size);

#endif // LC3VM_DBG_H
