#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint16_t program[] = {
  /*mem[0x3000]=*/    0x5020,    //  0101 0000 0010 0000             AND R0,R0,x0     ;initialize R0 to 0
  /*mem[0x3001]=*/    0x1025,    //  0001 0000 0010 0101             ADD R0,R0,x5     ;initialize R0 to 0x5
  /*mem[0x3002]=*/    0x1220,    //  0001 0010 0010 0000             ADD R1,R0,x0     ;copy to R0 to R1
  /*mem[0x3003]=*/    0x5020,    //  0101 0000 0010 0000             AND R0,R0,x0     ;initialize R0 to 0
  /*mem[0x3004]=*/    0x103D,    //  0001 0000 0011 1101             ADD R0,R0,-x3    ;initialize R0 to -0x3
  /*mem[0x3005]=*/    0x1240,    //  0001 0010 0100 0000             ADD R1,R1,R0     ;add contents of R0 to R1 R1=0x2
  /*mem[0x3006]=*/    0x1060,    //  0001 0000 0110 0000             ADD R0,R1,x0     ;copy R1 to R0, now R0=0x2 as well
  /*mem[0x3007]=*/    0xF025,    //  1111 0000 0010 0101             TRAP HALT        ;halt
};

int main(int argc, char** argv)
{
  char* outf = "sum.obj";
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
