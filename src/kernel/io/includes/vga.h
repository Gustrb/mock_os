#ifndef VGA_H
#define VGA_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#define VGA_ADDRESS 0xB8000
#define BUFF_SIZE 2200
#define NULL 0

uint16 *vga_buffer;

typedef enum vga_color {
  BLACK,
  BLUE,
  GREEN,
  CYAN,
  RED,
  MAGENTA,
  BROWN,
  GREY,
  DARK_GREY,
  BRIGHT_BLUE,
  BRIGHT_GREEN,
  BRIGHT_CYAN,
  BRIGHT_RED,
  BRIGHT_MAGENTA,
  YELLOW,
  WHITE,
} vga_color_t;

void print_int(int num);
void print_string(char *str);
void print_char(char ch);
void print_new_line();
void init_vga(uint8 fore_color, uint8 back_color);
void clear_vga_buffer(uint16 **buffer, uint8 fore_color, uint8 back_color);
uint16 vga_entry(unsigned char ch, uint8 fore_color, uint8 back_color);

#endif
