// Data processing
case ADDr_b:  a=reg.a; reg.a+=reg.b; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.b^a)&0x10) reg.f|=0x20; reg.m=1; break;
case ADDr_c:  a=reg.a; reg.a+=reg.c; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.c^a)&0x10) reg.f|=0x20; reg.m=1; break;
case ADDr_d:  a=reg.a; reg.a+=reg.d; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.d^a)&0x10) reg.f|=0x20; reg.m=1; break;
case ADDr_e:  a=reg.a; reg.a+=reg.e; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.e^a)&0x10) reg.f|=0x20; reg.m=1; break;
case ADDr_h:  a=reg.a; reg.a+=reg.h; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.h^a)&0x10) reg.f|=0x20; reg.m=1; break;
case ADDr_l:  a=reg.a; reg.a+=reg.l; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.l^a)&0x10) reg.f|=0x20; reg.m=1; break;
case ADDr_a:  a=reg.a; reg.a+=reg.a; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.a^a)&0x10) reg.f|=0x20; reg.m=1; break;
case ADDHL:  a=reg.a; m=mmu_rb((reg.h<<8)+reg.l); reg.a+=m; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^a^m)&0x10) reg.f|=0x20; reg.m=2; break;
case ADDn:  a=reg.a; m=mmu_rb(reg.pc); reg.a+=m; reg.pc++; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^a^m)&0x10) reg.f|=0x20; reg.m=2; break;
case ADDHLBC:  hl=(reg.h<<8)+reg.l; hl+=(reg.b<<8)+reg.c; if(hl>65535) reg.f|=0x10; else reg.f&=0xEF; reg.h=(hl>>8)&255; reg.l=hl&255; reg.m=3; break;
case ADDHLDE:  hl=(reg.h<<8)+reg.l; hl+=(reg.d<<8)+reg.e; if(hl>65535) reg.f|=0x10; else reg.f&=0xEF; reg.h=(hl>>8)&255; reg.l=hl&255; reg.m=3; break;
case ADDHLHL:  hl=(reg.h<<8)+reg.l; hl+=(reg.h<<8)+reg.l; if(hl>65535) reg.f|=0x10; else reg.f&=0xEF; reg.h=(hl>>8)&255; reg.l=hl&255; reg.m=3; break;
case ADDHLSP:  hl=(reg.h<<8)+reg.l; hl+=reg.sp; if(hl>65535) reg.f|=0x10; else reg.f&=0xEF; reg.h=(hl>>8)&255; reg.l=hl&255; reg.m=3; break;
case ADDSPn:  i=mmu_rb(reg.pc); if(i>127) i=-((~i+1)&255); reg.pc++; reg.sp+=i; reg.m=4; break;

case ADCr_b:  a=reg.a; reg.a+=reg.b; reg.a+=(reg.f&0x10)?1:0; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.b^a)&0x10) reg.f|=0x20; reg.m=1; break;
case ADCr_c:  a=reg.a; reg.a+=reg.c; reg.a+=(reg.f&0x10)?1:0; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.c^a)&0x10) reg.f|=0x20; reg.m=1; break;
case ADCr_d:  a=reg.a; reg.a+=reg.d; reg.a+=(reg.f&0x10)?1:0; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.d^a)&0x10) reg.f|=0x20; reg.m=1; break;
case ADCr_e:  a=reg.a; reg.a+=reg.e; reg.a+=(reg.f&0x10)?1:0; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.e^a)&0x10) reg.f|=0x20; reg.m=1; break;
case ADCr_h:  a=reg.a; reg.a+=reg.h; reg.a+=(reg.f&0x10)?1:0; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.h^a)&0x10) reg.f|=0x20; reg.m=1; break;
case ADCr_l:  a=reg.a; reg.a+=reg.l; reg.a+=(reg.f&0x10)?1:0; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.l^a)&0x10) reg.f|=0x20; reg.m=1; break;
case ADCr_a:  a=reg.a; reg.a+=reg.a; reg.a+=(reg.f&0x10)?1:0; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.a^a)&0x10) reg.f|=0x20; reg.m=1; break;
case ADCHL:  a=reg.a; m=mmu_rb((reg.h<<8)+reg.l); reg.a+=m; reg.a+=(reg.f&0x10)?1:0; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^m^a)&0x10) reg.f|=0x20; reg.m=2; break;
case ADCn:  a=reg.a; m=mmu_rb(reg.pc); reg.a+=m; reg.pc++; reg.a+=(reg.f&0x10)?1:0; reg.f=(reg.a>255)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^m^a)&0x10) reg.f|=0x20; reg.m=2; break;

