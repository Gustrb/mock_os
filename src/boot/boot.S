# Setting magic number to 0x1BADB002 to be identified by the bootloader
.set MAGIC, 0x1BADB002

# Set flags to 0x0
.set FLAGS, 0x0

# Set the checksum
.set CHECKSUM, -(MAGIC + FLAGS)

# Enable multiboot
.section .multiboot

# type all the constants types to be used later in the bootloader
.long MAGIC
.long FLAGS
.long CHECKSUM

# Define the stack bottom
stackBottom:

# Define the max stack size to be 512 bytes
.skip 1024

# Set the stack top which grows from higher to lower
stackTop:

.section .text
.global _start
.type _start, @function

_start:
  # Assign current stack pointer to be stackTop
  mov $stackTop, %esp

  # Call the kernel main method
  call kernel_entry

  cli

# Put the system into an infinte loop
hltLoop:
  hlt
  jmp hltLoop

.size _start, . - _start
