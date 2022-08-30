#assemble boot.s file
as --32 src/boot/boot.s -o boot.o

#compile kernel.c file
gcc -m32 -c src/kernel/kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

gcc -m32 -c src/kernel/io/keyboard.c
gcc -m32 -c src/lib/string/string.c

#linking the kernel with kernel.o and boot.o files
ld -m elf_i386 -T src/boot/linker.ld kernel.o string.o keyboard.o boot.o -o mock_os.bin -nostdlib

#check mock_os.bin file is x86 multiboot file or not
grub-file --is-x86-multiboot mock_os.bin

#building the iso file
mkdir -p isodir/boot/grub

cp mock_os.bin isodir/boot/mock_os.bin
cp src/boot/grubfile.cfg isodir/boot/grub/grub.cfg

grub-mkrescue -o mock_os.iso isodir

#run it in qemu
qemu-system-x86_64 -cdrom mock_os.iso

# Cleanup
rm -rf isodir

rm boot.o
rm kernel.o
rm keyboard.o
rm string.o

rm mock_os.bin
rm mock_os.iso
