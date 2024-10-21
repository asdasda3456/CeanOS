/* KERNEL.C */
/* Copyright (c) @asdasda3456 2024 - 2024 */

/* main entry point of the ceanos kernel */

#include "vga.h"
#include "stdint.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"
#include "util.h"
#include "stdlib/stdio.h"
#include "keyboard.h"
#include "io.h"
#include "memory.h"

void main(void);

// initialize all important stuff, like idt, gdt, etc

static inline void init_all(void) {
    gdt_init();
        idt_init();
        init_mem();
        timer_init();
    keyboard_init();

    outb(0x3D4, 0x0A);              //disable text cursor
    outb(0x3D5, 0x20);              //disable text cursor
}

void main(void){
    init_all();

    print("##welcome to ceanos##\n");            // this part will probably be cleared and replaced with something
    print("current os version: v0.0.3-alpha\n"); // else in the future, for now it will just print a message and 
    print("ceanos~$ ");                          // initialize the shell

    set_screen_color(0x0F);                      // 0x0F = white on black
    
    while(1);   // infinite loop
}
