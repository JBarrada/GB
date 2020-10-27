#define	VGA_AC_INDEX		0x3C0
#define	VGA_AC_WRITE		0x3C0
#define	VGA_MISC_WRITE		0x3C2
#define VGA_SEQ_INDEX		0x3C4
#define VGA_SEQ_DATA		0x3C5
#define VGA_GC_INDEX 		0x3CE
#define VGA_GC_DATA 		0x3CF

#define VGA_CRTC_INDEX		0x3D4
#define VGA_CRTC_DATA		0x3D5
#define	VGA_INSTAT_READ		0x3DA

#define	VGA_NUM_SEQ_REGS	5
#define	VGA_NUM_CRTC_REGS	25
#define	VGA_NUM_GC_REGS		9
#define	VGA_NUM_AC_REGS		21

#include "gbbg/gb_onelayer.h"

unsigned char* video_buffer = (char*) 0xA0000;

unsigned char g_640x480x16[] = {
/* MISC */
	0xE3,
/* SEQ */
	0x03, 0x01, 0x08, 0x00, 0x06,
/* CRTC */
	0x5F, 0x4F, 0x50, 0x82, 0x54, 0x80, 0x0B, 0x3E,
	0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xEA, 0x0C, 0xDF, 0x28, 0x00, 0xE7, 0x04, 0xE3,
	0xFF,
/* GC */
	0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x05, 0x0F,
	0xFF,
/* AC */
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x14, 0x07,
	0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
	0x01, 0x00, 0x0F, 0x00, 0x00
};

inline unsigned char inportb(unsigned int port) {
   unsigned char ret;
   asm volatile ("inb %%dx,%%al":"=a" (ret):"d" (port));
   return ret;
}
inline void outportb(unsigned int port, unsigned char value) {
   asm volatile ("outb %%al,%%dx": :"d" (port), "a" (value));
}

void write_regs(unsigned char *regs) {
	unsigned i;

/* write MISCELLANEOUS reg */
	outportb(VGA_MISC_WRITE, *regs);
	regs++;
/* write SEQUENCER regs */
	for(i = 0; i < VGA_NUM_SEQ_REGS; i++)
	{
		outportb(VGA_SEQ_INDEX, i);
		outportb(VGA_SEQ_DATA, *regs);
		regs++;
	}
/* unlock CRTC registers */
	outportb(VGA_CRTC_INDEX, 0x03);
	outportb(VGA_CRTC_DATA, inportb(VGA_CRTC_DATA) | 0x80);
	outportb(VGA_CRTC_INDEX, 0x11);
	outportb(VGA_CRTC_DATA, inportb(VGA_CRTC_DATA) & ~0x80);
/* make sure they remain unlocked */
	regs[0x03] |= 0x80;
	regs[0x11] &= ~0x80;
/* write CRTC regs */
	for(i = 0; i < VGA_NUM_CRTC_REGS; i++)
	{
		outportb(VGA_CRTC_INDEX, i);
		outportb(VGA_CRTC_DATA, *regs);
		regs++;
	}
/* write GRAPHICS CONTROLLER regs */
	for(i = 0; i < VGA_NUM_GC_REGS; i++)
	{
		outportb(VGA_GC_INDEX, i);
		outportb(VGA_GC_DATA, *regs);
		regs++;
	}
/* write ATTRIBUTE CONTROLLER regs */
	for(i = 0; i < VGA_NUM_AC_REGS; i++)
	{
		(void)inportb(VGA_INSTAT_READ);
		outportb(VGA_AC_INDEX, i);
		outportb(VGA_AC_WRITE, *regs);
		regs++;
	}
/* lock 16-color palette and unblank display */
	(void)inportb(VGA_INSTAT_READ);
	outportb(VGA_AC_INDEX, 0x20);
}

void set_plane(unsigned p) {
	unsigned char pmask;

	p &= 3;
	pmask = 1 << p;
/* set read plane */
	outportb(VGA_GC_INDEX, 4);
	outportb(VGA_GC_DATA, p);
/* set write plane */
	outportb(VGA_SEQ_INDEX, 2);
	outportb(VGA_SEQ_DATA, pmask);
}

