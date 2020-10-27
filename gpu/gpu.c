#include <stdio.h>
#include "gpu.h"

extern registers reg;


void gpu_reset() {
	int i, j, k;
	
	for (i=0;i<8*1024; i++)
		gpu_.vram[i] = 0;
	
	for (i=0;i<160; i++)
		gpu_.oam[i] = 0;
	
	for (i=0; i<4; i++) {
      gpu_.palette_.bg[i] = 255;
      gpu_.palette_.obj0[i] = 255;
      gpu_.palette_.obj1[i] = 255;
    }
	
	for (i=0; i<512; i++) {
      for (j=0; j<8; j++) {
        for (k=0; k<8; k++) {
          gpu_.tilemap[i][j][k] = 0;
        }
      }
    }
	
	// init screen
	
	gpu_.curline=0;
    gpu_.curscan=0;
    gpu_.linemode=2;
    gpu_.modeclocks=0;
    gpu_.yscrl=0;
    gpu_.xscrl=0;
    gpu_.winy=0;
    gpu_.winx=0;
    gpu_.raster=0;
    gpu_.ints=0;
    gpu_.intfired=0;

    gpu_.lcdon = 0;
    gpu_.bgon = 0;
    gpu_.objon = 0;
    gpu_.winon = 0;
	
	gpu_.objsize = 0;
	
	for(i=0; i<160; i++) gpu_.scanrow[i] = 0;
	
	for(i=0; i<40; i++) {
	  gpu_.objdata[i].y = -16;
	  gpu_.objdata[i].x = -8;
	  gpu_.objdata[i].tile = 0;
	  gpu_.objdata[i].palette = 0;
	  gpu_.objdata[i].yflip = 0;
	  gpu_.objdata[i].xflip = 0;
	  gpu_.objdata[i].prio = 0;
	  gpu_.objdata[i].num = i;
    }
	
	gpu_.bgtilebase = 0x0000;
    gpu_.bgmapbase = 0x1800;
    gpu_.winmapbase = 0x1800;
}

