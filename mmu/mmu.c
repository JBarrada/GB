#include <stdio.h>
#include "mmu.h"

int bios[] = {
0x31, 0xFE, 0xFF, 0xAF, 0x21, 0xFF, 0x9F, 0x32, 0xCB, 0x7C, 0x20, 0xFB, 0x21, 0x26, 0xFF, 0x0E,
0x11, 0x3E, 0x80, 0x32, 0xE2, 0x0C, 0x3E, 0xF3, 0xE2, 0x32, 0x3E, 0x77, 0x77, 0x3E, 0xFC, 0xE0,
0x47, 0x11, 0x04, 0x01, 0x21, 0x10, 0x80, 0x1A, 0xCD, 0x95, 0x00, 0xCD, 0x96, 0x00, 0x13, 0x7B,
0xFE, 0x34, 0x20, 0xF3, 0x11, 0xD8, 0x00, 0x06, 0x08, 0x1A, 0x13, 0x22, 0x23, 0x05, 0x20, 0xF9,
0x3E, 0x19, 0xEA, 0x10, 0x99, 0x21, 0x2F, 0x99, 0x0E, 0x0C, 0x3D, 0x28, 0x08, 0x32, 0x0D, 0x20,
0xF9, 0x2E, 0x0F, 0x18, 0xF3, 0x67, 0x3E, 0x64, 0x57, 0xE0, 0x42, 0x3E, 0x91, 0xE0, 0x40, 0x04,
0x1E, 0x02, 0x0E, 0x0C, 0xF0, 0x44, 0xFE, 0x90, 0x20, 0xFA, 0x0D, 0x20, 0xF7, 0x1D, 0x20, 0xF2,
0x0E, 0x13, 0x24, 0x7C, 0x1E, 0x83, 0xFE, 0x62, 0x28, 0x06, 0x1E, 0xC1, 0xFE, 0x64, 0x20, 0x06,
0x7B, 0xE2, 0x0C, 0x3E, 0x87, 0xF2, 0xF0, 0x42, 0x90, 0xE0, 0x42, 0x15, 0x20, 0xD2, 0x05, 0x20,
0x4F, 0x16, 0x20, 0x18, 0xCB, 0x4F, 0x06, 0x04, 0xC5, 0xCB, 0x11, 0x17, 0xC1, 0xCB, 0x11, 0x17,
0x05, 0x20, 0xF5, 0x22, 0x23, 0x22, 0x23, 0xC9, 0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B,
0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D, 0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E,
0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99, 0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC,
0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E, 0x3c, 0x42, 0xB9, 0xA5, 0xB9, 0xA5, 0x42, 0x4C,
0x21, 0x04, 0x01, 0x11, 0xA8, 0x00, 0x1A, 0x13, 0xBE, 0x20, 0xFE, 0x23, 0x7D, 0xFE, 0x34, 0x20,
0xF5, 0x06, 0x19, 0x78, 0x86, 0x23, 0x05, 0x20, 0xFB, 0x86, 0x20, 0xFE, 0x3E, 0x01, 0xE0, 0x50
};

void mmu_reset() {
	
	mmu_.zram[5] = 0xff;
	
	mmu_.inbios = 1;
	mmu_.ie_ = 0;
	mmu_.if_ = 0;
	
	mmu_.carttype = 0;
	mmu_.mbc_.rombank = 0;
	mmu_.mbc_.rambank = 0;
	mmu_.mbc_.ramon = 0;
	mmu_.mbc_.mode = 0;
	
	mmu_.romoffs = 0x4000;
	mmu_.ramoffs = 0;
	printf("mmu reset\n");
}

void mmu_load() {
	FILE *ptr;
	ptr = fopen("tetris.gb","rb");
	if (ptr) {
		fread(mmu_.rom,64*1024,1,ptr);
		fclose(ptr);
		mmu_.carttype = mmu_.rom[0x0147];
		printf("mmu rom loaded\n");
	}
	else {
		printf("mmu rom error\n");
	}
}

