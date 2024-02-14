/** @file lc3vm.h
 * @brief LC-3 VM API
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Spring 2024
 * @note   ide:  g++ 8.2.0 / GNU Make 4.2.1
 *
 * Header include file for LC-3 simulator API/functions.
 */
#include <stdint.h>
#include <stdbool.h>

#ifndef LC3VM_H
#define LC3VM_H

// total number of opcodes in the LC-3 architecture.
#define NOPS (16)

// Need to #define all of your bit manipulation macros like DR, SR1, etc. here.
#define TRP(i) ((i)&0xFF)

typedef void (*op_ex_f)(uint16_t i);
typedef void (*trp_ex_f)();

enum { trp_offset = 0x20 };
enum registr { R0 = 0, R1, R2, R3, R4, R5, R6, R7, RPC, RCND, RCNT };
enum flags { FP = 1 << 0, FZ = 1 << 1, FN = 1 << 2 };

// If we are creating tests, make all declarations extern C so can
// work with catch2 C++ framework
#ifdef TEST
extern "C" bool running;
extern "C" uint16_t mem[];
extern "C" uint16_t reg[];
extern "C" uint16_t PC_START;

// you need to add all function prototypes here with extern "C" before each one.
extern "C" void rti(uint16_t i);
extern "C" void res(uint16_t i);
extern "C" void tgetc();
extern "C" void tout();
extern "C" void tputs();
extern "C" void tin();
extern "C" void thalt();
extern "C" void tinu16();
extern "C" void toutu16();
extern "C" void trap(uint16_t i);
extern "C" void ld_img(char *fname, uint16_t offset);

// otherwise make them regular declarations
#else
extern bool running;
extern uint16_t mem[];
extern uint16_t reg[];
extern uint16_t PC_START;

// you will add in the same function prototype for all function here as well, just without
// the extern "C" syntax cruft
void rti(uint16_t i);
void res(uint16_t i);
void tgetc();
void tout();
void tputs();
void tin();
void thalt();
void tinu16();
void toutu16();
void trap(uint16_t i);
void ld_img(char *fname, uint16_t offset);
#endif

#endif // LC3VM_H