void gpu_checkline() {
	gpu_.modeclocks += reg.m;
	
	switch (gpu_.linemode) {
		case 0: // in hblank
			if(gpu_.modeclocks >= 51) {
				
				if(gpu_.curline == 143) { // end of hblank for last scanline
					gpu_.linemode = 1;
					// render screen
					
					mmu_.if_ |= 1;
					if(gpu_.ints&2) {
						gpu_.intfired|=2; 
						mmu_.if_|=2; 
					}
				}
				else {
					gpu_.linemode = 2;
					if(gpu_.ints&4) { 
						gpu_.intfired|=4; 
						mmu_.if_|=2;
					}
				}
				
				gpu_.curline++;
				
				if(gpu_.curline == gpu_.raster) {
					if(gpu_.ints&8) { 
						gpu_.intfired|=8; 
						mmu_.if_|=2; 
					}
				}
				
				gpu_.curscan += 640;
				gpu_.modeclocks = 0;
			}
			break;
		
		case 1: // in vblank
		    if(gpu_.modeclocks >= 114) {
				
				gpu_.modeclocks = 0;
				gpu_.curline++;
				
				if(gpu_.curline > 153) {
					gpu_.curline = 0;
					gpu_.curscan = 0;
					gpu_.linemode = 2;
				}

				if(gpu_.ints&4) { 
					gpu_.intfired|=4; 
					mmu_.if_|=2; 
				}
			}
			break;
			
		case 2: // in oam-read mode
			if(gpu_.modeclocks >= 20) {
			  gpu_.modeclocks = 0;
			  gpu_.linemode = 3;
			}
			break;
			
		case 3: // in vram-read mode
			if(gpu_.modeclocks >= 43) {
				gpu_.modeclocks = 0;
				gpu_.linemode = 0;
				if(gpu_.ints&1) { 
					gpu_.intfired|=1; 
					mmu_.if_|=2; 
				}
				
				if(gpu_.lcdon) { // render scanline
					if (gpu_.bgon) {
						int mapoffs = gpu_.bgmapbase + ((((gpu_.curline+gpu_.yscrl)&255)>>3)<<5);
						int lineoffs = gpu_.xscrl>>3;
						int y = (gpu_.curline+gpu_.yscrl)&7;
						int x = gpu_.xscrl&7;
						int tile = gpu_.vram[mapoffs+lineoffs];
						
						if(gpu_.bgtilebase == 0x800 && tile < 128) tile += 256;
						
						int w;
						for (w=0; w<160; w++) {
							scrn[gpu_.curline][w] = gpu_.tilemap[tile][y][x];
							
							x++;
							if (x==8) {
								x = 0;
								lineoffs = (lineoffs+1)&31;
								tile = gpu_.vram[mapoffs+lineoffs];
								if(gpu_.bgtilebase == 0x800 && tile < 128) tile += 256;
							}
						}
						
						/*
						int mapbase = gpu_.bgmapbase + ((((gpu_.curline+gpu_.yscrl)&255)>>3)<<5);
						int y = (gpu_.curline+gpu_.yscrl)&7;
						int x = gpu_.xscrl&7;
						int t = (gpu_.xscrl>>3)&31;
						int w=160;
						
						if (gpu_.bgtilebase) {
							int tile = gpu_.vram[mapbase+t];
							if(tile<128) 
								tile = 256+tile;
							
							do {
								gpu_.scanrow[160-x] = gpu_.tilemap[tile][y][x];
								scrn[gpu_.curline][160-w] = gpu_.tilemap[tile][y][x];
								
								x++;
								if (x==8) {
									t = (t+1)&31;
									x = 0;
									tile = gpu_.vram[mapbase+t];
									if(tile<128) 
										tile = 256+tile;
								}
							} while (--w);
						}
						else {
							do {
								gpu_.scanrow[160-x] = gpu_.tilemap[gpu_.vram[mapbase+t]][y][x];
								scrn[gpu_.curline][160-w] = gpu_.tilemap[gpu_.vram[mapbase+t]][y][x];
								
								x++;
								if (x==8) {
									t = (t+1)&31;
									x = 0;
								}
							} while (--w);
						}
						*/
					}
					if (gpu_.objon) {
						int count = 0;
						if (gpu_.objsize) {
							// loop?
						}
						else {
							int tilerow[8];
							obj obj_;
							int x;
							int screen_x;
							
							int i, yf;
							for (i=0; i<40; i++) {
								obj_ = gpu_.objdatasorted[i];
								if ((obj_.y <= gpu_.curline) && ((obj_.y+8) > gpu_.curline)) {
									
									if (obj_.yflip) {
										for (yf=0; yf<8; yf++) {
											tilerow[yf] = gpu_.tilemap[obj_.tile][7-(gpu_.curline-obj_.y)][yf];
										}
									}
									else {
										for (yf=0; yf<8; yf++) {
											tilerow[yf] = gpu_.tilemap[obj_.tile][gpu_.curline-obj_.y][yf];
										}
									}
									
									screen_x = obj_.x;
									
									if (obj_.xflip) {
										for (x=0; x<8; x++) {
											if (obj_.x+x >= 0 && obj_.x+x < 160) {
												if (tilerow[7-x] && (obj_.prio || !gpu_.scanrow[x])) {
													//GPU._scrn.data[linebase + 3] = pal[tilerow[7 - x]];
													scrn[gpu_.curline][screen_x] = tilerow[7-x];
												}
											}
											screen_x++;
										}
									} 
									else {
										for (x=0; x<8; x++) {
											if (obj_.x+x >= 0 && obj_.x+x < 160) {
												if (tilerow[x] && (obj_.prio || !gpu_.scanrow[x])) {
													//GPU._scrn.data[linebase + 3] = pal[tilerow[x]];
													scrn[gpu_.curline][screen_x] = tilerow[x];
												}
											}
											screen_x++;
										}
									}
									
									count++;
									if (count>10) 
										break;
								}
							}
						}
					}
				}
			}
			break;
	}
}


