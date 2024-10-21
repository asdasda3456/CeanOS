#include "io.h"
#include "stdint.h"

void wait_ata_ready() {
    while ((inb(ATA_PRIMARY_IO + 7) & 0x80) != 0);  // wait until BSY flag is cleared
}

void read_sector(uint32_t lba, uint8_t* buffer) {
    // wait for the drive to be ready
    wait_ata_ready();

    // send the LBA address
    outb(ATA_PRIMARY_IO + 6, 0xE0 | ((lba >> 24) & 0x0F));  // LBA mode, send high 4 bits of LBA
    outb(ATA_PRIMARY_IO + 2, 1);                            // Sector count (1 sector)
    outb(ATA_PRIMARY_IO + 3, (uint8_t) lba);                // LBA low byte
    outb(ATA_PRIMARY_IO + 4, (uint8_t)(lba >> 8));          // LBA mid byte
    outb(ATA_PRIMARY_IO + 5, (uint8_t)(lba >> 16));         // LBA high byte

    wait_ata_ready();

    for (int i = 0; i < ATA_SECTOR_SIZE; i++) {
        buffer[i] = inb(ATA_PRIMARY_IO);
        print_hex(buffer[i]);
        print(" ");
    }
    print("\n");
}

uint8_t inb(uint16_t port) {
    uint8_t result;
    __asm__ volatile("inb %1, %0" : "=a"(result) : "dN"(port));
    return result;
}

void outb(uint16_t port, uint8_t data) {
    __asm__ volatile("outb %1, %0" : : "dN"(port), "a"(data));
}

uint16_t inw(uint16_t port) {
    uint16_t result;
    __asm__ volatile("inw %1, %0" : "=a"(result) : "dN"(port));
    return result;
}