case SUBr_b:  a=reg.a; reg.a-=reg.b; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.b^a)&0x10) reg.f|=0x20; reg.m=1; break;
case SUBr_c:  a=reg.a; reg.a-=reg.c; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.c^a)&0x10) reg.f|=0x20; reg.m=1; break;
case SUBr_d:  a=reg.a; reg.a-=reg.d; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.d^a)&0x10) reg.f|=0x20; reg.m=1; break;
case SUBr_e:  a=reg.a; reg.a-=reg.e; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.e^a)&0x10) reg.f|=0x20; reg.m=1; break;
case SUBr_h:  a=reg.a; reg.a-=reg.h; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.h^a)&0x10) reg.f|=0x20; reg.m=1; break;
case SUBr_l:  a=reg.a; reg.a-=reg.l; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.l^a)&0x10) reg.f|=0x20; reg.m=1; break;
case SUBr_a:  a=reg.a; reg.a-=reg.a; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.a^a)&0x10) reg.f|=0x20; reg.m=1; break;
case SUBHL:  a=reg.a; m=mmu_rb((reg.h<<8)+reg.l); reg.a-=m; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^m^a)&0x10) reg.f|=0x20; reg.m=2; break;
case SUBn:  a=reg.a; m=mmu_rb(reg.pc); reg.a-=m; reg.pc++; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^m^a)&0x10) reg.f|=0x20; reg.m=2; break;

case SBCr_b:  a=reg.a; reg.a-=reg.b; reg.a-=(reg.f&0x10)?1:0; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.b^a)&0x10) reg.f|=0x20; reg.m=1; break;
case SBCr_c:  a=reg.a; reg.a-=reg.c; reg.a-=(reg.f&0x10)?1:0; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.c^a)&0x10) reg.f|=0x20; reg.m=1; break;
case SBCr_d:  a=reg.a; reg.a-=reg.d; reg.a-=(reg.f&0x10)?1:0; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.d^a)&0x10) reg.f|=0x20; reg.m=1; break;
case SBCr_e:  a=reg.a; reg.a-=reg.e; reg.a-=(reg.f&0x10)?1:0; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.e^a)&0x10) reg.f|=0x20; reg.m=1; break;
case SBCr_h:  a=reg.a; reg.a-=reg.h; reg.a-=(reg.f&0x10)?1:0; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.h^a)&0x10) reg.f|=0x20; reg.m=1; break;
case SBCr_l:  a=reg.a; reg.a-=reg.l; reg.a-=(reg.f&0x10)?1:0; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.l^a)&0x10) reg.f|=0x20; reg.m=1; break;
case SBCr_a:  a=reg.a; reg.a-=reg.a; reg.a-=(reg.f&0x10)?1:0; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^reg.a^a)&0x10) reg.f|=0x20; reg.m=1; break;
case SBCHL:  a=reg.a; m=mmu_rb((reg.h<<8)+reg.l); reg.a-=m; reg.a-=(reg.f&0x10)?1:0; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^m^a)&0x10) reg.f|=0x20; reg.m=2; break;
case SBCn:  a=reg.a; m=mmu_rb(reg.pc); reg.a-=m; reg.pc++; reg.a-=(reg.f&0x10)?1:0; reg.f=(reg.a<0)?0x50:0x40; reg.a&=255; if(!reg.a) reg.f|=0x80; if((reg.a^m^a)&0x10) reg.f|=0x20; reg.m=2; break;