void gpu_update_tile(unsigned int addr) {
	//printf("UPDATE TILE: %04x\n", addr);
	unsigned int saddr = addr;
	if (addr&1) { // ensure saddr and addr are even numbers
		saddr--;
		addr--;
	}
	
	// get affected tile number
	// 16bp tile...				divide by 16 to get affected tile
	unsigned int tile = (addr>>4)&511; 
	
	// get y location in tile
	// 2bp row or 8 pixels...	divide by 2 to affected row
	//
	unsigned int y = (addr>>1)&7; 
	
	
	unsigned int x, sx;
	
	for (x=0; x<8; x++) {
		
		sx = 1<<(7-x);
		// x-| sx-------
		// 0 | 1000 0000
		// 1 | 0100 0000
		// 2 | 0010 0000
		// 3 | 0001 0000
		// . | .... ....
		// 7 | 0000 0001
		
		gpu_.tilemap[tile][y][x] = ((gpu_.vram[saddr]&sx)?1:0) | ((gpu_.vram[saddr+1]&sx)?2:0);
	}
}


void gpu_update_oam(unsigned int addr, unsigned char val) {
	//printf("UPDATE OAM: %04x %02x\n", addr, val);
	
	addr-=0xFE00; // values relative to 0
    
	// get affected object
	// 4bp object... 	divide by 4 to get affected object
	unsigned int obj=addr>>2;
	
	if (obj<40) { // only 40 objects
		switch(addr&3) { // which of 4 object bytes is being written to
			case 0: 
				gpu_.objdata[obj].y=val-16; 
				break;
				
			case 1:
				gpu_.objdata[obj].x=val-8; 
				break;
				
			case 2:
				if (gpu_.objsize) 
					gpu_.objdata[obj].tile = (val&0xFE);
				else
					gpu_.objdata[obj].tile = val;
				break;
				
			case 3:
				gpu_.objdata[obj].palette = (val&0x10)?1:0;
				gpu_.objdata[obj].xflip = (val&0x20)?1:0;
				gpu_.objdata[obj].yflip = (val&0x40)?1:0;
				gpu_.objdata[obj].prio = (val&0x80)?1:0;
				break;
		}
	}
	
	int i;
	for (i=0; i<40; i++) {
		gpu_.objdatasorted[i] = gpu_.objdata[i];
		//if(debug)printf("D: %d %d\n", gpu_.objdata[i].num, gpu_.objdata[i].x);
	}
	
	//sort_objdatasorted();
}

void sort_objdatasorted() {
	int c, d;
	obj swap;
	
	for (c=0; c<(40-1); c++) {
		for (d=0; d<(40-c-1); d++) {
			if (gpu_.objdatasorted[d].x<gpu_.objdatasorted[d+1].x) {
				swap = gpu_.objdatasorted[d];
				gpu_.objdatasorted[d] = gpu_.objdatasorted[d+1];
				gpu_.objdatasorted[d+1] = swap;
			}
			/*
			if (gpu_.objdatasorted[d].num>gpu_.objdatasorted[d+1].num) {
				swap = gpu_.objdatasorted[d];
				gpu_.objdatasorted[d] = gpu_.objdatasorted[d+1];
				gpu_.objdatasorted[d+1] = swap;
			}
			*/
		}
	}
}


