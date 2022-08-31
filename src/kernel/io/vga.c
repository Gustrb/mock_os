#include "includes/vga.h"
#include "../../lib/string/string.h"

// Currently the vga buffer is located at 0xB8000
uint32 vga_index;

// Counter to store the number of lines that have been printed
static uint32 next_line_index = 1;

// Global foreground and background color values
uint8 g_fore_color = WHITE;
uint8 g_back_color = BLUE;

// The ascii codes for all the numeric digits
int digit_ascii_codes[10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};

/**
 * Gets the vga uint16 that corresponds to that fore_ground color and back_ground color
 * and the character to be printed.
 *
 * @param ch the character to be printed.
 * @param fore_color the foreground color is used to paint the character.
 * @param back_color the background color is used to paint the screen.
 *
 * @return uint16 the vga uint16 that corresponds to the fore_ground color, back_ground color and the character to be printed.
 */
PRIVATE uint16 vga_entry(unsigned char ch, uint8 fore_color, uint8 back_color) {
  uint16 ax = 0;
  uint8 ah = 0, al = 0;

  ah = back_color;
  ah <<= 4;
  ah |= fore_color;
  ax = ah;
  ax <<= 8;
  al = ch;
  ax |= al;

  return ax;
}

void clear_vga_buffer(uint16 **buffer, uint8 fore_color, uint8 back_color) {
  // Go through the buffer and set each uint16 to 0.
  for(uint32 i = 0; i < BUFF_SIZE; i++){
    (*buffer)[i] = vga_entry(NULL, fore_color, back_color);
  }

  // Reset the index to 0, and the next_line_index to 1.
  next_line_index = 1;
  vga_index = 0;
}

void init_vga(uint8 fore_color, uint8 back_color) {
  // Cast the vga_buffer to a uint16 pointer, and set it to the VGA_ADDRESS.
  // because it is the address of all vgas buffer, 0xB8000
  vga_buffer = (uint16*) VGA_ADDRESS;

  // Clears the buffer itself so everything is blank.
  clear_vga_buffer(&vga_buffer, fore_color, back_color);

  // Set the fore_color and back_color.
  g_fore_color = fore_color;
  g_back_color = back_color;
}

void print_new_line() {
  // If it is going to overflow reset it and clear the buffer.
  if (next_line_index >= 55) {
    next_line_index = 0;
    clear_vga_buffer(&vga_buffer, g_fore_color, g_back_color);
  }

  // Increment the next_line_index.
  vga_index = 80 * next_line_index;
  next_line_index++;
}

void print_char(char ch) {
  // Inserts the vga uint16 into the vga buffer.
  vga_buffer[vga_index] = vga_entry(ch, g_fore_color, g_back_color);

  // Incremets the index
  vga_index++;
}

void print_string(char *str) {
  uint32 index = 0;

  // Foreach char print it to the buffer;
  while (str[index]){
    print_char(str[index]);
    index++;
  }
}

void print_int(int num) {
  // Stack allocate a buffer to store the number, containing enough space for the number and a null terminator.
  char str_num[digit_count(num) + 1];
  // Insert the number into the buffer.
  itoa(num, str_num);
  // Print the buffer.
  print_string(str_num);
}
