#include <common_datatypes.h>

#include "utilities.h"
#include "rom/rom_functions.h"

void sys_init(void);

void sys_init(void) {
	// Prepare the pointers to rom functions
	getchar = (rom_getchar)(*(uint8_t*)(ROM_TABLE_BASE-4));
	putchar = (rom_putchar)(*(uint8_t*)(ROM_TABLE_BASE-2));
}

void main(void) {
	sys_init();

	while(1) { // Endless loop
		;
	}
}

