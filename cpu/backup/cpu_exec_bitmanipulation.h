// Bit manipulation
case BIT0b:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x01)?0:0x80; reg.m=2; break;
case BIT0c:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x01)?0:0x80; reg.m=2; break;
case BIT0d:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x01)?0:0x80; reg.m=2; break;
case BIT0e:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x01)?0:0x80; reg.m=2; break;
case BIT0h:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x01)?0:0x80; reg.m=2; break;
case BIT0l:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x01)?0:0x80; reg.m=2; break;
case BIT0a:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x01)?0:0x80; reg.m=2; break;
case BIT0m:	reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x01)?0:0x80; reg.m=3; break;

case RES0b:	reg.b&=0xFE; reg.m=2; break;
case RES0c:	reg.c&=0xFE; reg.m=2; break;
case RES0d:	reg.d&=0xFE; reg.m=2; break;
case RES0e:	reg.e&=0xFE; reg.m=2; break;
case RES0h:	reg.h&=0xFE; reg.m=2; break;
case RES0l:	reg.l&=0xFE; reg.m=2; break;
case RES0a:	reg.a&=0xFE; reg.m=2; break;
case RES0m:	i=mmu_rb((reg.h<<8)+reg.l); i&=0xFE; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case SET0b:	reg.b|=0x01; reg.m=2; break;
case SET0c:	reg.b|=0x01; reg.m=2; break;
case SET0d:	reg.b|=0x01; reg.m=2; break;
case SET0e:	reg.b|=0x01; reg.m=2; break;
case SET0h:	reg.b|=0x01; reg.m=2; break;
case SET0l:	reg.b|=0x01; reg.m=2; break;
case SET0a:	reg.b|=0x01; reg.m=2; break;
case SET0m:	i=mmu_rb((reg.h<<8)+reg.l); i|=0x01; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case BIT1b:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x02)?0:0x80; reg.m=2; break;
case BIT1c:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x02)?0:0x80; reg.m=2; break;
case BIT1d:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x02)?0:0x80; reg.m=2; break;
case BIT1e:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x02)?0:0x80; reg.m=2; break;
case BIT1h:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x02)?0:0x80; reg.m=2; break;
case BIT1l:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x02)?0:0x80; reg.m=2; break;
case BIT1a:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x02)?0:0x80; reg.m=2; break;
case BIT1m:	reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x02)?0:0x80; reg.m=3; break;

case RES1b:	reg.b&=0xFD; reg.m=2; break;
case RES1c:	reg.c&=0xFD; reg.m=2; break;
case RES1d:	reg.d&=0xFD; reg.m=2; break;
case RES1e:	reg.e&=0xFD; reg.m=2; break;
case RES1h:	reg.h&=0xFD; reg.m=2; break;
case RES1l:	reg.l&=0xFD; reg.m=2; break;
case RES1a:	reg.a&=0xFD; reg.m=2; break;
case RES1m:	i=mmu_rb((reg.h<<8)+reg.l); i&=0xFD; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case SET1b:	reg.b|=0x02; reg.m=2; break;
case SET1c:	reg.b|=0x02; reg.m=2; break;
case SET1d:	reg.b|=0x02; reg.m=2; break;
case SET1e:	reg.b|=0x02; reg.m=2; break;
case SET1h:	reg.b|=0x02; reg.m=2; break;
case SET1l:	reg.b|=0x02; reg.m=2; break;
case SET1a:	reg.b|=0x02; reg.m=2; break;
case SET1m:	i=mmu_rb((reg.h<<8)+reg.l); i|=0x02; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case BIT2b:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x04)?0:0x80; reg.m=2; break;
case BIT2c:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x04)?0:0x80; reg.m=2; break;
case BIT2d:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x04)?0:0x80; reg.m=2; break;
case BIT2e:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x04)?0:0x80; reg.m=2; break;
case BIT2h:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x04)?0:0x80; reg.m=2; break;
case BIT2l:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x04)?0:0x80; reg.m=2; break;
case BIT2a:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x04)?0:0x80; reg.m=2; break;
case BIT2m:	reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x04)?0:0x80; reg.m=3; break;

