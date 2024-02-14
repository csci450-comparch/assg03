#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint16_t program[] = {
  /*mem[0x3000]=*/    0x2208,    //  0010 0010 0000 1000             LD R1, #x8       ;R1 has loop count 0x0004
  /*mem[0x3001]=*/    0xE408,    //  1110 0100 0000 1000             LEA R2, #x8      ;Load base address of array into R2
  /*mem[0x3002]=*/    0x56E0,    //  0101 0110 1110 0000             AND R3, R3, #x0  ;initialize R3 to 0, will hold running sum
  /*mem[0x3003]=*/    0x6880,    //  0110 1000 1000 0000             LDR R4, R2, #x0  ;Load R4 with value in array being summed
  /*mem[0x3004]=*/    0x16C4,    //  0001 0110 1100 0100             ADD R3, R3, R4   ;add in current value to running sum in R3
  /*mem[0x3005]=*/    0x14A1,    //  0001 0100 1010 0001             ADD R2, R2, #x1  ;increment array address to next value
  /*mem[0x3006]=*/    0x127F,    //  0001 0010 0111 1111             ADD R1, R1, #x-1 ;decrement loop counter in R1 by 1
  /*mem[0x3007]=*/    0x03FB,    //  0000 0011 1111 1011             BRp #x-5         ;branch if loop counter is still > 0 back to 0x3003
  /*mem[0x3008]=*/    0xF025,    //  1111 0000 0010 0101             TRAP HALT        ;halt

  /*mem[0x3009]=*/    0x0004,    //  0000 0000 0000 0100             0x0004           ;+0x4 data loop counter
  /*mem[0x300A]=*/    0x0003,    //  0000 0000 0000 0011             0x0003           ;+0x3 array[0] first value to add
  /*mem[0x300B]=*/    0xFFFE,    //  1111 1111 1111 1110             0xFFFE           ;-0x2 array[1] second value to add
  /*mem[0x300C]=*/    0x0005,    //  0000 0000 0000 0101             0x0005           ;+0x5 array[2] third value to add
  /*mem[0x300D]=*/    0xFFFC,    //  1111 1111 1111 1100             0xFFFC           ;-0x4 array[3] fourth value to add
};

int main(int argc, char** argv)
{
  char* outf = "sumarray.obj";
  FILE* f = fopen(outf, "wb");
  if (NULL==f)
  {
    fprintf(stderr, "Cannot write to file %s\n", outf);
  }
  size_t writ = fwrite(program, 1, sizeof(program), f);
  fprintf(stdout, "sizeof program = %lu\n", sizeof(program));
  fprintf(stdout, "Written size_t = %lu to file %s\n", writ, outf);
  fclose(f);
  return 0;
}
