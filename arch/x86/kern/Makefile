
NASM=nasm -f elf

all:
	@echo "AS chanload.o"
	$(NASM) chainload.asm -o chainload.o
	@echo "AS goreal.o"
	@$(NASM) goreal.asm -o goreal.o
	@echo "AS jmp.o"
	@$(CC) -c jmp.S -o jmp.o -nostdlib -Werror
	@echo "CC kmain.o"
	@$(CC) -c kmain.c -o kmain.o -nostdlib -Werror -I../include -ffreestanding -std=gnu99 -I../fs/zfs -g $(KMAIN_CFLAGS) -fmax-errors=1 -DKBUILD
	@echo "CC kloader.o"
	@$(CC) -c kloader.c -o kloader.o -nostdlib -Werror -I../include -ffreestanding -std=gnu99 -g $(KMAIN_CFLAGS);
	@echo "BINAS bootloader.bin"
	@$(NASM) -f bin bootloader.asm -o bootloader.bin -g
	@echo "CC kernel.o"
	@$(CC) -c kernel.c -o kernel.o -nostdlib -I../include -Werror -ffreestanding -std=gnu99 -g
	@echo "CC tty.o"
	@$(CC) -c tty.c -o tty.o -nostdlib -I../include -ffreestanding -Werror -std=gnu99 -g
	@echo "AS boot.o"
	@$(AS) boot.S -o boot.o -g
	@echo "AS crti.o"
	@$(AS) crti.S -o crti.o  -g
	@echo "AS crtn.o"
	@$(AS) crtn.S -o crtn.o -g
	@echo "AS halt.o"
	@$(AS) halt.S -o halt.o -g
	@echo "NASM inportb.o"
	@echo "CC init.o"
	@$(CC) -c init.c -o init.o -g -Werror
	@$(NASM) inportb.asm -o inportb.o -g
	@echo "CC xc.o"
	@$(CC)  -c xw.c -o xw.o -nostdlib -g -I../include -Werror -ffreestanding
	@echo "CC panic.o"
	@$(CC) -c panic.c -o panic.o -nostdlib -Werror -g  -I../include -ffreestanding
	@echo "AS bootl.o"
	@$(NASM) -f elf bootl.asm -o bootl.o -g
	@echo "CC shell.o"
	@$(CC) -c shell.c -o shell.o  -std=c99 -nostdlib -g -Werror  -ffreestanding -I../include
	@echo "CC mod.o"
	@$(CC) -c add_module.c -o mod.o -nostdlib -ffreestanding -Werror -I../include
	@echo "AS rm.o"
	@$(NASM) -f elf rm.asm -o rm.o
	@echo "CC reboot.c"
	@$(CC) -c reboot.c -o reboot.o -ffreestanding -nostdlib -Werror
	@echo "BINAS zero.bin"
	@$(NASM) -f bin zero.asm -o zero.bin
	@echo "NASM initgui.o"
	@$(NASM) -f elf initgui.asm -o initgui.o
	@echo "NASM int32.o"
	@$(NASM) -f elf int32.asm -o int32.o
	@echo "AS yourboot.o"
	@$(AS) yourboot.S -o yourboot.o
	@echo "CC yourkernel.o"
	@$(CC) -c yourkernel.c -o yourkernel.o -nostdlib -I../include -Werror
#	@$(AS) rm.S -o rm.o
clean:
	rm *.o
