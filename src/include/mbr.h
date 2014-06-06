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

typedef struct {
	uint16_t	checksum;
	char		copyright[31];
	uint16_t	start_cyl;
	uint16_t	cyls_tot;
	uint8_t		heads_tot;
	uint8_t		sect_tot; // Number of physical sector/tracks
	uint8_t		options;
	uint8_t		sec_size; // sector size / 128
	uint16_t	spt; // Number of 128 byte records per track
	uint8_t		bsh; // Block shift 3 => 1k, 4 => 2k, 5 => 4k ...
	uint8_t		blm; // Block mask 7 => 1k, 0x0F => 2k, 0x1F => 4k ...
	uint8_t		exm; // Extent mask
	uint16_t	dsm; // number of blocks on disk -1
	uint16_t	drm; // number of directory entries -1
	uint16_t	al0; // Directory allocation bitmap, 1st byte
	uint16_t	al1; // Directory allocation bitmap, 2nd byte
	uint16_t	cks; // Checksum vector size, 0 for fixd disk
	uint16_t	dir_off; // Number of tracks from start of drive to directory (reserved tracks)
	uint16_t	unused[4];
	uint16_t	blk_size; // block size / 128
	uint16_t	max_words_bblock;
	uint16_t	words_badblock;
} CPM_Partition_Descr;

#endif /* __MBR_HEADER__ */
