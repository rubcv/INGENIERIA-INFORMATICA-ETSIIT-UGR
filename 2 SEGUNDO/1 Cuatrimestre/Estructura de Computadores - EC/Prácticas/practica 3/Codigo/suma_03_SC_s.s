# suma.s del Guión 1
# 1.- añadiéndole convención cdecl
# 2.- añadiéndole printf() y cambiando syscall por exit()
# 3.- extrayendo suma a módulo C para linkar
#	gcc -m32 -O1 -g -c suma_03_SC_c.c	[-fno-omit-frame-pointer]
#	as --32      -g    suma_03_SC_s.s -o suma_03_SC_s.o
#	ld -m elf_i386     suma_03_SC_c.o    suma_03_SC_s.o -o suma_03_SC \
#		-lc   -dynamic-linker /lib/ld-linux.so.2

.section .data
lista:		.int 1,2,10,  1,2,0b10,  1,2,0x10
longlista:	.int (.-lista)/4
resultado:	.int -1
formato:	.ascii	"resultado = %d = %0x hex\n\0"
				# formato para printf() libC
.section .text
_start:	.global _start

	pushl longlista
	pushl    $lista
	call suma
	add $8, %esp
	mov %eax, resultado

	push %eax
	push %eax
	push $formato
	call printf
	add $12, %esp

	pushl $0
	call exit
#	add $4, %esp		# (no ret)
