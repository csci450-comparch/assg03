/** @file assg03-sim.cpp
 * @brief LC-3 Simulator
 *
 * @author Student Name
 * @note   cwid: 123456
 * @date   Spring 2024
 * @note   ide:  VS Code Editor / IDE ; g++ 8.2.0 / GNU Make 4.2.1
 *
 * Command line invocation of LC-3 microarchitecture/VM simulator.
 * We expect the name of a LC-3 machine language binary file
 * as the one and only input.  This starts the LC-3 simulator and
 * "interprets" the given program, displaying status information
 * during and at end of run of the program.
 */
#include "lc3vm.h"
#include "lc3vm_dbg.h"

int main(int argc, char **argv)
{
  ld_img(argv[1], 0x0);
  fprintf(stdout, "Occupied memory after program load:\n");
  fprintf_mem_nonzero(stdout, mem, UINT16_MAX);
  // Full system tests, to get the system tests to work and this simulation
  // to finally run, uncomment the call to the start() main function that you
  // should have implemented in task 9.
  //start(0x0); // START PROGRAM
  fprintf(stdout, "Occupied memory after program execution:\n");
  fprintf_mem_nonzero(stdout, mem, UINT16_MAX);
  fprintf(stdout, "Registers after program execution:\n");
  fprintf_reg_all(stdout, reg, RCNT);
  return 0;
}
