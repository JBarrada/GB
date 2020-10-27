/*--- Stack ---*/
void PUSHBC() {reg.sp--; mmu_wb(reg.sp,reg.b); reg.sp--; mmu_wb(reg.sp,reg.c); reg.m=3; }
void PUSHDE() {reg.sp--; mmu_wb(reg.sp,reg.d); reg.sp--; mmu_wb(reg.sp,reg.e); reg.m=3; }
void PUSHHL() {reg.sp--; mmu_wb(reg.sp,reg.h); reg.sp--; mmu_wb(reg.sp,reg.l); reg.m=3; }
void PUSHAF() {reg.sp--; mmu_wb(reg.sp,reg.a); reg.sp--; mmu_wb(reg.sp,reg.f); reg.m=3; }

void POPBC() {reg.c=mmu_rb(reg.sp); reg.sp++; reg.b=mmu_rb(reg.sp); reg.sp++; reg.m=3; }
void POPDE() {reg.e=mmu_rb(reg.sp); reg.sp++; reg.d=mmu_rb(reg.sp); reg.sp++; reg.m=3; }
void POPHL() {reg.l=mmu_rb(reg.sp); reg.sp++; reg.h=mmu_rb(reg.sp); reg.sp++; reg.m=3; }
void POPAF() {reg.f=mmu_rb(reg.sp); reg.sp++; reg.a=mmu_rb(reg.sp); reg.sp++; reg.m=3; }

/*--- Jump ---*/
void JPnn() {reg.pc = mmu_rw(reg.pc); reg.m=3; }
void JPHL() {reg.pc=(reg.h<<8)+reg.l; reg.m=1; }
void JPNZnn() {reg.m=3; if((reg.f&0x80)==0x00) { reg.pc=mmu_rw(reg.pc); reg.m++; } else reg.pc+=2; }
void JPZnn() {reg.m=3; if((reg.f&0x80)==0x80) { reg.pc=mmu_rw(reg.pc); reg.m++; } else reg.pc+=2; }
void JPNCnn() {reg.m=3; if((reg.f&0x10)==0x00) { reg.pc=mmu_rw(reg.pc); reg.m++; } else reg.pc+=2; }
void JPCnn() {reg.m=3; if((reg.f&0x10)==0x10) { reg.pc=mmu_rw(reg.pc); reg.m++; } else reg.pc+=2; }

void JRn() {i=mmu_rb(reg.pc); if(i>127) i=-((~i+1)&255); reg.pc++; reg.m=2; reg.pc+=i; reg.m++; }
void JRNZn() {i=mmu_rb(reg.pc); if(i>127) i=-((~i+1)&255); reg.pc++; reg.m=2; if((reg.f&0x80)==0x00) { reg.pc+=i; reg.m++; } }
void JRZn() {i=mmu_rb(reg.pc); if(i>127) i=-((~i+1)&255); reg.pc++; reg.m=2; if((reg.f&0x80)==0x80) { reg.pc+=i; reg.m++; } }
void JRNCn() {i=mmu_rb(reg.pc); if(i>127) i=-((~i+1)&255); reg.pc++; reg.m=2; if((reg.f&0x10)==0x00) { reg.pc+=i; reg.m++; } }
void JRCn() {i=mmu_rb(reg.pc); if(i>127) i=-((~i+1)&255); reg.pc++; reg.m=2; if((reg.f&0x10)==0x10) { reg.pc+=i; reg.m++; } }

void DJNZn() {i=mmu_rb(reg.pc); if(i>127) i=-((~i+1)&255); reg.pc++; reg.m=2; reg.b--; if(reg.b) { reg.pc+=i; reg.m++; } }

void CALLnn() {reg.sp-=2; mmu_ww(reg.sp,reg.pc+2); reg.pc=mmu_rw(reg.pc); reg.m=5; }
void CALLNZnn() {reg.m=3; if((reg.f&0x80)==0x00) { reg.sp-=2; mmu_ww(reg.sp,reg.pc+2); reg.pc=mmu_rw(reg.pc); reg.m+=2; } else reg.pc+=2; }
void CALLZnn() {reg.m=3; if((reg.f&0x80)==0x80) { reg.sp-=2; mmu_ww(reg.sp,reg.pc+2); reg.pc=mmu_rw(reg.pc); reg.m+=2; } else reg.pc+=2; }
void CALLNCnn() {reg.m=3; if((reg.f&0x10)==0x00) { reg.sp-=2; mmu_ww(reg.sp,reg.pc+2); reg.pc=mmu_rw(reg.pc); reg.m+=2; } else reg.pc+=2; }
void CALLCnn() {reg.m=3; if((reg.f&0x10)==0x10) { reg.sp-=2; mmu_ww(reg.sp,reg.pc+2); reg.pc=mmu_rw(reg.pc); reg.m+=2; } else reg.pc+=2; }

