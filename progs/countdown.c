#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint16_t program[] = {
  /*mem[0x3000]=*/    0xE205,    //  1110 0010 0000 0101             LEA R1,#x05      ;load address of start of data, 0x3006
  /*mem[0x3001]=*/    0x6440,    //  0110 0100 0100 0000             LDR R2, R1, #x0  ;load R2 with value to decrement
  /*mem[0x3002]=*/    0x6641,    //  0110 0110 0100 0001             LDR R3, R1, #x1  ;load R3 with decrement value
  /*mem[0x3003]=*/    0x1483,    //  0001 0100 1000 0011             ADD R2, R2, R3   ;addr offset to R2, should decrement by 2 each loop
  /*mem[0x3004]=*/    0x03FE,    //  0000 0011 1111 1110             BRp #x-0x2       ;branch on positive to 0x3003
  /*mem[0x3005]=*/    0xF025,    //  1111 0000 0010 0101             TRAP HALT        ;halt
  /*mem[0x3006]=*/    0x0004,    //  0000 0000 0000 0100             0x0004           ;+0x4 initial loop counter
  /*mem[0x3007]=*/    0xFFFE,    //  1111 1111 1111 1110             0xFFFE           ;-0x2 loop decrement amount
};

int main(int argc, char** argv)
{
  char* outf = "countdown.obj";
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
