#include "osfunc.h"
#include "stdint.h"
#include "vga.h"

void _term_help(){
    print("Available commands:\n");
    print("  clear     - clears the screen\n");
    print("  exit      - exits the operating system\n");
    print("  about     - displays information about the computer\n");
    print("  shutdown  - shuts down the system.\n");
    print("  compdate  - displays the compilation date.\n"); 
}