case CPr_b:  i=reg.a; i-=reg.b; reg.f=(i<0)?0x50:0x40; i&=255; if(!i) reg.f|=0x80; if((reg.a^reg.b^i)&0x10) reg.f|=0x20; reg.m=1; break;
case CPr_c:  i=reg.a; i-=reg.c; reg.f=(i<0)?0x50:0x40; i&=255; if(!i) reg.f|=0x80; if((reg.a^reg.c^i)&0x10) reg.f|=0x20; reg.m=1; break;
case CPr_d:  i=reg.a; i-=reg.d; reg.f=(i<0)?0x50:0x40; i&=255; if(!i) reg.f|=0x80; if((reg.a^reg.d^i)&0x10) reg.f|=0x20; reg.m=1; break;
case CPr_e:  i=reg.a; i-=reg.e; reg.f=(i<0)?0x50:0x40; i&=255; if(!i) reg.f|=0x80; if((reg.a^reg.e^i)&0x10) reg.f|=0x20; reg.m=1; break;
case CPr_h:  i=reg.a; i-=reg.h; reg.f=(i<0)?0x50:0x40; i&=255; if(!i) reg.f|=0x80; if((reg.a^reg.h^i)&0x10) reg.f|=0x20; reg.m=1; break;
case CPr_l:  i=reg.a; i-=reg.l; reg.f=(i<0)?0x50:0x40; i&=255; if(!i) reg.f|=0x80; if((reg.a^reg.l^i)&0x10) reg.f|=0x20; reg.m=1; break;
case CPr_a:  i=reg.a; i-=reg.a; reg.f=(i<0)?0x50:0x40; i&=255; if(!i) reg.f|=0x80; if((reg.a^reg.a^i)&0x10) reg.f|=0x20; reg.m=1; break;
case CPHL:  i=reg.a; m=mmu_rb((reg.h<<8)+reg.l); i-=m; reg.f=(i<0)?0x50:0x40; i&=255; if(!i) reg.f|=0x80; if((reg.a^i^m)&0x10) reg.f|=0x20; reg.m=2; break;
case CPn:  i=reg.a; m=mmu_rb(reg.pc); i-=m; reg.pc++; reg.f=(i<0)?0x50:0x40; i&=255; if(!i) reg.f|=0x80; if((reg.a^i^m)&0x10) reg.f|=0x20; reg.m=2; break;

case DAA:  a=reg.a; if((reg.f&0x20)||((reg.a&15)>9)) reg.a+=6; reg.f&=0xEF; if((reg.f&0x20)||(a>0x99)) { reg.a+=0x60; reg.f|=0x10; } reg.m=1; break;

case ANDr_b:  reg.a&=reg.b; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case ANDr_c:  reg.a&=reg.c; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case ANDr_d:  reg.a&=reg.d; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case ANDr_e:  reg.a&=reg.e; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case ANDr_h:  reg.a&=reg.h; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case ANDr_l:  reg.a&=reg.l; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case ANDr_a:  reg.a&=reg.a; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case ANDHL:  reg.a&=mmu_rb((reg.h<<8)+reg.l); reg.a&=255; reg.f=reg.a?0:0x80; reg.m=2; break;
case ANDn:  reg.a&=mmu_rb(reg.pc); reg.pc++; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=2; break;

case ORr_b:  reg.a|=reg.b; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case ORr_c:  reg.a|=reg.c; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case ORr_d:  reg.a|=reg.d; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case ORr_e:  reg.a|=reg.e; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case ORr_h:  reg.a|=reg.h; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case ORr_l:  reg.a|=reg.l; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case ORr_a:  reg.a|=reg.a; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case ORHL:  reg.a|=mmu_rb((reg.h<<8)+reg.l); reg.a&=255; reg.f=reg.a?0:0x80; reg.m=2; break;
case ORn:  reg.a|=mmu_rb(reg.pc); reg.pc++; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=2; break;

