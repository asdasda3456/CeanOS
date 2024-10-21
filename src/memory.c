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
}

uint64_t allocate(int virtual_page) {

}

