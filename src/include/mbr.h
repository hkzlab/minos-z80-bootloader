#ifndef __MBR_HEADER__
#define __MBR_HEADER__

#include <common_datatypes.h>

typedef struct {
	uint8_t status;
	uint8_t chs_start_addr[3];
	uint8_t type;
	uint8_t chs_end_addr[3];
	uint8_t lba_start_addr[4];
	uint8_t sec_size[4];
} PartitionEntry;

typedef struct {
	uint8_t code_area[446];
	PartitionEntry partitions[4];
	uint8_t signature[2];
} MBRStruct;

#endif /* __MBR_HEADER__ */
