#ifndef _ROM_FUNCTIONS_
#define _ROM_FUNCTIONS_

#include <common_datatypes.h>

#define ROM_TABLE_BASE 0xF800 

typedef	void (*rom_putchar)(char ch);
typedef	char (*rom_getchar)(void);

typedef	uint8_t (*rom_n8vem_ide_init)(void);
typedef	uint8_t (*rom_n8vem_ide_read)(uint8_t *dest, uint8_t sect, uint8_t head, uint8_t cyll, uint8_t cylh);
typedef	uint8_t (*rom_n8vem_ide_reg_rd)(uint8_t reg);
typedef	uint8_t (*rom_n8vem_ide_reg_wr)(uint8_t reg, uint8_t val);

#endif /* _ROM_FUNCTIONS_ */
