#include "cpu.h"

#include "cpu_exec_loadstore.h"
#include "cpu_exec_dataprocess.h"
#include "cpu_exec_bitmanipulation.h"
#include "cpu_exec_misc.h"

#include "cpu_code_enum.h"

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
	
	if (!halt) {
		unsigned int opcode = mmu_rb(reg.pc);
		reg.pc++;	

		if (opcode==0xcb) {
			opcode = mmu_rb(reg.pc);
			reg.pc++;
			(*cbmap[opcode]) ();
		}
		else {
			(*map[opcode]) ();
		}
		
		reg.pc &= 65535;
	}
	
	if(reg.ime && mmu_.ie_ && mmu_.if_) {
        halt = 0;
		reg.ime = 0;
        unsigned char ifired = mmu_.ie_ & mmu_.if_;

		if(ifired & 0x01)
		{
			mmu_.if_ &= (255-0x01);
			RST40();
		}
		else {
			reg.ime = 1;
		}
    }
	
	clock += reg.m;
	gpu_checkline();
	timer_inc();
}