case RES2b:	reg.b&=0xFB; reg.m=2; break;
case RES2c:	reg.c&=0xFB; reg.m=2; break;
case RES2d:	reg.d&=0xFB; reg.m=2; break;
case RES2e:	reg.e&=0xFB; reg.m=2; break;
case RES2h:	reg.h&=0xFB; reg.m=2; break;
case RES2l:	reg.l&=0xFB; reg.m=2; break;
case RES2a:	reg.a&=0xFB; reg.m=2; break;
case RES2m:	i=mmu_rb((reg.h<<8)+reg.l); i&=0xFB; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case SET2b:	reg.b|=0x04; reg.m=2; break;
case SET2c:	reg.b|=0x04; reg.m=2; break;
case SET2d:	reg.b|=0x04; reg.m=2; break;
case SET2e:	reg.b|=0x04; reg.m=2; break;
case SET2h:	reg.b|=0x04; reg.m=2; break;
case SET2l:	reg.b|=0x04; reg.m=2; break;
case SET2a:	reg.b|=0x04; reg.m=2; break;
case SET2m:	i=mmu_rb((reg.h<<8)+reg.l); i|=0x04; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case BIT3b:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x08)?0:0x80; reg.m=2; break;
case BIT3c:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x08)?0:0x80; reg.m=2; break;
case BIT3d:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x08)?0:0x80; reg.m=2; break;
case BIT3e:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x08)?0:0x80; reg.m=2; break;
case BIT3h:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x08)?0:0x80; reg.m=2; break;
case BIT3l:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x08)?0:0x80; reg.m=2; break;
case BIT3a:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x08)?0:0x80; reg.m=2; break;
case BIT3m:	reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x08)?0:0x80; reg.m=3; break;

case RES3b:	reg.b&=0xF7; reg.m=2; break;
case RES3c:	reg.c&=0xF7; reg.m=2; break;
case RES3d:	reg.d&=0xF7; reg.m=2; break;
case RES3e:	reg.e&=0xF7; reg.m=2; break;
case RES3h:	reg.h&=0xF7; reg.m=2; break;
case RES3l:	reg.l&=0xF7; reg.m=2; break;
case RES3a:	reg.a&=0xF7; reg.m=2; break;
case RES3m:	i=mmu_rb((reg.h<<8)+reg.l); i&=0xF7; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case SET3b:	reg.b|=0x08; reg.m=2; break;
case SET3c:	reg.b|=0x08; reg.m=2; break;
case SET3d:	reg.b|=0x08; reg.m=2; break;
case SET3e:	reg.b|=0x08; reg.m=2; break;
case SET3h:	reg.b|=0x08; reg.m=2; break;
case SET3l:	reg.b|=0x08; reg.m=2; break;
case SET3a:	reg.b|=0x08; reg.m=2; break;
case SET3m:	i=mmu_rb((reg.h<<8)+reg.l); i|=0x08; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case BIT4b:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x10)?0:0x80; reg.m=2; break;
case BIT4c:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x10)?0:0x80; reg.m=2; break;
case BIT4d:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x10)?0:0x80; reg.m=2; break;
case BIT4e:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x10)?0:0x80; reg.m=2; break;
case BIT4h:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x10)?0:0x80; reg.m=2; break;
case BIT4l:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x10)?0:0x80; reg.m=2; break;
case BIT4a:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x10)?0:0x80; reg.m=2; break;
case BIT4m:	reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x10)?0:0x80; reg.m=3; break;

case RES4b:	reg.b&=0xEF; reg.m=2; break;
case RES4c:	reg.c&=0xEF; reg.m=2; break;
case RES4d:	reg.d&=0xEF; reg.m=2; break;
case RES4e:	reg.e&=0xEF; reg.m=2; break;
case RES4h:	reg.h&=0xEF; reg.m=2; break;
case RES4l:	reg.l&=0xEF; reg.m=2; break;
case RES4a:	reg.a&=0xEF; reg.m=2; break;
case RES4m:	i=mmu_rb((reg.h<<8)+reg.l); i&=0xEF; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case SET4b:	reg.b|=0x10; reg.m=2; break;
case SET4c:	reg.b|=0x10; reg.m=2; break;
case SET4d:	reg.b|=0x10; reg.m=2; break;
case SET4e:	reg.b|=0x10; reg.m=2; break;
case SET4h:	reg.b|=0x10; reg.m=2; break;
case SET4l:	reg.b|=0x10; reg.m=2; break;
case SET4a:	reg.b|=0x10; reg.m=2; break;
case SET4m:	i=mmu_rb((reg.h<<8)+reg.l); i|=0x10; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case BIT5b:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x20)?0:0x80; reg.m=2; break;
case BIT5c:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x20)?0:0x80; reg.m=2; break;
case BIT5d:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x20)?0:0x80; reg.m=2; break;
case BIT5e:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x20)?0:0x80; reg.m=2; break;
case BIT5h:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x20)?0:0x80; reg.m=2; break;
case BIT5l:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x20)?0:0x80; reg.m=2; break;
case BIT5a:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x20)?0:0x80; reg.m=2; break;
case BIT5m:	reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x20)?0:0x80; reg.m=3; break;

