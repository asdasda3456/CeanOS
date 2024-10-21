#include "osfunc.h"
#include "stdint.h"
#include "vga.h"
#include "keyboard.h"
#include "cpuinfo.h"

extern char press;
extern char text[100];

void _term_help(){
    print("Available commands:\n");
    print("  clear     - clears the screen\n");
    print("  help      - prints this message\n");
    print("  version   - displays os version\n");
    print("  exit      - exits the operating system\n");
    print("  shutdown  - shuts down the system.\n");
    print("  compdate  - displays the compilation date.\n");
    print("  neofetch  - display system information");
}

void _get_sysinfo() {
    print("\n    ____ \tOS: CeanOS\n");
    print("   /   __|\tKernel version: 0xFDF4E3 \n");
    print("  |   |   \tshell: bosh (bobo shell)\n");
    print("  |   |os \tbosh version: v0.1 \n");
    print("  \\    \\_\tbuild date: 21 october 2024\n\n");
    print("   \\_____|\t");
    print_cpuinfo();
}

void halt() {
    __asm__ volatile ("cli");
    __asm__ volatile ("hlt");
}

void itoa(int value, char* str, int base) {
    char* ptr = str;
    char* ptr1 = str;
    char tmp_char;
    int tmp_value;

    if (value < 0 && base == 10) {
        *ptr++ = '-';
        value = -value;
    }

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "0123456789ABCDEF"[tmp_value - value * base];
    } while (value);

    *ptr-- = '\0';

    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
}

