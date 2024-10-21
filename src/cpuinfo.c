#include "cpuinfo.h"
#include "vga.h"
#include "stdlib/stdio.h"

void get_cpu_info(CPUinfo* cpu_info) {
    uint32_t eax, ebx, ecx, edx;

    asm volatile (
        "cpuid"
        : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
        : "a"(0)
    );

    *((uint32_t*)&cpu_info->vendor[0]) = ebx;  // first 4 bytes
    *((uint32_t*)&cpu_info->vendor[4]) = edx;  // next 4 bytes
    *((uint32_t*)&cpu_info->vendor[8]) = ecx;  // last 4 bytes
    cpu_info->vendor[12] = '\0';  // null-terminate the string

    asm volatile (
        "cpuid"
        : "=a"(eax)
        : "a"(1)
    );

    cpu_info->model = (eax >> 4) & 0xF;   
    cpu_info->family = (eax >> 8) & 0xF;  
}    

inline void print_cpuinfo() {
    CPUinfo cpu_info;
    get_cpu_info(&cpu_info);
    
    printf("CPU: %s | M: %u | F: %u\n", cpu_info.vendor, cpu_info.model, cpu_info.family); 
}
