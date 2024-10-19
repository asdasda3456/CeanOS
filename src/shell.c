#include "vga.h"
#include "stdint.h"
#include "osfunc.h"
#include "cpuinfo.h"
#include "util.h"
#include "strings.h"

void run_term(const char *tex) {
    if (strcmp("clear", tex) != 0) {
        Reset();
    }
    else if (strcmp("help", tex) != 0) {
        _term_help();
    }
    else if (strcmp("neofetch", tex) != 0) {
        _get_sysinfo();
    }
    else if (strcmp("exit", tex) != 0) {
        __asm__("hlt");
    }
    else if (strcmp("shutdown", tex) != 0 ) {
        print("shutting down...\n");
        
        __asm__ __volatile__ (
            "cli\n\t"               
            "hlt\n\t"               
        );
    }
    else if (strcmp("compdate", tex) != 0 ) {
        print("Compiled at 19 october 2024\n");
    }
    else if (strcmp("", tex) != 0 ) {
    }
    else if (strcmp(" ", tex) != 0 ) {
    }
    else {
        print("bosh: unrecognized command \n");
    }
}
