# suma.s del Guión 1
# 1.- añadiéndole convención cdecl
#	as --32 -g      suma_01_S_cdecl.s -o suma_01_S_cdecl.o
#	ld -m elf_i386  suma_01_S_cdecl.o -o suma_01_S_cdecl

.section .data
lista:		.int 1,2,10,  1,2,0b10,  1,2,0x10
longlista:	.int (.-lista)/4
resultado:	.int -1

.section .text
_start:	.global _start

	pushl longlista
	pushl    $lista
	call suma
	add $8, %esp
	mov %eax, resultado

	mov $1, %eax
	mov $0, %ebx
	int $0x80

suma:
	push %ebp
	mov  %esp, %ebp

	push %ebx
	mov  8(%ebp), %ebx
	mov 12(%ebp), %ecx

	mov $0, %eax
	mov $0, %edx
bucle:
	add (%ebx,%edx,4), %eax
	inc       %edx
	cmp  %edx,%ecx
	jne bucle

	pop %ebx
	pop %ebp
	ret