case XORr_b:  reg.a^=reg.b; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case XORr_c:  reg.a^=reg.c; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case XORr_d:  reg.a^=reg.d; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case XORr_e:  reg.a^=reg.e; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case XORr_h:  reg.a^=reg.h; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case XORr_l:  reg.a^=reg.l; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case XORr_a:  reg.a^=reg.a; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case XORHL:  reg.a^=mmu_rb((reg.h<<8)+reg.l); reg.a&=255; reg.f=reg.a?0:0x80; reg.m=2; break;
case XORn:  reg.a^=mmu_rb(reg.pc); reg.pc++; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=2; break;

case INCr_b:  reg.b++; reg.b&=255; reg.f=reg.b?0:0x80; reg.m=1; break;
case INCr_c:  reg.c++; reg.c&=255; reg.f=reg.c?0:0x80; reg.m=1; break;
case INCr_d:  reg.d++; reg.d&=255; reg.f=reg.d?0:0x80; reg.m=1; break;
case INCr_e:  reg.e++; reg.e&=255; reg.f=reg.e?0:0x80; reg.m=1; break;
case INCr_h:  reg.h++; reg.h&=255; reg.f=reg.h?0:0x80; reg.m=1; break;
case INCr_l:  reg.l++; reg.l&=255; reg.f=reg.l?0:0x80; reg.m=1; break;
case INCr_a:  reg.a++; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case INCHLm:  i=mmu_rb((reg.h<<8)+reg.l)+1; i&=255; mmu_wb((reg.h<<8)+reg.l,i); reg.f=i?0:0x80; reg.m=3; break;

case DECr_b:  reg.b--; reg.b&=255; reg.f=reg.b?0:0x80; reg.m=1; break;
case DECr_c:  reg.c--; reg.c&=255; reg.f=reg.c?0:0x80; reg.m=1; break;
case DECr_d:  reg.d--; reg.d&=255; reg.f=reg.d?0:0x80; reg.m=1; break;
case DECr_e:  reg.e--; reg.e&=255; reg.f=reg.e?0:0x80; reg.m=1; break;
case DECr_h:  reg.h--; reg.h&=255; reg.f=reg.h?0:0x80; reg.m=1; break;
case DECr_l:  reg.l--; reg.l&=255; reg.f=reg.l?0:0x80; reg.m=1; break;
case DECr_a:  reg.a--; reg.a&=255; reg.f=reg.a?0:0x80; reg.m=1; break;
case DECHLm:  i=mmu_rb((reg.h<<8)+reg.l)-1; i&=255; mmu_wb((reg.h<<8)+reg.l,i); reg.f=i?0:0x80; reg.m=3; break;

case INCBC:  reg.c=(reg.c+1)&255; if(!reg.c) reg.b=(reg.b+1)&255; reg.m=1; break;
case INCDE:  reg.e=(reg.e+1)&255; if(!reg.e) reg.d=(reg.d+1)&255; reg.m=1; break;
case INCHL:  reg.l=(reg.l+1)&255; if(!reg.l) reg.h=(reg.h+1)&255; reg.m=1; break;
case INCSP:  reg.sp=(reg.sp+1)&65535; reg.m=1; break;

case DECBC:  reg.c=(reg.c-1)&255; if(reg.c==255) reg.b=(reg.b-1)&255; reg.m=1; break;
case DECDE:  reg.e=(reg.e-1)&255; if(reg.e==255) reg.d=(reg.d-1)&255; reg.m=1; break;
case DECHL:  reg.l=(reg.l-1)&255; if(reg.l==255) reg.h=(reg.h-1)&255; reg.m=1; break;
case DECSP:  reg.sp=(reg.sp-1)&65535; reg.m=1; break;
