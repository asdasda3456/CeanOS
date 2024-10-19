#include "vga.h"
#include "stdint.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"
#include "util.h"
#include "stdlib/stdio.h"
#include "keyboard.h"

void main();
extern void set_screen_color(uint8_t color);

void init_all() {
    initGdt();
    initIdt();
    initTimer();
    initKeyboard();
}

void main(){
    init_all();
    print("##welcome to ceanos##\n");
    print("current os version: v0.0.2-alpha\n");
    print("ceanos~$ ");
    set_screen_color(0x0F);
    for(;;);
}
