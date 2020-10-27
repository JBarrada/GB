del cpu.o
del mmu.o
del gpu.o
del key.o
del gb.exe
del debug.csv
del screen.txt
gcc -c cpu/cpu.c -o cpu.o -Icpu\ -Immu\ -Igpu\
gcc -c mmu/mmu.c -o mmu.o -Icpu\ -Immu\ -Igpu\
gcc -c gpu/gpu.c -o gpu.o -Icpu\ -Immu\ -Igpu\
gcc -c timer/timer.c -o timer.o -Icpu\ -Immu\ -Igpu\
gcc -c key/key.c -o key.o
gcc test.c cpu.o mmu.o gpu.o timer.o key.o -o gb.exe
del cpu.o
del mmu.o
del gpu.o
del key.o
gb.exe