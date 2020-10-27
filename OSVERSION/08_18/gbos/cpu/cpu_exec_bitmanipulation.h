// Bit manipulation
void BIT0b() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x01)?0:0x80; reg.m=2; }
void BIT0c() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x01)?0:0x80; reg.m=2; }
void BIT0d() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x01)?0:0x80; reg.m=2; }
void BIT0e() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x01)?0:0x80; reg.m=2; }
void BIT0h() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x01)?0:0x80; reg.m=2; }
void BIT0l() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x01)?0:0x80; reg.m=2; }
void BIT0a() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x01)?0:0x80; reg.m=2; }
void BIT0m() {reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x01)?0:0x80; reg.m=3; }

void RES0b() {reg.b&=0xFE; reg.m=2; }
void RES0c() {reg.c&=0xFE; reg.m=2; }
void RES0d() {reg.d&=0xFE; reg.m=2; }
void RES0e() {reg.e&=0xFE; reg.m=2; }
void RES0h() {reg.h&=0xFE; reg.m=2; }
void RES0l() {reg.l&=0xFE; reg.m=2; }
void RES0a() {reg.a&=0xFE; reg.m=2; }
void RES0m() {i=mmu_rb((reg.h<<8)+reg.l); i&=0xFE; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void SET0b() {reg.b|=0x01; reg.m=2; }
void SET0c() {reg.b|=0x01; reg.m=2; }
void SET0d() {reg.b|=0x01; reg.m=2; }
void SET0e() {reg.b|=0x01; reg.m=2; }
void SET0h() {reg.b|=0x01; reg.m=2; }
void SET0l() {reg.b|=0x01; reg.m=2; }
void SET0a() {reg.b|=0x01; reg.m=2; }
void SET0m() {i=mmu_rb((reg.h<<8)+reg.l); i|=0x01; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void BIT1b() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x02)?0:0x80; reg.m=2; }
void BIT1c() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x02)?0:0x80; reg.m=2; }
void BIT1d() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x02)?0:0x80; reg.m=2; }
void BIT1e() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x02)?0:0x80; reg.m=2; }
void BIT1h() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x02)?0:0x80; reg.m=2; }
void BIT1l() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x02)?0:0x80; reg.m=2; }
void BIT1a() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x02)?0:0x80; reg.m=2; }
void BIT1m() {reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x02)?0:0x80; reg.m=3; }

void RES1b() {reg.b&=0xFD; reg.m=2; }
void RES1c() {reg.c&=0xFD; reg.m=2; }
void RES1d() {reg.d&=0xFD; reg.m=2; }
void RES1e() {reg.e&=0xFD; reg.m=2; }
void RES1h() {reg.h&=0xFD; reg.m=2; }
void RES1l() {reg.l&=0xFD; reg.m=2; }
void RES1a() {reg.a&=0xFD; reg.m=2; }
void RES1m() {i=mmu_rb((reg.h<<8)+reg.l); i&=0xFD; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void SET1b() {reg.b|=0x02; reg.m=2; }
void SET1c() {reg.b|=0x02; reg.m=2; }
void SET1d() {reg.b|=0x02; reg.m=2; }
void SET1e() {reg.b|=0x02; reg.m=2; }
void SET1h() {reg.b|=0x02; reg.m=2; }
void SET1l() {reg.b|=0x02; reg.m=2; }
void SET1a() {reg.b|=0x02; reg.m=2; }
void SET1m() {i=mmu_rb((reg.h<<8)+reg.l); i|=0x02; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void BIT2b() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x04)?0:0x80; reg.m=2; }
void BIT2c() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x04)?0:0x80; reg.m=2; }
void BIT2d() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x04)?0:0x80; reg.m=2; }
void BIT2e() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x04)?0:0x80; reg.m=2; }
void BIT2h() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x04)?0:0x80; reg.m=2; }
void BIT2l() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x04)?0:0x80; reg.m=2; }
void BIT2a() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x04)?0:0x80; reg.m=2; }
void BIT2m() {reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x04)?0:0x80; reg.m=3; }