unsigned char mmu_rb(unsigned int addr) {
	//if(debug)printf("RB ____: %04x\n", addr);
	switch (addr&0xF000) {
		case 0x0000:
			if (mmu_.inbios) {
				if (addr<0x0100) {
					return bios[addr]; // bios
				}
				else if (reg.pc==0x0100) {
					mmu_.inbios = 0; // leaving bios
					printf("mmu exit bios\n");
				}
			}
			else {
				return mmu_.rom[addr]; // rombank 0
			}
			
		case 0x1000:
		case 0x2000: 
		case 0x3000:
			return mmu_.rom[addr]; // rombank 0
			
		case 0x4000:
		case 0x5000:
		case 0x6000:
		case 0x7000:
			return mmu_.rom[mmu_.romoffs+(addr&0x3FFF)]; // rombank 1
			
		case 0x8000:
		case 0x9000:
			//if(debug)printf("RB VRAM: %04x\n", addr);
			return gpu_.vram[addr&0x1FFF]; // gpu vram

		case 0xA000:
		case 0xB000:
			return mmu_.eram[mmu_.ramoffs+(addr&0x1FFF)]; // eram
			
		case 0xC000:
		case 0xD000:
		case 0xE000:
			//if(addr==0xd014)printf("WRAM READ: %04x\n", addr);
			return mmu_.wram[addr&0x1FFF]; // wram 0xC000-0xDFFF | wram shadow 0xE000-0xEFFF
			
		case 0xF000:
			switch (addr&0x0F00) {
				case 0x000:
				case 0x100:
				case 0x200:
				case 0x300:
				case 0x400:
				case 0x500:
				case 0x600:
				case 0x700:
				case 0x800:
				case 0x900:
				case 0xA00:
				case 0xB00:
				case 0xC00:
				case 0xD00:
					return mmu_.wram[addr&0x1FFF]; // wram shadow 0xF000-0xFDFF
				
				case 0xE00:
					if ((addr&0xFF)<0xA0) {
						//if(debug)printf("RB _OAM: %04x\n", addr);
						return gpu_.oam[addr&0xFF]; // gpu oam
					}
					else
						return 0;
					
				case 0xF00:
					{
						if (addr==0xFF00) {
							//printf("R_KEYS %04x\n", reg.pc);
							return key_rb(); // keyboard
						}
						if (addr==0xFF0F) {
							return mmu_.if_; // interrupt flags
						}
						switch (addr&0xF0) {
							case 0x00: {
								switch (addr&0xf) {
									case 4:
									case 5:
									case 6:
									case 7:
										printf("READ TO TIMER\n");
										return timer_rb(addr);
									default:
										return 0;
								}
							}
							
							case 0x10:
							case 0x20:
								return 0; // sound
							
							case 0x40:
							case 0x50:
							case 0x60:
							case 0x70:
								//if(debug)printf("RB _GPU: %04x\n", addr);
								return gpu_rb(addr); // gpu read byte

							case 0x80:
							case 0x90:
							case 0xA0:
							case 0xB0:
							case 0xC0:
							case 0xD0:
							case 0xE0:
							case 0xF0:
								if (addr==0xFFFF) {
									return mmu_.ie_; // interrupt something?
								}
								else {
									//if(addr==0xffb3)printf("READ ZRAM B3\n");
									//if(debug)printf("ZRAM %04x\n", addr);
									return mmu_.zram[addr&0x7F]; // zram
								}
							default:
								//printf("READ DEFAULTED %04x\n", addr);
								return 0;
						}
					}
			}
	}
}
unsigned int mmu_rw(unsigned int addr) {
	return (mmu_rb(addr) | (mmu_rb(addr+1)<<8));
}

