#ifndef STRING_H
#define STRING_H

#include "stdint.h"

int strcmp(const char *first, const char *second);
char* strncpy(char* dest, const char* src, size_t n);
void strcpy(char *dest, const char* src);
void strcat(char *dest, const char* src);
size_t strlen(const char* str);
void splitter(const char *tex);

#endif // string_h
