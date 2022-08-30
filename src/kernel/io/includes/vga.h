#ifndef VGA_H
#define VGA_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#define VGA_ADDRESS 0xB8000
#define BUFF_SIZE 2200
#define NULL 0
#define PRIVATE static

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

/**
 * Initializes the vga buffer with the given fore_color and back_color, and clears the vga_buffer.
 *
 * @param fore_color the foreground color is used to paint the character.
 * @param back_color the background color is used to paint the screen.
 */
void init_vga(uint8 fore_color, uint8 back_color);

/**
 * Prints an integer to the vga buffer
 *
 * @param num the integer to be printed
 */
void print_int(int num);

/**
 * prints a null terminated string to the vga buffer
 *
 * This method assumes the string is null terminated, and its memory is valid and allocated
 * if its null or it points to invalid memory it will cause a segmentation fault.
 *
 * @param str the string to be printed
 */
void print_string(char *str);

/**
 * Prints the char to the vga buffer using it ascii code(vga_entry)
 *
 * @param ch the character to be printed
 */
void print_char(char ch);

/**
 * Prints a new line in the vga buffer
 *
 * If the next line is going to overflow the buffer then it clear the buffer and reset the index to 0.
 */
void print_new_line();

/**
 * Clears the vga buffer with the given fore_color and back_color, and sets each vga uint16 to 0.
 *
 * This method assumes the vga buffer is allocated and can be used so
 * if its null or it points to invalid memory it will cause a segmentation fault.
 *
 * @param buffer is the vga buffer to be cleared.
 * @param fore_color the foreground color is used to paint the character.
 * @param back_color the background color is used to paint the screen.
 */
void clear_vga_buffer(uint16 **buffer, uint8 fore_color, uint8 back_color);

#endif
