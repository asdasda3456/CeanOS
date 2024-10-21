#ifndef IO_H
#define IO_H

#define ATA_PRIMARY_IO  0x1F0  // primary ATA I/O Base
#define ATA_SECTOR_SIZE 512      // standard sector size

#include "stdint.h"  

void wait_ata_ready(); 
void read_sector(uint32_t lba, uint8_t* buffer);

uint8_t inb(uint16_t port);
void outb(uint16_t port, uint8_t data);
uint16_t inw(uint16_t port);

#endif  // IO_H