void write_pixel_row(unsigned int y, unsigned char *d) {
	unsigned int p, i, di;
	char plane_bits[80];
	int off = 80 * y;
	for(p = 0; p < 4; p++) {
		set_plane(p);
		for (i=0; i<80; i++) {
			di = i*8;
			plane_bits[i] = ((d[di] >> p) & 1) << 7 | ((d[di+1] >> p) & 1) << 6 | ((d[di+2] >> p) & 1) << 5 | ((d[di+3] >> p) & 1) << 4 | ((d[di+4] >> p) & 1) << 3 | ((d[di+5] >> p) & 1) << 2 | ((d[di+6] >> p) & 1) << 1 | ((d[di+7] >> p) & 1);
		}
		memcpy(video_buffer+off, plane_bits, 80);
	}
}

void write_pixel_frame(unsigned char *d) {
	unsigned int p, i, di;
	char plane_bits[38400];
	for(p = 0; p < 4; p++) {
		set_plane(p);
		for (i=0; i<38400; i++) {
			di = i*8;
			plane_bits[i] = ((d[di] >> p) & 1) << 7 | ((d[di+1] >> p) & 1) << 6 | ((d[di+2] >> p) & 1) << 5 | ((d[di+3] >> p) & 1) << 4 | ((d[di+4] >> p) & 1) << 3 | ((d[di+5] >> p) & 1) << 2 | ((d[di+6] >> p) & 1) << 1 | ((d[di+7] >> p) & 1);
		}
		memcpy(video_buffer, plane_bits, 38400);
	}
}

void write_160_144(unsigned int y, unsigned int x, unsigned char *d) {
	unsigned int p, i, di, yend, y_d;
	char plane_bits[20];
	yend = y+144;
	
	int off;
	y_d = 0;
	for (y=y; y<yend; y++) {
		off = 80 * y + 30; // todo x
		for(p = 0; p < 4; p++) {
			set_plane(p);
			for (i=0; i<20; i++) {
				di = i*8 + (y_d*160);
				plane_bits[i] = ((d[di] >> p) & 1) << 7 | ((d[di+1] >> p) & 1) << 6 | ((d[di+2] >> p) & 1) << 5 | ((d[di+3] >> p) & 1) << 4 | ((d[di+4] >> p) & 1) << 3 | ((d[di+5] >> p) & 1) << 2 | ((d[di+6] >> p) & 1) << 1 | ((d[di+7] >> p) & 1);
			}
			memcpy(video_buffer+off, plane_bits, 20);
		}
		y_d++;
	}
	
}


void set_palette_color(unsigned char color, unsigned char r, unsigned char g, unsigned char b) {
	outportb(0x03C6,0xff);
	outportb(0x03C8,color);
	outportb(0x03C9,r);
	outportb(0x03C9,g);
	outportb(0x03C9,b);
}

void setup_palette_gb() {

	unsigned int hsv[16] = {0x000000, 0x7d0b43, 0x585962, 0x826a7a, 0x9b9d99, 0xbbbdba, 0x000000, 0x000000, 
							0x9C9715, 0x66630E, 0x3B3908, 0x1C1B04, 0x000000, 0x000000, 0x000000, 0x000000};
	unsigned int color_index[16] = { 0,  1,  2,  3,  4,  5, 20, 7, 
									56, 57, 58, 59, 60, 61, 62, 63};	
	int i;
	for (i=0; i<16; i++) {
		set_palette_color(color_index[i], ((hsv[i]>>16)&0xff)/4, ((hsv[i]>>8)&0xff)/4, ((hsv[i]>>0)&0xff)/4);
	}
}

void demobars() {
	int y, i;
	unsigned char color[640];
	for (y=0; y<480; y++) {
		for (i=0;i<640;i++)
			color[i] = y / 30;
		write_pixel_row(y, color);
	}
}

int que = 0;
unsigned char visual[640];
void que_visual() {
	memset(visual, que, 640);
	int i;
	for (i=0; i<4; i++)
		write_pixel_row(i, (unsigned char*)visual);
	que++;
	if (que==4)
		que = 0;
}

void setup_vga() {
	write_regs(g_640x480x16);
}

void draw_gb() {
	write_pixel_frame((unsigned char*)header_data);
}
