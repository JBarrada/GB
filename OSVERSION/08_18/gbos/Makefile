AS=/home/swdev/cross-compile/i686-elf-as
CC=/home/swdev/cross-compile/usr/bin/i686-elf-gcc

INCLS=-Icpu/ -Immu/ -Igpu/

all: clean gb.iso

boot.o: boot.s
	$(AS) boot.s -o $@
	
memcpy.o: machine/memcpy.S
	$(CC) -c machine/memcpy.S -o $@
memset.o: machine/memset.S
	$(CC) -c machine/memset.S -o $@

cpu.o: cpu/cpu.c
	$(CC) -c cpu/cpu.c -o $@ $(INCLS) -O3
	
mmu.o: mmu/mmu.c
	$(CC) -c mmu/mmu.c -o $@ $(INCLS) -O3
	
gpu.o: gpu/gpu.c
	$(CC) -c gpu/gpu.c -o $@ $(INCLS) -O3
	
rom.o: rom.gb
	objcopy -B i386 -I binary -O elf32-i386 rom.gb $@
	
timer.o: timer/timer.c
	$(CC) -c timer/timer.c -o $@ $(INCLS) -O3

key.o: key/key.c
	$(CC) -c key/key.c -o $@ $(INCLS) -O3
	
vga.o: vga.c
	$(CC) -c vga.c -o $@ -O3
	
kernel.o: kernel.c
	$(CC) -c kernel.c -o $@ -std=gnu99 -ffreestanding -O3 -Wall -Wextra
	
gb.bin: linker.ld vga.o cpu.o rom.o mmu.o gpu.o timer.o key.o memset.o memcpy.o kernel.o boot.o
	$(LD) -T linker.ld vga.o cpu.o rom.o mmu.o gpu.o timer.o key.o memset.o memcpy.o kernel.o boot.o -o $@
	
	
gb.iso: grub.cfg gb.bin
	mkdir -p isodir
	mkdir -p isodir/boot
	cp gb.bin isodir/boot/gb.bin
	mkdir -p isodir/boot/grub
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o $@ isodir
	rm -R isodir
	
clean:
	rm -f *.o *.iso gb.bin
