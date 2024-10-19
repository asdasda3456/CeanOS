#include "vga.h"
#include "stdint.h"
#include "cpuinfo.h"
#include "osfunc.h"

#include "stdlib/stdio.h"

int strcmp(const char *first, const char *second) {
    uint8_t i = 0;
    uint8_t j = 0; 
    
    while (first[i] != '\0') {
        i++;
    }
    while (second[j] != '\0') {
        if (second[j] != first[j]) {
            return 0;
        }
        j++;
    }
    if (i == j) {
        return 1;
    }else {
        return 0;
    }
}

void splitter(const char *tex) {
    if (strcmp("clear", tex) != 0) {
        Reset();
    }
    else if (strcmp("help", tex) != 0) {
        _term_help();
    }
    else if (strcmp("exit", tex) != 0) {
        __asm__("hlt");
    }
    else if (strcmp("about", tex) != 0 ) {
        print("OS: CeanOS\n");
        print("OSVER: alpha 0.0.1\n");
        print_cpuinfo();
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
    else {
        print("bosh: unrecognized command \n");
    }
}
