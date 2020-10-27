#include <stdio.h>
#include "cpu.h"

void cpu_reset() {
	reg.a = 0;
	reg.b = 0;
	reg.c = 0;
	reg.d = 0;
	reg.e = 0;
	reg.h = 0;
	reg.l = 0;
	reg.f = 0;
	reg.sp = 0;
	reg.pc = 0;
	reg.r = 0;
	reg.m = 0;
	reg.ime = 1;
	halt = 0;
	stop = 0;
	clock = 0;
}

void exec() {
	reg.r = (reg.r+1) & 127;
	    printf("\n\nREAD OP  | ");
	unsigned int opcode = mmu_rb(reg.pc++);
	if (opcode==0xcb) {
		opcode = mmu_rb(reg.pc++);
		printf("\nop: cb%02x | ", opcode);
	}
	else
		printf("\nop:   %02x | ", opcode);
	
	switch (opcode) {
		#include "cpu_exec_loadstore.h"
		#include "cpu_exec_dataprocess.h"
		#include "cpu_exec_bitmanipulation.h"
		#include "cpu_exec_misc.h"
	}
	
	reg.pc &= 65535;
	clock += reg.m;
}