#ifndef STRING_H
#define STRING_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

uint32 strlen(const char* str);
void itoa(int num, char *number);
uint32 digit_count(int num);

#endif
