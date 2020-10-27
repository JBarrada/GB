#ifndef CPU_H
#define CPU_H

typedef struct registers {
	unsigned int a, b, c, d, e, h, l, f;
	unsigned int sp, pc, r, m, ime;
} registers;

registers reg;
registers rsv;
unsigned int clock;
unsigned int halt;
unsigned int stop;

unsigned int ci;
unsigned int co;
unsigned int i;
unsigned int a;
unsigned int tr;
unsigned int m;
unsigned int hl;

#include "cpu_code_enum.h"

void cpu_reset();

void exec();

#endif