case RES5b:	reg.b&=0xDF; reg.m=2; break;
case RES5c:	reg.c&=0xDF; reg.m=2; break;
case RES5d:	reg.d&=0xDF; reg.m=2; break;
case RES5e:	reg.e&=0xDF; reg.m=2; break;
case RES5h:	reg.h&=0xDF; reg.m=2; break;
case RES5l:	reg.l&=0xDF; reg.m=2; break;
case RES5a:	reg.a&=0xDF; reg.m=2; break;
case RES5m:	i=mmu_rb((reg.h<<8)+reg.l); i&=0xDF; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case SET5b:	reg.b|=0x20; reg.m=2; break;
case SET5c:	reg.b|=0x20; reg.m=2; break;
case SET5d:	reg.b|=0x20; reg.m=2; break;
case SET5e:	reg.b|=0x20; reg.m=2; break;
case SET5h:	reg.b|=0x20; reg.m=2; break;
case SET5l:	reg.b|=0x20; reg.m=2; break;
case SET5a:	reg.b|=0x20; reg.m=2; break;
case SET5m:	i=mmu_rb((reg.h<<8)+reg.l); i|=0x20; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case BIT6b:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x40)?0:0x80; reg.m=2; break;
case BIT6c:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x40)?0:0x80; reg.m=2; break;
case BIT6d:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x40)?0:0x80; reg.m=2; break;
case BIT6e:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x40)?0:0x80; reg.m=2; break;
case BIT6h:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x40)?0:0x80; reg.m=2; break;
case BIT6l:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x40)?0:0x80; reg.m=2; break;
case BIT6a:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x40)?0:0x80; reg.m=2; break;
case BIT6m:	reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x40)?0:0x80; reg.m=3; break;

case RES6b:	reg.b&=0xBF; reg.m=2; break;
case RES6c:	reg.c&=0xBF; reg.m=2; break;
case RES6d:	reg.d&=0xBF; reg.m=2; break;
case RES6e:	reg.e&=0xBF; reg.m=2; break;
case RES6h:	reg.h&=0xBF; reg.m=2; break;
case RES6l:	reg.l&=0xBF; reg.m=2; break;
case RES6a:	reg.a&=0xBF; reg.m=2; break;
case RES6m:	i=mmu_rb((reg.h<<8)+reg.l); i&=0xBF; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case SET6b:	reg.b|=0x40; reg.m=2; break;
case SET6c:	reg.b|=0x40; reg.m=2; break;
case SET6d:	reg.b|=0x40; reg.m=2; break;
case SET6e:	reg.b|=0x40; reg.m=2; break;
case SET6h:	reg.b|=0x40; reg.m=2; break;
case SET6l:	reg.b|=0x40; reg.m=2; break;
case SET6a:	reg.b|=0x40; reg.m=2; break;
case SET6m:	i=mmu_rb((reg.h<<8)+reg.l); i|=0x40; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case BIT7b:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.b&0x80)?0:0x80; reg.m=2; break;
case BIT7c:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.c&0x80)?0:0x80; reg.m=2; break;
case BIT7d:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.d&0x80)?0:0x80; reg.m=2; break;
case BIT7e:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.e&0x80)?0:0x80; reg.m=2; break;
case BIT7h:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.h&0x80)?0:0x80; reg.m=2; break;
case BIT7l:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.l&0x80)?0:0x80; reg.m=2; break;
case BIT7a:	reg.f&=0x1F; reg.f|=0x20; reg.f=(reg.a&0x80)?0:0x80; reg.m=2; break;
case BIT7m:	reg.f&=0x1F; reg.f|=0x20; reg.f=(mmu_rb((reg.h<<8)+reg.l)&0x80)?0:0x80; reg.m=3; break;

