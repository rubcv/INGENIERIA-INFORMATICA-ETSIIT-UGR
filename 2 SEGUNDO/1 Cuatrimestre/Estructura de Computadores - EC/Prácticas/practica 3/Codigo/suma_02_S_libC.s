# suma.s del Guión 1
# 1.- añadiéndole convención cdecl
# 2.- añadiéndole printf() y cambiando syscall por exit()
#	as --32 -g      suma_02_S_libC.s -o suma_02_S_libC.o
#	ld -m elf_i386  suma_02_S_libC.o -o suma_02_S_libC \
#		-lc   -dynamic-linker /lib/ld-linux.so.2

.section .data
lista:		.int 1,2,10,  1,2,0b10,  1,2,0x10
longlista:	.int (.-lista)/4
resultado:	.int -1
formato:	.ascii	"resultado = %d = %0x hex\n"
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
