#include <stdio.h>

typedef struct registers {
	int a, b, c, d, e, h, l, f;
	int sp, pc, r, m, ime;
} registers;

extern int debug;
extern char debug_data[15][12];
extern unsigned int clock;
extern registers reg;


typedef struct obj {
	int x;
	int y;
	int tile;
	int palette;
	int yflip;
	int xflip;
	int prio;
	int num;
} obj;

typedef struct palette {
	int bg[4];
	int obj0[4];
	int obj1[4];
} palette;

typedef struct gpu {
	int vram[8*1024];
	int oam[160];
	int reg[32];
	int tilemap[512][8][8];
	
	obj objdata[40];
	obj objdatasorted[40];
	
	palette palette_;
	
	int scanrow[256];
	
	unsigned char curline;
	unsigned char curscan;
	unsigned char linemode;
	unsigned int modeclocks;
	
	int yscrl;
	int xscrl;
	int winy;
	int winx;
	unsigned char raster;
	unsigned char ints;
	unsigned char intfired;
	
	unsigned char lcdon;
	unsigned char bgon;
	unsigned char objon;
	unsigned char winon;
	
	int objsize;
	
	int bgtilebase;
	int bgmapbase;
	int winmapbase;
} gpu;

extern gpu gpu_;


unsigned int scrn[256][256];


FILE *f;


unsigned int loop_detect[] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
unsigned int loop_pos = 0;
unsigned int loop_len = 8;
unsigned int is_loop = 0;

void push_pc(unsigned int pc){
	//determine if pc already in loop
	int i;
	int inloop = -1;
	for (i=0;i<8;i++) {
		if (loop_detect[i] == pc) {
			inloop = i;
			i = 8;
		}
	}
	
	
	if (is_loop) {
		
		//see if aligned
		if (inloop == loop_pos) {
			if (debug == 1) {
				debug = 0;
				fprintf(f, "LOOP ...\n");
			}
		}
		else { // loop misaligned
			debug = 1;
			is_loop = 0;
			loop_len = 8;
			loop_pos = 0;
			loop_detect[loop_pos] = pc;
		}
		
	}
	else { // not in loop yet
	
		if (inloop != -1) {
			int trans = 0; // align with index 0
			for (i=inloop; i<loop_pos; i++) {
				loop_detect[trans] = loop_detect[i];
				trans++;
			}
			for (trans=trans; trans<8; trans++) {
				loop_detect[trans] = 0xfffffff;
			}
			
			is_loop = 1;
			loop_len = loop_pos-inloop;
			loop_pos = 0;
		}
		else {
			loop_detect[loop_pos] = pc;
			is_loop = 0;
		}
		debug = 1;
	}
	
	loop_pos++;
	if (loop_pos>=loop_len)
		loop_pos = 0;
}



int exit_pc = -1;

void write_debug(FILE *f) {
	int i;
	for (i=0; i<15; i++) {
		fprintf(f, debug_data[i]);
		fprintf(f, ",");
	}
	fprintf(f, "\n");
}


void main() {
	cpu_reset();
	mmu_reset();
	gpu_reset();
	mmu_load();

	f = fopen("debug.csv", "w");
	fprintf(f, "CLOCK,0XOP,OPCODE,A,B,C,D,E,H,L,F,SP,PC,R,M\n");
	debug = 0;
	
	//0x005d9e54
	
	unsigned int i = 0;
	unsigned int totalcalcs = 22000000;
	for (i=0; i<totalcalcs; i++) { //2239000 //2336300
		//if (reg.pc == 0xfa)
			//debug = 1;
		
		//push_pc(reg.pc);
		
		/*
		switch (reg.pc) {
			case 0x04:
				if (debug) {
					fprintf(f, "CLEAR VRAM ...\n");
					exit_pc = 0x0c;
					debug = 0;	
				}
				break;
			case 0x95:
				if (debug) {
					fprintf(f, "DECOMPRESS/SCALE/WRITE NINTENDO LOGO PIXELS TO VRAM 1 ...\n");
					exit_pc = 0xa7;
					debug = 0;	
				}
				break;
			case 0x96:
				if (debug) {
					fprintf(f, "DECOMPRESS/SCALE/WRITE NINTENDO LOGO PIXELS TO VRAM 2 ...\n");
					exit_pc = 0xa7;
					debug = 0;	
				}
				break;
			case 0x32:
				if (debug) {
					//fprintf(f, "LOOP IF NOT FINSIHED COMPARING ...\n");
					//exit_pc = 0x34;
					//debug = 0;	
				}
				break;
			case 0x3e:
				if (debug) {
					fprintf(f, "JUMP IF NOT ZERO TO 0x39 ...\n");
					exit_pc = 0x40;
					debug = 0;	
				}
				break;
			case 0x4f:
				if (debug) {
					fprintf(f, "JUMP IF NOT ZERO TO 0x4f ...\n");
					exit_pc = 0x51;
					debug = 0;	
				}
				break;
			case 0x55:
				if (debug) {
					fprintf(f, "SCROLL NINTENDO LOGO ...\n");
					exit_pc = 0xe0;
					debug = 0;	
				}
				break;
			case 0xef:
				if (debug) {
					fprintf(f, "JUMP IF NOT AT END TO 0xe6 ...\n");
					exit_pc = 0xf1;
					debug = 0;	
				}
				break;
			case 0xf7:
				if (debug) {
					fprintf(f, "LOOP ...\n");
					exit_pc = 0xf9;
					debug = 0;	
				}
				break;
			case 0x100:
				if (debug) {
					fprintf(f, "EXECUTION PASSED TO CARTRIDGE ROM ... \n");
				}
				break;
			
			case 0x0214:
				if (debug) {
					fprintf(f, "ROM STUFF 1 ... \n");
					exit_pc = 0x218;
					debug = 0;
				}
				break;
			case 0x0233:
				if (debug) {
					fprintf(f, "ROM STUFF 2 ... \n");
					exit_pc = 0x239;
					debug = 0;
				}
				break;
			case 0x0260:
				if (debug) {
					fprintf(f, "ROM STUFF 2 ... \n");
					exit_pc = 0x239;
					debug = 0;
				}
				break;	
			
			case 0x02a0:
				if (debug) {
					fprintf(f, "ROM STUFF 3 ... \n");
					exit_pc = 0x27a3;
					debug = 0;
				}
				break;
				

		}
		if (reg.pc == exit_pc) {
			debug = 1;
		}
		*/
		
		
		if (i > totalcalcs-10000000) {
			debug = 1;
		}
		
		
		//if (clock > 0x011003ed)
			//break;
		
		exec();

			
		//if (debug)
			//write_debug(f);		
	}
	FILE *s;
	s = fopen("screen.txt", "w");
	int x, y;
	for (y=0; y<144; y++) {
		for (x=0; x<160; x++) {
			if (scrn[y][x])
				fprintf(s, "%d", scrn[y][x]);
			else
				fprintf(s, " ");
		}
		fprintf(s, "\n");
	}
	
	/*
	//dump tilemap
	int tile, x, y;
	for (tile=0; tile<(256+128); tile++) {
		for (y=0; y<8; y++) {
			for (x=0; x<8; x++) {
				if (gpu_.tilemap[tile][y][x])
					fprintf(s, "%d", gpu_.tilemap[tile][y][x]);
				else
					fprintf(s, " ");
			}
			fprintf(s, "\n");
		}
		fprintf(s, "\n");
	}
	*/
	
}