case RES7b:	reg.b&=0x7F; reg.m=2; break;
case RES7c:	reg.c&=0x7F; reg.m=2; break;
case RES7d:	reg.d&=0x7F; reg.m=2; break;
case RES7e:	reg.e&=0x7F; reg.m=2; break;
case RES7h:	reg.h&=0x7F; reg.m=2; break;
case RES7l:	reg.l&=0x7F; reg.m=2; break;
case RES7a:	reg.a&=0x7F; reg.m=2; break;
case RES7m:	i=mmu_rb((reg.h<<8)+reg.l); i&=0x7F; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case SET7b:	reg.b|=0x80; reg.m=2; break;
case SET7c:	reg.b|=0x80; reg.m=2; break;
case SET7d:	reg.b|=0x80; reg.m=2; break;
case SET7e:	reg.b|=0x80; reg.m=2; break;
case SET7h:	reg.b|=0x80; reg.m=2; break;
case SET7l:	reg.b|=0x80; reg.m=2; break;
case SET7a:	reg.b|=0x80; reg.m=2; break;
case SET7m:	i=mmu_rb((reg.h<<8)+reg.l); i|=0x80; mmu_wb((reg.h<<8)+reg.l,i); reg.m=4; break;

case RLA:	ci=reg.f&0x10?1:0; co=reg.a&0x80?0x10:0; reg.a=(reg.a<<1)+ci; reg.a&=255; reg.f=(reg.f&0xEF)+co; reg.m=1; break;
case RLCA:	ci=reg.a&0x80?1:0; co=reg.a&0x80?0x10:0; reg.a=(reg.a<<1)+ci; reg.a&=255; reg.f=(reg.f&0xEF)+co; reg.m=1; break;
case RRA:	ci=reg.f&0x10?0x80:0; co=reg.a&1?0x10:0; reg.a=(reg.a>>1)+ci; reg.a&=255; reg.f=(reg.f&0xEF)+co; reg.m=1; break;
case RRCA:	ci=reg.a&1?0x80:0; co=reg.a&1?0x10:0; reg.a=(reg.a>>1)+ci; reg.a&=255; reg.f=(reg.f&0xEF)+co; reg.m=1; break;

case RLr_b:	ci=reg.f&0x10?1:0; co=reg.b&0x80?0x10:0; reg.b=(reg.b<<1)+ci; reg.b&=255; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RLr_c:	ci=reg.f&0x10?1:0; co=reg.c&0x80?0x10:0; reg.c=(reg.c<<1)+ci; reg.c&=255; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RLr_d:	ci=reg.f&0x10?1:0; co=reg.d&0x80?0x10:0; reg.d=(reg.d<<1)+ci; reg.d&=255; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RLr_e:	ci=reg.f&0x10?1:0; co=reg.e&0x80?0x10:0; reg.e=(reg.e<<1)+ci; reg.e&=255; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RLr_h:	ci=reg.f&0x10?1:0; co=reg.h&0x80?0x10:0; reg.h=(reg.h<<1)+ci; reg.h&=255; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RLr_l:	ci=reg.f&0x10?1:0; co=reg.l&0x80?0x10:0; reg.l=(reg.l<<1)+ci; reg.l&=255; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RLr_a:	ci=reg.f&0x10?1:0; co=reg.a&0x80?0x10:0; reg.a=(reg.a<<1)+ci; reg.a&=255; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RLHL:	i=mmu_rb((reg.h<<8)+reg.l); ci=reg.f&0x10?1:0; co=i&0x80?0x10:0; i=(i<<1)+ci; i&=255; reg.f=(i)?0:0x80; mmu_wb((reg.h<<8)+reg.l,i); reg.f=(reg.f&0xEF)+co; reg.m=4; break;

