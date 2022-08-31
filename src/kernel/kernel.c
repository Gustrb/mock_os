#include "kernel.h"

#include "io/includes/vga.h"
#include "io/includes/keyboard.h"

void kernel_entry() {
  //first init vga with fore & back colors
  init_vga(WHITE, BLACK);

  char current_char = 0;
  while (current_char != KEY_ENTER) {
    current_char = get_input_keycode();
    print_new_line();
    print_int(current_char);
    sleep(0x02FFFFFF);
  }
}
