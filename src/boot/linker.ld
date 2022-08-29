/* Kernel entrypoint */
ENTRY(_start)

SECTIONS
{
  /* Allocating 1MB of free space */
  . = 1M;

  /* Text section */
  .text BLOCK(4K) : ALIGN(4K)
  {
    *(.multiboot)
    *(.text)
  }

  /* Read only data section */
  .rodata BLOCK(4K) : ALIGN(4K)
  {
    *(.rodata)
  }

  /* bss section */
  .bss BLOCK(4K) : ALIGN(4K)
  {
    *(COMMON)
    *(.bss)
  }
}
