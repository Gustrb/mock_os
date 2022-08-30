#include "kernel.h"

#include "io/includes/vga.h"

void kernel_entry() {
  //first init vga with fore & back colors
  init_vga(WHITE, BLACK);

  /*call above function to print something
    here to change the fore & back color
    assign g_fore_color & g_back_color to color values
    g_fore_color = BRIGHT_RED;
  */
  print_string("Hello World!");
  print_new_line();
  print_int(123456789);
  print_new_line();
  print_string("Goodbye World!");
}
