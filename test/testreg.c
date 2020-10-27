#include <stdio.h>

typedef struct registers {
	int a, b, c, d, e, h, l, f;
	int sp, pc, r, m, ime;
} registers;

registers reg;

int ci;
int co;
int i;
int a;
int tr;
int m;
int hl;

void main() {
	reg.a = 0x00;
	reg.pc = 0x67;
	reg.m = 3;
	
	
	i=reg.a;
	m=0x90; 
	i-=m; 
	reg.pc++; 
	reg.f=(i<0)?0x50:0x40; 
	i&=255; 
	if(!i) 
		reg.f|=0x80; 
	if((reg.a^i^m)&0x10) 
		reg.f|=0x20;
	reg.m=2;

	reg.pc++; // cpu

	i=0xfa; 
	if(i>127) 
		i=-((~i+1)&255); 
	reg.pc++; 
	reg.m=2; 
	if((reg.f&0x80)==0x80) {
		reg.pc+=i; 
		reg.m++; 
	}
	
	printf("pc: %02x", reg.pc);
}