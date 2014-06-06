#include <common_datatypes.h>

#include "utilities.h"

#include "include/rom_functions.h"
#include "include/mbr.h"

#define MBR_CODESIZE 0x1BE
#define MBR_PTABLE_ADDR (__BTLDRADDR__ + MBR_CODESIZE)
#define CPM_PARTITION_TYPE 0xDB

static MBRStruct *mbr;

void sys_init(void);
void sys_boot(uint8_t pNo);
void print_string(const char *str);
void monitor_jmp(uint8_t *addr);

void sys_init(void) {
	// Prepare the pointers to rom functions
	getchar = (rom_getchar)(*(uint8_t*)(ROM_TABLE_BASE-4));
	putchar = (rom_putchar)(*(uint8_t*)(ROM_TABLE_BASE-2));

	n8vem_ide_init = (rom_n8vem_ide_init)(*(uint8_t*)(ROM_TABLE_BASE-12));
	n8vem_ide_read = (rom_n8vem_ide_read)(*(uint8_t*)(ROM_TABLE_BASE-6));
	n8vem_ide_reg_rd = (rom_n8vem_ide_reg_rd)(*(uint8_t*)(ROM_TABLE_BASE-10));
	n8vem_ide_reg_wr = (rom_n8vem_ide_reg_wr)(*(uint8_t*)(ROM_TABLE_BASE-8));

	mbr = (MBRStruct*)__BTLDRADDR__;
}

void print_string(const char *str) {
	while(*str)
		putchar(*(str++));
}

void sys_boot(uint8_t pNo) {
	uint8_t ch, cl, sect, head;

	head = mbr->partitions[pNo].chs_start_addr[0];
	ch = mbr->partitions[pNo].chs_start_addr[1] >> 6;
	cl = mbr->partitions[pNo].chs_start_addr[2];
	sect = mbr->partitions[pNo].chs_start_addr[1] & 0x3F;

	// TODO: Read the sectors and jump the execution to them.
}

void main(void) {
	uint8_t pNum;

	sys_init();

	for (pNum = 0; pNum < 4; pNum++) {
		if (mbr->partitions[pNum].type == CPM_PARTITION_TYPE) {
			sys_boot(pNum);
		}
	}

	// Nothing to do, jumping back to the monitor
	__asm
		jp 0xF000
	__endasm;
}

void monitor_jmp(uint8_t *addr) __naked {
	addr;

	__asm
		pop bc
		pop hl
		jp (hl)
	__endasm;
}
