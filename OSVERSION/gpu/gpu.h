#ifndef GPU_H
#define GPU_H

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
	unsigned char vram[8*1024];
	unsigned char oam[160];
	unsigned char reg[64];
	unsigned char tilemap[512][8][8];
	
	obj objdata[40];
	obj objdatasorted[40];
	
	palette palette_;
	
	unsigned char scanrow[256];
	
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

unsigned int scrn[256][256];

gpu gpu_;

#include "cpu.h"
#include "mmu.h"

void gpu_reset();

void gpu_checkline();

void gpu_update_tile(unsigned int addr);

void gpu_update_oam(unsigned int addr, unsigned char val);

void sort_objdatasorted();

int gpu_rb(unsigned int addr);

void gpu_wb(unsigned int addr,unsigned char val);

#endif