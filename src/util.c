/* UTILS FOR CEANOS */

#include "stdint.h"
#include "util.h"
#include "timer.h"
#include "stdlib/stdio.h"

void memset(void *dest, char val, uint32_t count){
    char *temp = (char*) dest;
    for (; count != 0; count --){
        *temp++ = val;
    }
}

void* memcpy(void* dest, const void* src, size_t n) {
    uint8_t* d = (uint8_t*)dest; 
    const uint8_t* s = (const uint8_t*)src; 
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i]; 
    }
    return dest; 
}

void outPortB(uint16_t Port, uint8_t Value){
    asm volatile ("outb %1, %0" : : "dN" (Port), "a" (Value));
}

char inPortB(uint16_t port){
    char rv;
    asm volatile("inb %1, %0": "=a"(rv):"dN"(port));
    return rv;
}

void insl(uint16_t port, void* addr, int count) {
    asm volatile ("cld; rep insl" 
                  : "=D" (addr), "=c" (count) 
                  : "d" (port), "0" (addr), "1" (count) 
                  : "memory");
}

