#include "io.h"
#include "stdint.h"
#include "vga.h"

volatile uint8_t inb(uint16_t port) {
    uint8_t result;
    __asm__ volatile("inb %1, %0" : "=a"(result) : "dN"(port));
    return result;
}

volatile void outb(uint16_t port, uint8_t data) {
    __asm__ volatile("outb %1, %0" : : "dN"(port), "a"(data));
}

volatile uint16_t inw(uint16_t port) {
    uint16_t result;
    __asm__ volatile("inw %1, %0" : "=a"(result) : "dN"(port));
    return result;
}