void RES2b() {reg.b&=0xFB; reg.m=2; }
void RES2c() {reg.c&=0xFB; reg.m=2; }
void RES2d() {reg.d&=0xFB; reg.m=2; }
void RES2e() {reg.e&=0xFB; reg.m=2; }
void RES2h() {reg.h&=0xFB; reg.m=2; }
void RES2l() {reg.l&=0xFB; reg.m=2; }
void RES2a() {reg.a&=0xFB; reg.m=2; }
void RES2m() {i=mmu_rb((reg.h<<8)+reg.l); i&=0xFB; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void SET2b() {reg.b|=0x04; reg.m=2; }
void SET2c() {reg.b|=0x04; reg.m=2; }
void SET2d() {reg.b|=0x04; reg.m=2; }
void SET2e() {reg.b|=0x04; reg.m=2; }
void SET2h() {reg.b|=0x04; reg.m=2; }
void SET2l() {reg.b|=0x04; reg.m=2; }
void SET2a() {reg.b|=0x04; reg.m=2; }
void SET2m() {i=mmu_rb((reg.h<<8)+reg.l); i|=0x04; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void BIT3b() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x08)?0:0x80; reg.m=2; }
void BIT3c() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x08)?0:0x80; reg.m=2; }
void BIT3d() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x08)?0:0x80; reg.m=2; }
void BIT3e() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x08)?0:0x80; reg.m=2; }
void BIT3h() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x08)?0:0x80; reg.m=2; }
void BIT3l() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x08)?0:0x80; reg.m=2; }
void BIT3a() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x08)?0:0x80; reg.m=2; }
void BIT3m() {reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x08)?0:0x80; reg.m=3; }

void RES3b() {reg.b&=0xF7; reg.m=2; }
void RES3c() {reg.c&=0xF7; reg.m=2; }
void RES3d() {reg.d&=0xF7; reg.m=2; }
void RES3e() {reg.e&=0xF7; reg.m=2; }
void RES3h() {reg.h&=0xF7; reg.m=2; }
void RES3l() {reg.l&=0xF7; reg.m=2; }
void RES3a() {reg.a&=0xF7; reg.m=2; }
void RES3m() {i=mmu_rb((reg.h<<8)+reg.l); i&=0xF7; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void SET3b() {reg.b|=0x08; reg.m=2; }
void SET3c() {reg.b|=0x08; reg.m=2; }
void SET3d() {reg.b|=0x08; reg.m=2; }
void SET3e() {reg.b|=0x08; reg.m=2; }
void SET3h() {reg.b|=0x08; reg.m=2; }
void SET3l() {reg.b|=0x08; reg.m=2; }
void SET3a() {reg.b|=0x08; reg.m=2; }
void SET3m() {i=mmu_rb((reg.h<<8)+reg.l); i|=0x08; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void BIT4b() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x10)?0:0x80; reg.m=2; }
void BIT4c() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x10)?0:0x80; reg.m=2; }
void BIT4d() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x10)?0:0x80; reg.m=2; }
void BIT4e() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x10)?0:0x80; reg.m=2; }
void BIT4h() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x10)?0:0x80; reg.m=2; }
void BIT4l() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x10)?0:0x80; reg.m=2; }
void BIT4a() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x10)?0:0x80; reg.m=2; }
void BIT4m() {reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x10)?0:0x80; reg.m=3; }

