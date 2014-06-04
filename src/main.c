#include <common_datatypes.h>

#include "utilities.h"
#include "rom/rom_functions.h"

#define MBR_CODESIZE 0x1BE
#define MBR_PTABLE_ADDR (__BTLDRADDR__ + MBR_CODESIZE)

void sys_init(void);

void sys_init(void) {
	// Prepare the pointers to rom functions
	getchar = (rom_getchar)(*(uint8_t*)(ROM_TABLE_BASE-4));
	putchar = (rom_putchar)(*(uint8_t*)(ROM_TABLE_BASE-2));

	n8vem_ide_init = (rom_n8vem_ide_init)(*(uint8_t*)(ROM_TABLE_BASE-12));
	n8vem_ide_read = (rom_n8vem_ide_read)(*(uint8_t*)(ROM_TABLE_BASE-6));
	n8vem_ide_reg_rd = (rom_n8vem_ide_reg_rd)(*(uint8_t*)(ROM_TABLE_BASE-10));
	n8vem_ide_reg_wr = (rom_n8vem_ide_reg_wr)(*(uint8_t*)(ROM_TABLE_BASE-8));
}

void main(void) {
	sys_init();

	while(1) { // Endless loop
		;
	}
}