case RLCr_b:	ci=reg.b&0x80?1:0; co=reg.b&0x80?0x10:0; reg.b=(reg.b<<1)+ci; reg.b&=255; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RLCr_c:	ci=reg.c&0x80?1:0; co=reg.c&0x80?0x10:0; reg.c=(reg.c<<1)+ci; reg.c&=255; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RLCr_d:	ci=reg.d&0x80?1:0; co=reg.d&0x80?0x10:0; reg.d=(reg.d<<1)+ci; reg.d&=255; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RLCr_e:	ci=reg.e&0x80?1:0; co=reg.e&0x80?0x10:0; reg.e=(reg.e<<1)+ci; reg.e&=255; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RLCr_h:	ci=reg.h&0x80?1:0; co=reg.h&0x80?0x10:0; reg.h=(reg.h<<1)+ci; reg.h&=255; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RLCr_l:	ci=reg.l&0x80?1:0; co=reg.l&0x80?0x10:0; reg.l=(reg.l<<1)+ci; reg.l&=255; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RLCr_a:	ci=reg.a&0x80?1:0; co=reg.a&0x80?0x10:0; reg.a=(reg.a<<1)+ci; reg.a&=255; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RLCHL:	i=mmu_rb((reg.h<<8)+reg.l); ci=i&0x80?1:0; co=i&0x80?0x10:0; i=(i<<1)+ci; i&=255; reg.f=(i)?0:0x80; mmu_wb((reg.h<<8)+reg.l,i); reg.f=(reg.f&0xEF)+co; reg.m=4; break;

case RRr_b:	ci=reg.f&0x10?0x80:0; co=reg.b&1?0x10:0; reg.b=(reg.b>>1)+ci; reg.b&=255; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RRr_c:	ci=reg.f&0x10?0x80:0; co=reg.c&1?0x10:0; reg.c=(reg.c>>1)+ci; reg.c&=255; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RRr_d:	ci=reg.f&0x10?0x80:0; co=reg.d&1?0x10:0; reg.d=(reg.d>>1)+ci; reg.d&=255; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RRr_e:	ci=reg.f&0x10?0x80:0; co=reg.e&1?0x10:0; reg.e=(reg.e>>1)+ci; reg.e&=255; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RRr_h:	ci=reg.f&0x10?0x80:0; co=reg.h&1?0x10:0; reg.h=(reg.h>>1)+ci; reg.h&=255; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RRr_l:	ci=reg.f&0x10?0x80:0; co=reg.l&1?0x10:0; reg.l=(reg.l>>1)+ci; reg.l&=255; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RRr_a:	ci=reg.f&0x10?0x80:0; co=reg.a&1?0x10:0; reg.a=(reg.a>>1)+ci; reg.a&=255; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RRHL:	i=mmu_rb((reg.h<<8)+reg.l); ci=reg.f&0x10?0x80:0; co=i&1?0x10:0; i=(i>>1)+ci; i&=255; mmu_wb((reg.h<<8)+reg.l,i); reg.f=(i)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=4; break;

case RRCr_b:	ci=reg.b&1?0x80:0; co=reg.b&1?0x10:0; reg.b=(reg.b>>1)+ci; reg.b&=255; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RRCr_c:	ci=reg.c&1?0x80:0; co=reg.c&1?0x10:0; reg.c=(reg.c>>1)+ci; reg.c&=255; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RRCr_d:	ci=reg.d&1?0x80:0; co=reg.d&1?0x10:0; reg.d=(reg.d>>1)+ci; reg.d&=255; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RRCr_e:	ci=reg.e&1?0x80:0; co=reg.e&1?0x10:0; reg.e=(reg.e>>1)+ci; reg.e&=255; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RRCr_h:	ci=reg.h&1?0x80:0; co=reg.h&1?0x10:0; reg.h=(reg.h>>1)+ci; reg.h&=255; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RRCr_l:	ci=reg.l&1?0x80:0; co=reg.l&1?0x10:0; reg.l=(reg.l>>1)+ci; reg.l&=255; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RRCr_a:	ci=reg.a&1?0x80:0; co=reg.a&1?0x10:0; reg.a=(reg.a>>1)+ci; reg.a&=255; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case RRCHL:	i=mmu_rb((reg.h<<8)+reg.l); ci=i&1?0x80:0; co=i&1?0x10:0; i=(i>>1)+ci; i&=255; mmu_wb((reg.h<<8)+reg.l,i); reg.f=(i)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=4; break;

