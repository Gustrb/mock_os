#ifndef STDIO_H
#define STDIO_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

/**
 * Stops the system, on nop, for the given number of timer_counts
 *
 * @param timer_count how many seconds to sleep
 */
void sleep(uint32 timer_count);

#endif
