/* MEMORY.C */
/* Copyright (c) @asdasda3456 2024 - 2024 */

#include "stdint.h"
#include "memory.h"
#include "vga.h"
#include "stdlib/stdio.h"

#define PAGE_SIZE 4096          
#define PAGE_TABLE_SIZE 1024    
#define MEM_TOTAL (16 * 1024)   

typedef struct {
    uint32_t frame_number; 
    uint32_t valid;        
} page_num;

page_num page[PAGE_TABLE_SIZE];

void init_mem(void) {
    for (uint16_t i = 0; i < PAGE_TABLE_SIZE; i++) {
        page[i].frame_number = -1; 
        page[i].valid = 1;         
    }
    print("memory initialized (probably)\n");
}

uint64_t allocate(int virtual_page) {
    if (virtual_page < 0 || virtual_page >= PAGE_TABLE_SIZE) {
        return -1; 
    }

    if (page[virtual_page].valid == 0) {
        return page[virtual_page].frame_number; 
    }

    static int next_frame = 0;
    if (next_frame >= (MEM_TOTAL / PAGE_SIZE)) {
        return -1; 
    }

    page[virtual_page].frame_number = next_frame++;
    page[virtual_page].valid = 0;       //valid 

    return page[virtual_page].frame_number;
}

void deallocate(int virtual_page) {
    if (virtual_page < 0 || virtual_page >= PAGE_TABLE_SIZE) {
        return; // invalid virtual page
    }

    page[virtual_page].valid = 1;       //invalid 
    page[virtual_page].frame_number = -1;   //frame_number is reseted 
}

//debugging function
void print_page_table(void) {
    for (int i = 0; i < PAGE_TABLE_SIZE; i++) {
        if (page[i].valid == 0) { 
            printf("Page %d -> Frame %d\n", i, page[i].frame_number);
        }
    }
}