void RES4b() {reg.b&=0xEF; reg.m=2; }
void RES4c() {reg.c&=0xEF; reg.m=2; }
void RES4d() {reg.d&=0xEF; reg.m=2; }
void RES4e() {reg.e&=0xEF; reg.m=2; }
void RES4h() {reg.h&=0xEF; reg.m=2; }
void RES4l() {reg.l&=0xEF; reg.m=2; }
void RES4a() {reg.a&=0xEF; reg.m=2; }
void RES4m() {i=mmu_rb((reg.h<<8)+reg.l); i&=0xEF; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void SET4b() {reg.b|=0x10; reg.m=2; }
void SET4c() {reg.b|=0x10; reg.m=2; }
void SET4d() {reg.b|=0x10; reg.m=2; }
void SET4e() {reg.b|=0x10; reg.m=2; }
void SET4h() {reg.b|=0x10; reg.m=2; }
void SET4l() {reg.b|=0x10; reg.m=2; }
void SET4a() {reg.b|=0x10; reg.m=2; }
void SET4m() {i=mmu_rb((reg.h<<8)+reg.l); i|=0x10; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void BIT5b() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x20)?0:0x80; reg.m=2; }
void BIT5c() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x20)?0:0x80; reg.m=2; }
void BIT5d() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x20)?0:0x80; reg.m=2; }
void BIT5e() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x20)?0:0x80; reg.m=2; }
void BIT5h() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x20)?0:0x80; reg.m=2; }
void BIT5l() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x20)?0:0x80; reg.m=2; }
void BIT5a() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x20)?0:0x80; reg.m=2; }
void BIT5m() {reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x20)?0:0x80; reg.m=3; }

void RES5b() {reg.b&=0xDF; reg.m=2; }
void RES5c() {reg.c&=0xDF; reg.m=2; }
void RES5d() {reg.d&=0xDF; reg.m=2; }
void RES5e() {reg.e&=0xDF; reg.m=2; }
void RES5h() {reg.h&=0xDF; reg.m=2; }
void RES5l() {reg.l&=0xDF; reg.m=2; }
void RES5a() {reg.a&=0xDF; reg.m=2; }
void RES5m() {i=mmu_rb((reg.h<<8)+reg.l); i&=0xDF; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void SET5b() {reg.b|=0x20; reg.m=2; }
void SET5c() {reg.b|=0x20; reg.m=2; }
void SET5d() {reg.b|=0x20; reg.m=2; }
void SET5e() {reg.b|=0x20; reg.m=2; }
void SET5h() {reg.b|=0x20; reg.m=2; }
void SET5l() {reg.b|=0x20; reg.m=2; }
void SET5a() {reg.b|=0x20; reg.m=2; }
void SET5m() {i=mmu_rb((reg.h<<8)+reg.l); i|=0x20; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void BIT6b() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x40)?0:0x80; reg.m=2; }
void BIT6c() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x40)?0:0x80; reg.m=2; }
void BIT6d() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x40)?0:0x80; reg.m=2; }
void BIT6e() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x40)?0:0x80; reg.m=2; }
void BIT6h() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x40)?0:0x80; reg.m=2; }
void BIT6l() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x40)?0:0x80; reg.m=2; }
void BIT6a() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x40)?0:0x80; reg.m=2; }
void BIT6m() {reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x40)?0:0x80; reg.m=3; }

void RES6b() {reg.b&=0xBF; reg.m=2; }
void RES6c() {reg.c&=0xBF; reg.m=2; }
void RES6d() {reg.d&=0xBF; reg.m=2; }
void RES6e() {reg.e&=0xBF; reg.m=2; }
void RES6h() {reg.h&=0xBF; reg.m=2; }
void RES6l() {reg.l&=0xBF; reg.m=2; }
void RES6a() {reg.a&=0xBF; reg.m=2; }
void RES6m() {i=mmu_rb((reg.h<<8)+reg.l); i&=0xBF; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void SET6b() {reg.b|=0x40; reg.m=2; }
void SET6c() {reg.b|=0x40; reg.m=2; }
void SET6d() {reg.b|=0x40; reg.m=2; }
void SET6e() {reg.b|=0x40; reg.m=2; }
void SET6h() {reg.b|=0x40; reg.m=2; }
void SET6l() {reg.b|=0x40; reg.m=2; }
void SET6a() {reg.b|=0x40; reg.m=2; }
void SET6m() {i=mmu_rb((reg.h<<8)+reg.l); i|=0x40; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void BIT7b() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x80)?0:0x80; reg.m=2; }
void BIT7c() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x80)?0:0x80; reg.m=2; }
void BIT7d() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x80)?0:0x80; reg.m=2; }
void BIT7e() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x80)?0:0x80; reg.m=2; }
void BIT7h() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x80)?0:0x80; reg.m=2; }
void BIT7l() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x80)?0:0x80; reg.m=2; }
void BIT7a() {reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x80)?0:0x80; reg.m=2; }
void BIT7m() {reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x80)?0:0x80; reg.m=3; }

