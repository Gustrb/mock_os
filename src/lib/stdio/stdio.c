#include "stdio.h"

/**
 * Just keep nooping until timer_count
 *
 * @param timer_count the number of noops to perform
 */
static
void nop(uint32 timer_count) {
  while (1) {
    asm volatile("nop");
    timer_count--;

    if (timer_count <= 0) {
      break;
    }
  }
}

void sleep(uint32 timer_count) {
  nop(timer_count);
}