int gpu_rb(unsigned int addr) {
	int gaddr = addr-0xFF40;
	
	switch (gaddr) {
		case 0:
			return (gpu_.lcdon?0x80:0)|
				   ((gpu_.winmapbase==0x1C00)?0x40:0)|
				   (gpu_.winon?0x20:0)|
				   ((gpu_.bgtilebase==0x0000)?0x10:0)|
				   ((gpu_.bgmapbase==0x1C00)?0x08:0)|
				   (gpu_.objsize?0x04:0)|
				   (gpu_.objon?0x02:0)|
				   (gpu_.bgon?0x01:0);
				   
		case 1: {
			int intf = gpu_.intfired;
			gpu_.intfired = 0;
			return (intf<<3)|(gpu_.curline==gpu_.raster?4:0)|gpu_.linemode;
		}
			
		case 2:
			return gpu_.yscrl;
			
		case 3:
			return gpu_.xscrl;
			
		case 4:
			return gpu_.curline;
			
		case 5:
			return gpu_.raster;
			
		case 10:
			return gpu_.winy;
			
		case 11:
			return gpu_.winx+7;
			
		default:
			printf("GPU_REG: %04x\n", addr);
			return gpu_.reg[gaddr];
	}
}

void gpu_wb(unsigned int addr,unsigned char val) {
	int gaddr = addr-0xFF40;
	gpu_.reg[gaddr] = val;
	
	switch (gaddr) {
		case 0:
			gpu_.lcdon = (val&0x80)?1:0;
			gpu_.winmapbase = (val&0x40)?0x1C00:0x1800;
			gpu_.winon = (val&0x20)?1:0;
			gpu_.bgtilebase = (val&0x10)?0x0000:0x0800;
			gpu_.bgmapbase = (val&0x08)?0x1C00:0x1800;
			gpu_.objsize = (val&0x04)?1:0;
			gpu_.objon = (val&0x02)?1:0;
			gpu_.bgon = (val&0x01)?1:0;
			
			//if(debug)printf("winon: %d\n", val&0x20);
			
			break;
			
		case 1:
			gpu_.ints = (val>>3)&15;
			break;
			
		case 2:
			if(debug)printf("WRITETO Y SCROLL: %d | %08x\n", val, clock);
			gpu_.yscrl = val;
			break;
			
		case 3:
			if(debug)printf("WRITETO X SCROLL: %d | %08x\n", val, clock);
			gpu_.xscrl = val;
			break;
			
		case 5:
			printf("gpu raster\n");
			gpu_.raster = val;
			break;
			
		case 6: {
			int v, i;
			for(i=0; i<160; i++) {
			  v = mmu_rb((val<<8)+i);
			  gpu_.oam[i] = v;
			  gpu_update_oam(0xFE00+i, v);
			}
			break;
		}
			
		case 7: { // bg palette map
			int i;
			for(i=0;i<4;i++) {
				switch((val>>(i*2))&3) {
					case 0: gpu_.palette_.bg[i] = 255; break;
					case 1: gpu_.palette_.bg[i] = 192; break;
					case 2: gpu_.palette_.bg[i] = 96; break;
					case 3: gpu_.palette_.bg[i] = 0; break;
				}
			}
			break;
		}
			
		case 8: { // obj0 palette map
			int i;
			for(i=0;i<4;i++) {
				switch((val>>(i*2))&3) {
					case 0: gpu_.palette_.obj0[i] = 255; break;
					case 1: gpu_.palette_.obj0[i] = 192; break;
					case 2: gpu_.palette_.obj0[i] = 96; break;
					case 3: gpu_.palette_.obj0[i] = 0; break;
				}
			}
			break;
		}
			
		case 9: { // obj1 palette map
			int i;
			for(i=0;i<4;i++) {
				switch((val>>(i*2))&3) {
					case 0: gpu_.palette_.obj1[i] = 255; break;
					case 1: gpu_.palette_.obj1[i] = 192; break;
					case 2: gpu_.palette_.obj1[i] = 96; break;
					case 3: gpu_.palette_.obj1[i] = 0; break;
				}
			}
			break;
		}
			
		case 10:
			if(debug)printf("WRITETO Y WIN: %d\n", val);
			gpu_.winy = val;
			break;
		
		case 11:
			if(debug)printf("WRITETO X WIN: %d - 7\n", val);
			gpu_.winx = val-7;
			break;
			
		default:
			printf("GPU WB DEFAULTED %04x %02x\n", addr, val);

	}
}