void RET() {reg.pc=mmu_rw(reg.sp); reg.sp+=2; reg.m=3; }
void RETI() {reg.ime=1; reg.a=rsv.a;reg.b=rsv.b;reg.c=rsv.c;reg.d=rsv.d;reg.e=rsv.e;reg.f=rsv.f;reg.h=rsv.h;reg.l=rsv.l; reg.pc=mmu_rw(reg.sp); reg.sp+=2; reg.m=3; }
void RETNZ() {reg.m=1; if((reg.f&0x80)==0x00) { reg.pc=mmu_rw(reg.sp); reg.sp+=2; reg.m+=2; } }
void RETZ() {reg.m=1; if((reg.f&0x80)==0x80) { reg.pc=mmu_rw(reg.sp); reg.sp+=2; reg.m+=2; } }
void RETNC() {reg.m=1; if((reg.f&0x10)==0x00) { reg.pc=mmu_rw(reg.sp); reg.sp+=2; reg.m+=2; } }
void RETC() {reg.m=1; if((reg.f&0x10)==0x10) { reg.pc=mmu_rw(reg.sp); reg.sp+=2; reg.m+=2; } }

void RST00() {rsv.a=reg.a;rsv.b=reg.b;rsv.c=reg.c;rsv.d=reg.d;rsv.e=reg.e;rsv.f=reg.f;rsv.h=reg.h;rsv.l=reg.l; reg.sp-=2; mmu_ww(reg.sp,reg.pc); reg.pc=0x00; reg.m=3; }
void RST08() {rsv.a=reg.a;rsv.b=reg.b;rsv.c=reg.c;rsv.d=reg.d;rsv.e=reg.e;rsv.f=reg.f;rsv.h=reg.h;rsv.l=reg.l; reg.sp-=2; mmu_ww(reg.sp,reg.pc); reg.pc=0x08; reg.m=3; }
void RST10() {rsv.a=reg.a;rsv.b=reg.b;rsv.c=reg.c;rsv.d=reg.d;rsv.e=reg.e;rsv.f=reg.f;rsv.h=reg.h;rsv.l=reg.l; reg.sp-=2; mmu_ww(reg.sp,reg.pc); reg.pc=0x10; reg.m=3; }
void RST18() {rsv.a=reg.a;rsv.b=reg.b;rsv.c=reg.c;rsv.d=reg.d;rsv.e=reg.e;rsv.f=reg.f;rsv.h=reg.h;rsv.l=reg.l; reg.sp-=2; mmu_ww(reg.sp,reg.pc); reg.pc=0x18; reg.m=3; }
void RST20() {rsv.a=reg.a;rsv.b=reg.b;rsv.c=reg.c;rsv.d=reg.d;rsv.e=reg.e;rsv.f=reg.f;rsv.h=reg.h;rsv.l=reg.l; reg.sp-=2; mmu_ww(reg.sp,reg.pc); reg.pc=0x20; reg.m=3; }
void RST28() {rsv.a=reg.a;rsv.b=reg.b;rsv.c=reg.c;rsv.d=reg.d;rsv.e=reg.e;rsv.f=reg.f;rsv.h=reg.h;rsv.l=reg.l; reg.sp-=2; mmu_ww(reg.sp,reg.pc); reg.pc=0x28; reg.m=3; }
void RST30() {rsv.a=reg.a;rsv.b=reg.b;rsv.c=reg.c;rsv.d=reg.d;rsv.e=reg.e;rsv.f=reg.f;rsv.h=reg.h;rsv.l=reg.l; reg.sp-=2; mmu_ww(reg.sp,reg.pc); reg.pc=0x30; reg.m=3; }
void RST38() {rsv.a=reg.a;rsv.b=reg.b;rsv.c=reg.c;rsv.d=reg.d;rsv.e=reg.e;rsv.f=reg.f;rsv.h=reg.h;rsv.l=reg.l; reg.sp-=2; mmu_ww(reg.sp,reg.pc); reg.pc=0x38; reg.m=3; }

void RST40() {rsv.a=reg.a;rsv.b=reg.b;rsv.c=reg.c;rsv.d=reg.d;rsv.e=reg.e;rsv.f=reg.f;rsv.h=reg.h;rsv.l=reg.l; reg.sp-=2; mmu_ww(reg.sp,reg.pc); reg.pc=0x40; reg.m=3; }
/*
void RST48() {rsv.a=reg.a;rsv.b=reg.b;rsv.c=reg.c;rsv.d=reg.d;rsv.e=reg.e;rsv.f=reg.f;rsv.h=reg.h;rsv.l=reg.l; reg.sp-=2; mmu_ww(reg.sp,reg.pc); reg.pc=0x48; reg.m=3; }
void RST50() {rsv.a=reg.a;rsv.b=reg.b;rsv.c=reg.c;rsv.d=reg.d;rsv.e=reg.e;rsv.f=reg.f;rsv.h=reg.h;rsv.l=reg.l; reg.sp-=2; mmu_ww(reg.sp,reg.pc); reg.pc=0x50; reg.m=3; }
void RST58() {rsv.a=reg.a;rsv.b=reg.b;rsv.c=reg.c;rsv.d=reg.d;rsv.e=reg.e;rsv.f=reg.f;rsv.h=reg.h;rsv.l=reg.l; reg.sp-=2; mmu_ww(reg.sp,reg.pc); reg.pc=0x58; reg.m=3; }
void RST60() {rsv.a=reg.a;rsv.b=reg.b;rsv.c=reg.c;rsv.d=reg.d;rsv.e=reg.e;rsv.f=reg.f;rsv.h=reg.h;rsv.l=reg.l; reg.sp-=2; mmu_ww(reg.sp,reg.pc); reg.pc=0x60; reg.m=3; }
*/

void NOP() {reg.m=1; }
void HALT() {halt=1; reg.m=1; }

void DI() {reg.ime=0; reg.m=1; }
void EI() {reg.ime=1; reg.m=1; }

void XX() {stop=1; }
