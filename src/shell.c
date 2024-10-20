/* SHELL.C */
/* Copyright (c) @asdasda3456 2024 - 2024 */

#include "vga.h"
#include "stdint.h"
#include "osfunc.h"
#include "cpuinfo.h"
#include "util.h"
#include "strings.h"
#include "keyboard.h"

void run_term(const char *tex) {
    if (strcmp("clear", tex) != 0) {
        Reset();
    }
    else if (strcmp("help", tex) != 0) {
        _term_help();
    }
    else if (strcmp("version", tex) != 0 || strcmp("ver", tex) != 0) {
        print("CeanOS version: 0.0.3-alpha\n");
    }
    else if (strcmp("fetch", tex) != 0) {
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
        print(__DATE__);
        print("\n");
        print(__TIME__);
        print("\n");
    }
    else if (strcmp("", tex) != 0 || strcmp(" ", tex) != 0 ) {
    }
    else {
        print("bosh: unrecognized command \n");
    }
}
