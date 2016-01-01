/*
*More panic Functions
*(c) 2015 Zachary James Schlotman
*Zachary Schlotman
*/
#include "panic.h"
void panic(){
	t_init();
	kprintf("A fatal error has been encountered in the kernel. Panic has been called.\n");
	kprintf("Continuing is not possible or is dangerous\n");
	kprintf("minOS kernel\n");
	kprintf("If you are getting a panic it is most likely that your hardware is not supported.\nThis works best in QEMU\n");
	kprintf("This build will NOT continue after a panic.");
	dump_args("NULL");
	debug("KERNEL","panic_shell()");
	panic_shell();
	//#ifndef NOPANIC
	while(1){ }
	//#endif
	//_panic();
}
void panic_shell(){
	debug("panic_shell","Init");
	char *buf = malloc(1024);
	while(1){
		kprintf("\n>");
		kstrcpy(buf,kgets());
		debug("panic_shell",buf);
		if(strncmp(buf,"ps ",3) == 0){
			kprintf("Sole process is kernel");
		}
		else if(strcmp(buf,"whoami") == 0){
			kprintf("Kernel");
		}
		else if(strcmp(buf,"help") == 0){
			kprintf("whoami,help,hlt");
		}
		else if(strcmp(buf,"hlt") == 0){
			while(1){asm volatile("hlt"); };
		}
		buf = malloc(1024);
	}
}
void __panic(char *reason){
	kprintf("A fatal error has been encountered in the kernel.__panic(reason)\n");
	kprintf("Panic Reason:%s\n",reason);
	dump_args(reason);
	debug("KERNEL","Hang");
	//while(1){ };
	panic();
}
