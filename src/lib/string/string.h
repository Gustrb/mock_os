#ifndef STRING_H
#define STRING_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

/**
 * Iterate through the string until it reaches the null terminator.
 *
 * This function is not safe, if the string is not null terminated, it will
 * run until it finds a null in the memory, thus maybe causing a segfault.
 *
 * @param str The string to iterate through.
 *
 * @return uint32 the length of str
 */
uint32 strlen(const char* str);

/**
 * Inserts the digits of a number into a mutable buffer.
 *
 * This function assumes the number buffer is allocated and can be used
 * so if its null or it points to invalid memory it will cause a segmentation fault.
 *
 * @param num the number to be inserted into the buffer.
 * @param number the buffer to insert the number into.
 */
void itoa(int num, char *number);

/**
 * Counts all the digits of a number, by dividing it by 10
 * progressively.
 *
 * @param num is the number to have its digits counted.
 *
 * @return uint32 is the number of digits that num has
 */
uint32 digit_count(int num);

#endif
