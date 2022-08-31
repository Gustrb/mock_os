#include "includes/keyboard.h"

uint8 inb(uint16 port) {
  uint8 ret;

  // Read from the given port and return the value.
  asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));

  return ret;
}

void outb(uint16 port, uint8 data) {
  asm volatile("outb %0, %1" : "=a"(data) : "d"(port));
}

char get_input_keycode() {
  char ch = 0;

  // While the recieved keycode is not a valid keycode, keep looping.
  while ((ch = inb(KEYBOARD_PORT)) != 0) {
    // If the keycode is a valid keycode, return it.
    if (ch > 0) return ch;
  }

  // return 0;
  return ch;
}
