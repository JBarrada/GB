#include <stdint.h>

extern void setup_vga();
extern void setup_palette_gb();
extern void demobars();
extern void write_pixel_frame(unsigned char *d);
extern void draw_gb();

extern unsigned int clock;

extern inline unsigned char inportb(unsigned int port);
extern inline void outportb(unsigned int port, unsigned char value);

#define TICKS 59659
unsigned long s_low, s_high;
static int cpuspeed(void) {
	int loops;
	unsigned long end_low, end_high;

	/* Setup timer */
	outportb((inportb(0x61) & ~0x02) | 0x01, 0x61);
	outportb(0xb0, 0x43); 
	outportb(TICKS & 0xff, 0x42);
	outportb(TICKS >> 8, 0x42);

	asm __volatile__ ("rdtsc":"=a" (s_low),"=d" (s_high));

	loops = 0;
	do {
		loops++;
	} while ((inportb(0x61) & 0x20) == 0);

	asm __volatile__ (
		"rdtsc\n\t" \
		"subl s_low,%%eax\n\t" \
		"sbbl s_high,%%edx\n\t" \
		:"=a" (end_low), "=d" (end_high)
	);

	unsigned long clks_msec = end_low/50;
	return(clks_msec);
}

uint64_t rdtsc() {
	unsigned a, d;
	asm volatile("rdtsc" : "=a" (a), "=d" (d));
	return ((uint64_t)a) | (((uint64_t)d) << 32);
}

void kernel_main() {
	setup_vga();
	setup_palette_gb();
	
	draw_gb();
	
	cpu_reset();
	mmu_reset();
	gpu_reset();
	mmu_load();

	uint64_t clocks_per_milli = cpuspeed();
	uint64_t start_time, start_clock;
	
	while (1) {
		start_time = rdtsc();
		start_clock = clock;
		
		while (clock-start_clock<1000)
			exec();

		while ((rdtsc()-start_time)<clocks_per_milli) {}
	}
		
}
