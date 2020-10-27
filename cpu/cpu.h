#ifndef CPU_H
#define CPU_H

typedef struct registers {
	int a, b, c, d, e, h, l, f;
	int sp, pc, r, m, ime;
} registers;

registers reg;
registers rsv;
unsigned int clock;
int halt;
int stop;

int ci;
int co;
int i;
int a;
int tr;
int m;
int hl;

int debug;
char debug_data[15][12]; // clock, opcode byte, opcode string, reg(12)

void cpu_reset();

void exec();

#include "mmu.h"

#endif