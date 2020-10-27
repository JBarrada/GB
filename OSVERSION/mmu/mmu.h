#ifndef MMU_H
#define MMU_H

typedef struct mbc {
	unsigned int rombank;
	unsigned int rambank;
	unsigned int ramon;
	unsigned int mode;
} mbc;

typedef struct mmu {
	unsigned char rom[1024*1024]; // banks 1 and 2
	int eram[32*1024]; // external/cartridge ram
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

mmu mmu_;

void mmu_reset();

void mmu_load();

unsigned char mmu_rb(unsigned int addr);

unsigned int mmu_rw(unsigned int addr);

void mmu_wb(unsigned int addr, unsigned char val);

#include "cpu.h"
#include "gpu.h"

extern unsigned char key_rb();
extern void key_wb(unsigned int v);

#endif
