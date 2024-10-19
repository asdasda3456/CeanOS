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
    print("  exit      - exits the operating system\n");
    print("  shutdown  - shuts down the system.\n");
    print("  compdate  - displays the compilation date.\n");
    print("  neofetch  - display system information\n");
}

void _get_sysinfo() {
    print("OS name: CeanOS\n");
    print("Kernel version: 0xFDF4E3 \n");
    print("bosh version: v0.1 \n");
    print("build date: 19 october 2024\n\n");
    
    print_cpuinfo();
}

