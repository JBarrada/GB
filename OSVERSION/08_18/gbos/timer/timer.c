
typedef struct registers {
	int a, b, c, d, e, h, l, f;
	int sp, pc, r, m, ime;
} registers;

typedef struct mbc {
	unsigned int rombank;
	unsigned int rambank;
	unsigned int ramon;
	unsigned int mode;
} mbc;

typedef struct mmu {
	unsigned char rom[256*1024]; // banks 1 and 2
	int eram[8*1024]; // external/cartridge ram
	int wram[32*1024]; // working ram 8k + shadow
	int zram[128]; // "zero-page" ram 
	
	mbc mbc_;

	unsigned int carttype;
	unsigned int romoffs;
	unsigned int ramoffs;
	
	unsigned int inbios;
	unsigned int ie_;
	unsigned int if_;
} mmu;

extern mmu mmu_;

extern registers reg;


unsigned int timer_div;
unsigned int timer_tma;
unsigned int timer_tima;
unsigned int timer_tac;

unsigned int timer_clock_main;
unsigned int timer_clock_sub;
unsigned int timer_clock_div;

void timer_reset() {
	timer_div = 0;
	timer_tma = 0;
	timer_tima = 0;
	timer_tac = 0;

	timer_clock_main = 0;
	timer_clock_sub = 0;
	timer_clock_div = 0;
}

void timer_step() {
	timer_tima++;
    timer_clock_main = 0;
    if(timer_tima > 255) {
      timer_tima = timer_tma;
      mmu_.if_ |= 4;
    }
}

void timer_inc() {
	unsigned int oldclk = timer_clock_main;
	
	timer_clock_sub += reg.m;
	if(timer_clock_sub > 3) {
		timer_clock_main++;
		timer_clock_sub -= 4;

		timer_clock_div++;
		if(timer_clock_div==16) {
			timer_clock_div = 0;
			timer_div++;
			timer_div &= 255;
		}
	}
	
    if(timer_tac & 4) {
		switch(timer_tac & 3) {
			case 0:
				if(timer_clock_main >= 64) timer_step();
				break;
			case 1:
				if(timer_clock_main >=  1) timer_step();
				break;
			case 2:
				if(timer_clock_main >=  4) timer_step();
				break;
			case 3:
				if(timer_clock_main >= 16) timer_step();
				break;
		}
    }
}

unsigned int timer_rb(unsigned int addr) {
	switch(addr) {
      case 0xFF04: return timer_div;
      case 0xFF05: return timer_tima;
      case 0xFF06: return timer_tma;
      case 0xFF07: return timer_tac;
    }
}

void timer_wb(unsigned int addr, unsigned int val) {
	switch(addr) {
      case 0xFF04: timer_div = 0; break;
      case 0xFF05: timer_tima = val; break;
      case 0xFF06: timer_tma = val; break;
      case 0xFF07: timer_tac = val&7; break;
    }
}