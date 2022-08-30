#include "string.h"

uint32 strlen(const char* str) {
  uint32 length = 0;

  // while the current char(str[index]) is not null
  while (str[length]) {
    // Increment the length
    length++;
  }

  return length;
}

// TODO: Negative numbers?
uint32 digit_count(int num) {
  uint32 count = 0;

  // if num is 0, then the number of digits is 1, since 0 is a single digit
  if (num == 0) {
    return 1;
  }

  // while num is not 0, divide it by 10 and increment count
  // to keep reducing the number of digits
  // Example:
  // num = 123
  // num = num / 10
  // num = 12
  while (num > 0) {
    count++;
    num = num / 10;
  }

  return count;
}

// TODO: Negative numbers?
void itoa(int num, char *number) {
  int digits_count = digit_count(num);
  int index = digits_count - 1;
  char x;

  // if num is 0 then put it inside the buffer and null terminate it
  if (num == 0 && digits_count == 1) {
    number[0] = '0';
    number[1] = '\0';
    return;
  }

  while (num != 0) {
    // get the remainder of num / 10
    // Example:
    // num = 123
    // x = num % 10
    // x = 3
    x = num % 10;

    // put the remainder in the buffer
    number[index] = x + '0';
    index--;

    // divide num by 10, to get the next digit
    num = num / 10;
  }

  // null terminate the buffer
  number[digits_count] = '\0';
}
