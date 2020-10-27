// Load/store
void LDrr_bb() {reg.b=reg.b; reg.m=1; }
void LDrr_bc() {reg.b=reg.c; reg.m=1; }
void LDrr_bd() {reg.b=reg.d; reg.m=1; }
void LDrr_be() {reg.b=reg.e; reg.m=1; }
void LDrr_bh() {reg.b=reg.h; reg.m=1; }
void LDrr_bl() {reg.b=reg.l; reg.m=1; }
void LDrr_ba() {reg.b=reg.a; reg.m=1; }
void LDrr_cb() {reg.c=reg.b; reg.m=1; }
void LDrr_cc() {reg.c=reg.c; reg.m=1; }
void LDrr_cd() {reg.c=reg.d; reg.m=1; }
void LDrr_ce() {reg.c=reg.e; reg.m=1; }
void LDrr_ch() {reg.c=reg.h; reg.m=1; }
void LDrr_cl() {reg.c=reg.l; reg.m=1; }
void LDrr_ca() {reg.c=reg.a; reg.m=1; }
void LDrr_db() {reg.d=reg.b; reg.m=1; }
void LDrr_dc() {reg.d=reg.c; reg.m=1; }
void LDrr_dd() {reg.d=reg.d; reg.m=1; }
void LDrr_de() {reg.d=reg.e; reg.m=1; }
void LDrr_dh() {reg.d=reg.h; reg.m=1; }
void LDrr_dl() {reg.d=reg.l; reg.m=1; }
void LDrr_da() {reg.d=reg.a; reg.m=1; }
void LDrr_eb() {reg.e=reg.b; reg.m=1; }
void LDrr_ec() {reg.e=reg.c; reg.m=1; }
void LDrr_ed() {reg.e=reg.d; reg.m=1; }
void LDrr_ee() {reg.e=reg.e; reg.m=1; }
void LDrr_eh() {reg.e=reg.h; reg.m=1; }
void LDrr_el() {reg.e=reg.l; reg.m=1; }
void LDrr_ea() {reg.e=reg.a; reg.m=1; }
void LDrr_hb() {reg.h=reg.b; reg.m=1; }
void LDrr_hc() {reg.h=reg.c; reg.m=1; }
void LDrr_hd() {reg.h=reg.d; reg.m=1; }
void LDrr_he() {reg.h=reg.e; reg.m=1; }
void LDrr_hh() {reg.h=reg.h; reg.m=1; }
void LDrr_hl() {reg.h=reg.l; reg.m=1; }
void LDrr_ha() {reg.h=reg.a; reg.m=1; }
void LDrr_lb() {reg.l=reg.b; reg.m=1; }
void LDrr_lc() {reg.l=reg.c; reg.m=1; }
void LDrr_ld() {reg.l=reg.d; reg.m=1; }
void LDrr_le() {reg.l=reg.e; reg.m=1; }
void LDrr_lh() {reg.l=reg.h; reg.m=1; }
void LDrr_ll() {reg.l=reg.l; reg.m=1; }
void LDrr_la() {reg.l=reg.a; reg.m=1; }
void LDrr_ab() {reg.a=reg.b; reg.m=1; }
void LDrr_ac() {reg.a=reg.c; reg.m=1; }
void LDrr_ad() {reg.a=reg.d; reg.m=1; }
void LDrr_ae() {reg.a=reg.e; reg.m=1; }
void LDrr_ah() {reg.a=reg.h; reg.m=1; }
void LDrr_al() {reg.a=reg.l; reg.m=1; }
void LDrr_aa() {reg.a=reg.a; reg.m=1; }

void LDrHLm_b() {reg.b=mmu_rb((reg.h<<8)+reg.l); reg.m=2; }
void LDrHLm_c() {reg.c=mmu_rb((reg.h<<8)+reg.l); reg.m=2; }
void LDrHLm_d() {reg.d=mmu_rb((reg.h<<8)+reg.l); reg.m=2; }
void LDrHLm_e() {reg.e=mmu_rb((reg.h<<8)+reg.l); reg.m=2; }
void LDrHLm_h() {reg.h=mmu_rb((reg.h<<8)+reg.l); reg.m=2; }
void LDrHLm_l() {reg.l=mmu_rb((reg.h<<8)+reg.l); reg.m=2; }
void LDrHLm_a() {reg.a=mmu_rb((reg.h<<8)+reg.l); reg.m=2; }

void LDHLmr_b() {mmu_wb((reg.h<<8)+reg.l,reg.b); reg.m=2; }
void LDHLmr_c() {mmu_wb((reg.h<<8)+reg.l,reg.c); reg.m=2; }
void LDHLmr_d() {mmu_wb((reg.h<<8)+reg.l,reg.d); reg.m=2; }
void LDHLmr_e() {mmu_wb((reg.h<<8)+reg.l,reg.e); reg.m=2; }
void LDHLmr_h() {mmu_wb((reg.h<<8)+reg.l,reg.h); reg.m=2; }
void LDHLmr_l() {mmu_wb((reg.h<<8)+reg.l,reg.l); reg.m=2; }
void LDHLmr_a() {mmu_wb((reg.h<<8)+reg.l,reg.a); reg.m=2; }