void RES7b() {reg.b&=0x7F; reg.m=2; }
void RES7c() {reg.c&=0x7F; reg.m=2; }
void RES7d() {reg.d&=0x7F; reg.m=2; }
void RES7e() {reg.e&=0x7F; reg.m=2; }
void RES7h() {reg.h&=0x7F; reg.m=2; }
void RES7l() {reg.l&=0x7F; reg.m=2; }
void RES7a() {reg.a&=0x7F; reg.m=2; }
void RES7m() {i=mmu_rb((reg.h<<8)+reg.l); i&=0x7F; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void SET7b() {reg.b|=0x80; reg.m=2; }
void SET7c() {reg.b|=0x80; reg.m=2; }
void SET7d() {reg.b|=0x80; reg.m=2; }
void SET7e() {reg.b|=0x80; reg.m=2; }
void SET7h() {reg.b|=0x80; reg.m=2; }
void SET7l() {reg.b|=0x80; reg.m=2; }
void SET7a() {reg.b|=0x80; reg.m=2; }
void SET7m() {i=mmu_rb((reg.h<<8)+reg.l); i|=0x80; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; }

void RLA() {ci=reg.f&0x10?1:0; co=reg.a&0x80?0x10:0; reg.a=(reg.a<<1)+ci; reg.a&=255; reg.f=(reg.f&0xEF)+co; reg.m=1; }
void RLCA() {ci=reg.a&0x80?1:0; co=reg.a&0x80?0x10:0; reg.a=(reg.a<<1)+ci; reg.a&=255; reg.f=(reg.f&0xEF)+co; reg.m=1; }
void RRA() {ci=reg.f&0x10?0x80:0; co=reg.a&1?0x10:0; reg.a=(reg.a>>1)+ci; reg.a&=255; reg.f=(reg.f&0xEF)+co; reg.m=1; }
void RRCA() {ci=reg.a&1?0x80:0; co=reg.a&1?0x10:0; reg.a=(reg.a>>1)+ci; reg.a&=255; reg.f=(reg.f&0xEF)+co; reg.m=1; }

void RLr_b() {ci=reg.f&0x10?1:0; co=reg.b&0x80?0x10:0; reg.b=(reg.b<<1)+ci; reg.b&=255; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RLr_c() {ci=reg.f&0x10?1:0; co=reg.c&0x80?0x10:0; reg.c=(reg.c<<1)+ci; reg.c&=255; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RLr_d() {ci=reg.f&0x10?1:0; co=reg.d&0x80?0x10:0; reg.d=(reg.d<<1)+ci; reg.d&=255; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RLr_e() {ci=reg.f&0x10?1:0; co=reg.e&0x80?0x10:0; reg.e=(reg.e<<1)+ci; reg.e&=255; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RLr_h() {ci=reg.f&0x10?1:0; co=reg.h&0x80?0x10:0; reg.h=(reg.h<<1)+ci; reg.h&=255; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RLr_l() {ci=reg.f&0x10?1:0; co=reg.l&0x80?0x10:0; reg.l=(reg.l<<1)+ci; reg.l&=255; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RLr_a() {ci=reg.f&0x10?1:0; co=reg.a&0x80?0x10:0; reg.a=(reg.a<<1)+ci; reg.a&=255; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RLHL() {i=mmu_rb((reg.h<<8)+reg.l); ci=reg.f&0x10?1:0; co=i&0x80?0x10:0; i=(i<<1)+ci; i&=255; reg.f=(i)?0:0x80; mmu_wb((reg.h<<8)+reg.l,i); reg.f=(reg.f&0xEF)+co; reg.m=4; }

void RLCr_b() {ci=reg.b&0x80?1:0; co=reg.b&0x80?0x10:0; reg.b=(reg.b<<1)+ci; reg.b&=255; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RLCr_c() {ci=reg.c&0x80?1:0; co=reg.c&0x80?0x10:0; reg.c=(reg.c<<1)+ci; reg.c&=255; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RLCr_d() {ci=reg.d&0x80?1:0; co=reg.d&0x80?0x10:0; reg.d=(reg.d<<1)+ci; reg.d&=255; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RLCr_e() {ci=reg.e&0x80?1:0; co=reg.e&0x80?0x10:0; reg.e=(reg.e<<1)+ci; reg.e&=255; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RLCr_h() {ci=reg.h&0x80?1:0; co=reg.h&0x80?0x10:0; reg.h=(reg.h<<1)+ci; reg.h&=255; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RLCr_l() {ci=reg.l&0x80?1:0; co=reg.l&0x80?0x10:0; reg.l=(reg.l<<1)+ci; reg.l&=255; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RLCr_a() {ci=reg.a&0x80?1:0; co=reg.a&0x80?0x10:0; reg.a=(reg.a<<1)+ci; reg.a&=255; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RLCHL() {i=mmu_rb((reg.h<<8)+reg.l); ci=i&0x80?1:0; co=i&0x80?0x10:0; i=(i<<1)+ci; i&=255; reg.f=(i)?0:0x80; mmu_wb((reg.h<<8)+reg.l,i); reg.f=(reg.f&0xEF)+co; reg.m=4; }

void RRr_b() {ci=reg.f&0x10?0x80:0; co=reg.b&1?0x10:0; reg.b=(reg.b>>1)+ci; reg.b&=255; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RRr_c() {ci=reg.f&0x10?0x80:0; co=reg.c&1?0x10:0; reg.c=(reg.c>>1)+ci; reg.c&=255; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RRr_d() {ci=reg.f&0x10?0x80:0; co=reg.d&1?0x10:0; reg.d=(reg.d>>1)+ci; reg.d&=255; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RRr_e() {ci=reg.f&0x10?0x80:0; co=reg.e&1?0x10:0; reg.e=(reg.e>>1)+ci; reg.e&=255; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RRr_h() {ci=reg.f&0x10?0x80:0; co=reg.h&1?0x10:0; reg.h=(reg.h>>1)+ci; reg.h&=255; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RRr_l() {ci=reg.f&0x10?0x80:0; co=reg.l&1?0x10:0; reg.l=(reg.l>>1)+ci; reg.l&=255; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RRr_a() {ci=reg.f&0x10?0x80:0; co=reg.a&1?0x10:0; reg.a=(reg.a>>1)+ci; reg.a&=255; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RRHL() {i=mmu_rb((reg.h<<8)+reg.l); ci=reg.f&0x10?0x80:0; co=i&1?0x10:0; i=(i>>1)+ci; i&=255; mmu_wb((reg.h<<8)+reg.l,i); reg.f=(i)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=4; }

void RRCr_b() {ci=reg.b&1?0x80:0; co=reg.b&1?0x10:0; reg.b=(reg.b>>1)+ci; reg.b&=255; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RRCr_c() {ci=reg.c&1?0x80:0; co=reg.c&1?0x10:0; reg.c=(reg.c>>1)+ci; reg.c&=255; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RRCr_d() {ci=reg.d&1?0x80:0; co=reg.d&1?0x10:0; reg.d=(reg.d>>1)+ci; reg.d&=255; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RRCr_e() {ci=reg.e&1?0x80:0; co=reg.e&1?0x10:0; reg.e=(reg.e>>1)+ci; reg.e&=255; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RRCr_h() {ci=reg.h&1?0x80:0; co=reg.h&1?0x10:0; reg.h=(reg.h>>1)+ci; reg.h&=255; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RRCr_l() {ci=reg.l&1?0x80:0; co=reg.l&1?0x10:0; reg.l=(reg.l>>1)+ci; reg.l&=255; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RRCr_a() {ci=reg.a&1?0x80:0; co=reg.a&1?0x10:0; reg.a=(reg.a>>1)+ci; reg.a&=255; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void RRCHL() {i=mmu_rb((reg.h<<8)+reg.l); ci=i&1?0x80:0; co=i&1?0x10:0; i=(i>>1)+ci; i&=255; mmu_wb((reg.h<<8)+reg.l,i); reg.f=(i)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=4; }

void SLAr_b() {co=reg.b&0x80?0x10:0; reg.b=(reg.b<<1)&255; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SLAr_c() {co=reg.c&0x80?0x10:0; reg.c=(reg.c<<1)&255; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SLAr_d() {co=reg.d&0x80?0x10:0; reg.d=(reg.d<<1)&255; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SLAr_e() {co=reg.e&0x80?0x10:0; reg.e=(reg.e<<1)&255; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SLAr_h() {co=reg.h&0x80?0x10:0; reg.h=(reg.h<<1)&255; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SLAr_l() {co=reg.l&0x80?0x10:0; reg.l=(reg.l<<1)&255; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SLAr_a() {co=reg.a&0x80?0x10:0; reg.a=(reg.a<<1)&255; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }

/*
void SLLr_b() {co=reg.b&0x80?0x10:0; reg.b=(reg.b<<1)&255+1; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SLLr_c() {co=reg.c&0x80?0x10:0; reg.c=(reg.c<<1)&255+1; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SLLr_d() {co=reg.d&0x80?0x10:0; reg.d=(reg.d<<1)&255+1; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SLLr_e() {co=reg.e&0x80?0x10:0; reg.e=(reg.e<<1)&255+1; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SLLr_h() {co=reg.h&0x80?0x10:0; reg.h=(reg.h<<1)&255+1; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SLLr_l() {co=reg.l&0x80?0x10:0; reg.l=(reg.l<<1)&255+1; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SLLr_a() {co=reg.a&0x80?0x10:0; reg.a=(reg.a<<1)&255+1; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
*/

void SRAr_b() {ci=reg.b&0x80; co=reg.b&1?0x10:0; reg.b=((reg.b>>1)+ci)&255; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SRAr_c() {ci=reg.c&0x80; co=reg.c&1?0x10:0; reg.c=((reg.c>>1)+ci)&255; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SRAr_d() {ci=reg.d&0x80; co=reg.d&1?0x10:0; reg.d=((reg.d>>1)+ci)&255; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SRAr_e() {ci=reg.e&0x80; co=reg.e&1?0x10:0; reg.e=((reg.e>>1)+ci)&255; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SRAr_h() {ci=reg.h&0x80; co=reg.h&1?0x10:0; reg.h=((reg.h>>1)+ci)&255; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SRAr_l() {ci=reg.l&0x80; co=reg.l&1?0x10:0; reg.l=((reg.l>>1)+ci)&255; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SRAr_a() {ci=reg.a&0x80; co=reg.a&1?0x10:0; reg.a=((reg.a>>1)+ci)&255; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }

void SRLr_b() {co=reg.b&1?0x10:0; reg.b=(reg.b>>1)&255; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SRLr_c() {co=reg.c&1?0x10:0; reg.c=(reg.c>>1)&255; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SRLr_d() {co=reg.d&1?0x10:0; reg.d=(reg.d>>1)&255; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SRLr_e() {co=reg.e&1?0x10:0; reg.e=(reg.e>>1)&255; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SRLr_h() {co=reg.h&1?0x10:0; reg.h=(reg.h>>1)&255; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SRLr_l() {co=reg.l&1?0x10:0; reg.l=(reg.l>>1)&255; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }
void SRLr_a() {co=reg.a&1?0x10:0; reg.a=(reg.a>>1)&255; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; }

void CPL() {reg.a ^= 255; reg.f=reg.a?0:0x80; reg.m=1; }
/*
void NEG() {reg.a=0-reg.a; reg.f=(reg.a<0)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; reg.m=2; }
*/

void CCF() {ci=reg.f&0x10?0:0x10; reg.f=(reg.f&0xEF)+ci; reg.m=1; }
void SCF() {reg.f|=0x10; reg.m=1; }