void mmu_wb(unsigned int addr, unsigned char val) {
	//if(debug)printf("WB ____: %04x %02x\n", addr, val);
	switch (addr&0xF000) {
		case 0x0000:
		case 0x1000:
			if (mmu_.carttype==1)
				mmu_.mbc_.ramon = ((val&0xF)==0xA)?1:0; // turn eram on
			break;
			
		case 0x2000: 
		case 0x3000:
			if (mmu_.carttype=1) {
				mmu_.mbc_.rombank &= 0x60;
				val &= 0x1F;
				if (!val)
					val = 1;
				mmu_.mbc_.rombank |= val;
				mmu_.romoffs = mmu_.mbc_.rombank*0x4000; // rom bank switch 
			}
			break;
			
		case 0x4000:
		case 0x5000:
			if (mmu_.carttype==1) {
				if (mmu_.mbc_.mode) {
					mmu_.mbc_.rambank = (val&3);
					mmu_.ramoffs = mmu_.mbc_.rambank*0x2000; // ram bank switch
				}
				else {
					mmu_.mbc_.rombank &= 0x1F;
					mmu_.mbc_.rombank |= ((val&3)<<5);
					mmu_.romoffs = mmu_.mbc_.rombank*0x4000;
				}
			}
			break;
			
		case 0x6000:
		case 0x7000:
			if (mmu_.carttype==1) 
				mmu_.mbc_.mode = val&1;
			break;
			
		case 0x8000:
		case 0x9000:
			gpu_.vram[addr&0x1FFF] = val;
			gpu_update_tile(addr&0x1FFF);
			//if(debug)printf("WB VRAM: %04x %02x\n", addr, val);
			break; // gpu vram
	
		case 0xA000:
		case 0xB000:
			mmu_.eram[mmu_.ramoffs+(addr&0x1FFF)] = val; // eram
			break;
			
		case 0xC000:
		case 0xD000:
		case 0xE000:
			mmu_.wram[addr&0x1FFF] = val; // wram 0xC000-0xDFFF | wram shadow 0xE000-0xEFFF
			break;
			
		case 0xF000:
			switch (addr&0x0F00) {
				case 0x000:
				case 0x100:
				case 0x200:
				case 0x300:
				case 0x400:
				case 0x500:
				case 0x600:
				case 0x700:
				case 0x800:
				case 0x900:
				case 0xA00:
				case 0xB00:
				case 0xC00:
				case 0xD00:
					mmu_.wram[addr&0x1FFF] = val; // wram shadow 0xF000-0xFDFF
					break;
				
				case 0xE00:
					if ((addr&0xFF)<0xA0) {
						gpu_.oam[addr&0xFF] = val; // gpu oam
						gpu_update_oam(addr, val);
						//if(debug)printf("WB _OAM: %04x %02x\n", addr, val);
					}
					break;
					
				case 0xF00:
					{
						if (addr==0xFF00) {
							//printf("W_KEYS %04x\n", reg.pc);
							key_wb(val);
							break; // keyboard todo todo todo todo todo
						}
						if (addr==0xFF0F) {
							mmu_.if_ = val; // interrupt flags
							break;
						}
						
						switch (addr&0xF0) {
							case 0x00: {
								switch (addr&0xf) {
									case 4:
									case 5:
									case 6:
									case 7:
										printf("WRITE TO TIMER %04x %02x\n", addr, val);
										timer_wb(addr, val);
										break;
								}
								break;
							}
							case 0x10:
							case 0x20:
								break; // sound
							
							case 0x40:
							case 0x50:
							case 0x60:
							case 0x70:
								//if(debug)printf("WB _GPU: %04x %02x\n", addr, val);
								gpu_wb(addr, val);
								break; // gpu write byte
							case 0x80:
							case 0x90:
							case 0xA0:
							case 0xB0:
							case 0xC0:
							case 0xD0:
							case 0xE0:
							case 0xF0:
								if (addr==0xFFFF) {
									mmu_.ie_ = val; // interrupt something?
								}
								else {
									mmu_.zram[addr&0x7F] = val; // zram
								}
								break;
							default:
								//printf("WRITE DEFAULTED %04x %02x\n", addr, val);
								break;
						}
					}
			}
	}
}
void mmu_ww(unsigned int addr, unsigned short val) {
	mmu_wb(addr, val&255);
	mmu_wb(addr+1, val>>8);
}
