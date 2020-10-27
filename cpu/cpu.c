#include <stdio.h>
#include "cpu.h"

#include "cpu_exec_loadstore.h"
#include "cpu_exec_dataprocess.h"
#include "cpu_exec_bitmanipulation.h"
#include "cpu_exec_misc.h"

#include "cpu_code_enum.h"
#include "cpu_code_debug.h"

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
	
	if(debug)sprintf(debug_data[0], "0x%08x", clock);
	
	if (!halt) {
		unsigned int opcode = mmu_rb(reg.pc);
		reg.pc++;
		
		if (opcode==0xcb) {
			opcode = mmu_rb(reg.pc);
			reg.pc++;
			if(debug)sprintf(debug_data[1], "0xcb%02x", opcode);
			if(debug)sprintf(debug_data[2], cbmap_debug[opcode]);
			(*cbmap[opcode]) ();
		}
		else {
			if(debug)sprintf(debug_data[1], "0x00%02x", opcode);
			if(debug)sprintf(debug_data[2], map_debug[opcode]);
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
			
			//clock += reg.m;
			//timer_inc();
		}
		else {
			reg.ime = 1;
		}
    }
	
	clock += reg.m;
	gpu_checkline();
	timer_inc();
	
		
	if(debug)sprintf(debug_data[3], "0x%02x", reg.a);
	if(debug)sprintf(debug_data[4], "0x%02x", reg.b);
	if(debug)sprintf(debug_data[5], "0x%02x", reg.c);
	if(debug)sprintf(debug_data[6], "0x%02x", reg.d);
	if(debug)sprintf(debug_data[7], "0x%02x", reg.e);
	if(debug)sprintf(debug_data[8], "0x%02x", reg.h);
	if(debug)sprintf(debug_data[9], "0x%02x", reg.l);
	if(debug)sprintf(debug_data[10], "0x%02x", reg.f);
	if(debug)sprintf(debug_data[11], "0x%04x", reg.sp);
	if(debug)sprintf(debug_data[12], "0x%04x", reg.pc);
	if(debug)sprintf(debug_data[13], "0x%02x", reg.r);
	if(debug)sprintf(debug_data[14], "0x%02x", reg.m);
}