void LDrn_b() {reg.b=mmu_rb(reg.pc); reg.pc++; reg.m=2; }
void LDrn_c() {reg.c=mmu_rb(reg.pc); reg.pc++; reg.m=2; }
void LDrn_d() {reg.d=mmu_rb(reg.pc); reg.pc++; reg.m=2; }
void LDrn_e() {reg.e=mmu_rb(reg.pc); reg.pc++; reg.m=2; }
void LDrn_h() {reg.h=mmu_rb(reg.pc); reg.pc++; reg.m=2; }
void LDrn_l() {reg.l=mmu_rb(reg.pc); reg.pc++; reg.m=2; }
void LDrn_a() {reg.a=mmu_rb(reg.pc); reg.pc++; reg.m=2; }

void LDHLmn() {mmu_wb((reg.h<<8)+reg.l, mmu_rb(reg.pc)); reg.pc++; reg.m=3; }

void LDBCmA() {mmu_wb((reg.b<<8)+reg.c, reg.a); reg.m=2; }
void LDDEmA() {mmu_wb((reg.d<<8)+reg.e, reg.a); reg.m=2; }

void LDmmA() {mmu_wb(mmu_rw(reg.pc), reg.a); reg.pc+=2; reg.m=4; }

void LDABCm() {reg.a=mmu_rb((reg.b<<8)+reg.c); reg.m=2; }
void LDADEm() {reg.a=mmu_rb((reg.d<<8)+reg.e); reg.m=2; }

void LDAmm() {reg.a=mmu_rb(mmu_rw(reg.pc)); reg.pc+=2; reg.m=4; }

void LDBCnn() {reg.c=mmu_rb(reg.pc); reg.b=mmu_rb(reg.pc+1); reg.pc+=2; reg.m=3; }
void LDDEnn() {reg.e=mmu_rb(reg.pc); reg.d=mmu_rb(reg.pc+1); reg.pc+=2; reg.m=3; }
void LDHLnn() {reg.l=mmu_rb(reg.pc); reg.h=mmu_rb(reg.pc+1); reg.pc+=2; reg.m=3; }
void LDSPnn() {reg.sp=mmu_rw(reg.pc); reg.pc+=2; reg.m=3; }

/*
void LDHLmm() {i=mmu_rw(reg.pc); reg.pc+=2; reg.l=mmu_rb(i); reg.h=mmu_rb(i+1); reg.m=5; }
void LDmmHL() {i=mmu_rw(reg.pc); reg.pc+=2; mmu_ww(i,(reg.h<<8)+reg.l); reg.m=5; }
*/

void LDHLIA() {mmu_wb((reg.h<<8)+reg.l, reg.a); reg.l=(reg.l+1)&255; if(!reg.l) reg.h=(reg.h+1)&255; reg.m=2; }
void LDAHLI() {reg.a=mmu_rb((reg.h<<8)+reg.l); reg.l=(reg.l+1)&255; if(!reg.l) reg.h=(reg.h+1)&255; reg.m=2; }

void LDHLDA() {mmu_wb((reg.h<<8)+reg.l, reg.a); reg.l=(reg.l-1)&255; if(reg.l==255) reg.h=(reg.h-1)&255; reg.m=2; }
void LDAHLD() {reg.a=mmu_rb((reg.h<<8)+reg.l); reg.l=(reg.l-1)&255; if(reg.l==255) reg.h=(reg.h-1)&255; reg.m=2; }

void LDAIOn() {reg.a=mmu_rb(0xFF00+mmu_rb(reg.pc)); reg.pc++; reg.m=3; }
void LDIOnA() {mmu_wb(0xFF00+mmu_rb(reg.pc),reg.a); reg.pc++; reg.m=3; }
void LDAIOC() {reg.a=mmu_rb(0xFF00+reg.c); reg.m=2; }
void LDIOCA() {mmu_wb(0xFF00+reg.c,reg.a); reg.m=2; }

void LDHLSPn() {i=mmu_rb(reg.pc); if(i>127) i=-((~i+1)&255); reg.pc++; i+=reg.sp; reg.h=(i>>8)&255; reg.l=i&255; reg.m=3; }

void SWAPr_b() {tr=reg.b; reg.b=((tr&0xF)<<4)|((tr&0xF0)>>4); reg.f=reg.b?0:0x80; reg.m=1; }
void SWAPr_c() {tr=reg.c; reg.c=((tr&0xF)<<4)|((tr&0xF0)>>4); reg.f=reg.c?0:0x80; reg.m=1; }
void SWAPr_d() {tr=reg.d; reg.d=((tr&0xF)<<4)|((tr&0xF0)>>4); reg.f=reg.d?0:0x80; reg.m=1; }
void SWAPr_e() {tr=reg.e; reg.e=((tr&0xF)<<4)|((tr&0xF0)>>4); reg.f=reg.e?0:0x80; reg.m=1; }
void SWAPr_h() {tr=reg.h; reg.h=((tr&0xF)<<4)|((tr&0xF0)>>4); reg.f=reg.h?0:0x80; reg.m=1; }
void SWAPr_l() {tr=reg.l; reg.l=((tr&0xF)<<4)|((tr&0xF0)>>4); reg.f=reg.l?0:0x80; reg.m=1; }
void SWAPr_a() {tr=reg.a; reg.a=((tr&0xF)<<4)|((tr&0xF0)>>4); reg.f=reg.a?0:0x80; reg.m=1; }