case SLAr_b:	co=reg.b&0x80?0x10:0; reg.b=(reg.b<<1)&255; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SLAr_c:	co=reg.c&0x80?0x10:0; reg.c=(reg.c<<1)&255; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SLAr_d:	co=reg.d&0x80?0x10:0; reg.d=(reg.d<<1)&255; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SLAr_e:	co=reg.e&0x80?0x10:0; reg.e=(reg.e<<1)&255; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SLAr_h:	co=reg.h&0x80?0x10:0; reg.h=(reg.h<<1)&255; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SLAr_l:	co=reg.l&0x80?0x10:0; reg.l=(reg.l<<1)&255; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SLAr_a:	co=reg.a&0x80?0x10:0; reg.a=(reg.a<<1)&255; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;

/*
case SLLr_b:	co=reg.b&0x80?0x10:0; reg.b=(reg.b<<1)&255+1; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SLLr_c:	co=reg.c&0x80?0x10:0; reg.c=(reg.c<<1)&255+1; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SLLr_d:	co=reg.d&0x80?0x10:0; reg.d=(reg.d<<1)&255+1; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SLLr_e:	co=reg.e&0x80?0x10:0; reg.e=(reg.e<<1)&255+1; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SLLr_h:	co=reg.h&0x80?0x10:0; reg.h=(reg.h<<1)&255+1; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SLLr_l:	co=reg.l&0x80?0x10:0; reg.l=(reg.l<<1)&255+1; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SLLr_a:	co=reg.a&0x80?0x10:0; reg.a=(reg.a<<1)&255+1; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
*/

case SRAr_b:	ci=reg.b&0x80; co=reg.b&1?0x10:0; reg.b=((reg.b>>1)+ci)&255; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SRAr_c:	ci=reg.c&0x80; co=reg.c&1?0x10:0; reg.c=((reg.c>>1)+ci)&255; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SRAr_d:	ci=reg.d&0x80; co=reg.d&1?0x10:0; reg.d=((reg.d>>1)+ci)&255; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SRAr_e:	ci=reg.e&0x80; co=reg.e&1?0x10:0; reg.e=((reg.e>>1)+ci)&255; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SRAr_h:	ci=reg.h&0x80; co=reg.h&1?0x10:0; reg.h=((reg.h>>1)+ci)&255; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SRAr_l:	ci=reg.l&0x80; co=reg.l&1?0x10:0; reg.l=((reg.l>>1)+ci)&255; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SRAr_a:	ci=reg.a&0x80; co=reg.a&1?0x10:0; reg.a=((reg.a>>1)+ci)&255; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;

case SRLr_b:	co=reg.b&1?0x10:0; reg.b=(reg.b>>1)&255; reg.f=(reg.b)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SRLr_c:	co=reg.c&1?0x10:0; reg.c=(reg.c>>1)&255; reg.f=(reg.c)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SRLr_d:	co=reg.d&1?0x10:0; reg.d=(reg.d>>1)&255; reg.f=(reg.d)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SRLr_e:	co=reg.e&1?0x10:0; reg.e=(reg.e>>1)&255; reg.f=(reg.e)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SRLr_h:	co=reg.h&1?0x10:0; reg.h=(reg.h>>1)&255; reg.f=(reg.h)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SRLr_l:	co=reg.l&1?0x10:0; reg.l=(reg.l>>1)&255; reg.f=(reg.l)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;
case SRLr_a:	co=reg.a&1?0x10:0; reg.a=(reg.a>>1)&255; reg.f=(reg.a)?0:0x80; reg.f=(reg.f&0xEF)+co; reg.m=2; break;

case CPL:	reg.a ^= 255; reg.f=reg.a?0:0x80; reg.m=1; break;
/*
case NEG:	reg.a=0-reg.a; reg.f=(reg.a<0)?0x10:0; reg.a&=255; if(!reg.a) reg.f|=0x80; reg.m=2; break;
*/

case CCF:	ci=reg.f&0x10?0:0x10; reg.f=(reg.f&0xEF)+ci; reg.m=1; break;
case SCF:	reg.f|=0x10; reg.m=1; break;
