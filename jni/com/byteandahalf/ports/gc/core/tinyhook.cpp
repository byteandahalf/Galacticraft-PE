#include "sys/mman.h"

void tiny_hook(uint32_t* addr, uint32_t hook) {
	mprotect(addr, 8, PROT_READ | PROT_WRITE);
	bool thumb = (uint32_t)addr & 1;
	if(thumb)
		addr = (uint32_t*) ((uint32_t) addr - 1);
	*addr = (uint32_t) (thumb)? 0xF000F8DF : 0xE59FF000; // LDR PC, [PC]
	*(++addr) = hook;
	mprotect(addr, 8, PROT_READ | PROT_EXEC);
}

