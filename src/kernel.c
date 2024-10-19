#include "vga.h"
#include "stdint.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"
#include "util.h"
#include "stdlib/stdio.h"
#include "keyboard.h"

void main();
void set_screen_color(uint8_t color);

void init_all() {
    initGdt();
    initIdt();
    initTimer();
    initKeyboard();
}

void set_screen_color(uint8_t color) {
    uint8_t* video_memory = (uint8_t*)0xB8000;
    for (int i = 0; i < width * height * 2; i += 2) {
        video_memory[i + 1] = color; // Set the background color byte
    }
}

void main(){
    init_all();
    print("##welcome to ceanos##\n");
    print("ceanos$ ");
    set_screen_color(0x0F);
    for(;;);
}
