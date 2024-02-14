/** @file lc3vm_dbg.c
 * @brief LC-3 VM Debug / Test
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Spring 2024
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Implementation of LC-3 helper functions, useful
 * for debug and unit testing, functions to display memory
 * and registers, and show numbers as binary/hex etc.
 */
#include "lc3vm_dbg.h"

// DEBUG
void fprintf_binary(FILE *f, uint16_t num) {
    int c = 16;
    while(c-->0) {
        if ((c+1)%4==0) {
            fprintf(f, " ");
        }
        fprintf(f, "%d", (num>>c)&1);
    }
}

void fprintf_inst(FILE *f, uint16_t instr) {
    fprintf(f, "instr=%u, binary=", instr);
    fprintf_binary(f, instr);
    fprintf(f, "\n");
}

void fprintf_mem(FILE *f, uint16_t *mem, uint16_t from, uint16_t to) {
    for(int i = from; i < to; i++) {
        fprintf(f, "mem[%d|0x%.04x]=", i, i);
        fprintf_binary(f, mem[i]);
        fprintf(f, "\n");
    }
}

void fprintf_mem_nonzero(FILE *f, uint16_t *mem, uint32_t stop) {
    for(int i = 0; i < stop; i++) {
        if (mem[i]!=0) {
            fprintf(f, "mem[%d|0x%.04x]=", i, i);
            fprintf_binary(f, mem[i]);
            fprintf(f, "\n"); 
        }
    }
}

void fprintf_reg(FILE *f, uint16_t *reg, int idx) {
    fprintf(stdout, "reg[%d]=0x%.04x\n", idx, reg[idx]);
}

void fprintf_reg_all(FILE *f, uint16_t *reg, int size) {
    for(int i = 0; i < size; i++) {
        fprintf_reg(f, reg, i);
    }
}
