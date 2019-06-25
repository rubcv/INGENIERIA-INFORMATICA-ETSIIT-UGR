	.file	"figura1a.c"
	.comm	s,40000,32
	.section	.rodata
.LC1:
	.string	"Tiempo(seg):%11.9f\t\n"
	.align 8
.LC2:
	.string	"Primera componente: %d, \303\232ltima componente: %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$160096, %rsp
	leaq	-160032(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	$1, -160080(%rbp)
	jmp	.L2
.L7:
	movl	$0, -160076(%rbp)
	movl	$0, -160072(%rbp)
	movl	$0, -160068(%rbp)
	movl	$0, -160064(%rbp)
	movl	$0, -160060(%rbp)
	movl	$0, -160056(%rbp)
	movl	$0, -160052(%rbp)
	movl	$0, -160048(%rbp)
	movl	$0, -160044(%rbp)
	jmp	.L3
.L4:
	movl	-160044(%rbp), %eax
	cltq
	movl	s(,%rax,8), %eax
	leal	(%rax,%rax), %edx
	movl	-160080(%rbp), %eax
	addl	%edx, %eax
	addl	%eax, -160076(%rbp)
	movl	-160044(%rbp), %eax
	addl	$1, %eax
	cltq
	movl	s(,%rax,8), %eax
	leal	(%rax,%rax), %edx
	movl	-160080(%rbp), %eax
	addl	%edx, %eax
	addl	%eax, -160068(%rbp)
	movl	-160044(%rbp), %eax
	addl	$2, %eax
	cltq
	movl	s(,%rax,8), %eax
	leal	(%rax,%rax), %edx
	movl	-160080(%rbp), %eax
	addl	%edx, %eax
	addl	%eax, -160060(%rbp)
	movl	-160044(%rbp), %eax
	addl	$3, %eax
	cltq
	movl	s(,%rax,8), %eax
	leal	(%rax,%rax), %edx
	movl	-160080(%rbp), %eax
	addl	%edx, %eax
	addl	%eax, -160052(%rbp)
	movl	-160044(%rbp), %eax
	cltq
	movl	s+4(,%rax,8), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	subl	-160080(%rbp), %eax
	addl	%eax, -160072(%rbp)
	movl	-160044(%rbp), %eax
	addl	$1, %eax
	cltq
	movl	s+4(,%rax,8), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	subl	-160080(%rbp), %eax
	addl	%eax, -160064(%rbp)
	movl	-160044(%rbp), %eax
	addl	$2, %eax
	cltq
	movl	s+4(,%rax,8), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	subl	-160080(%rbp), %eax
	addl	%eax, -160056(%rbp)
	movl	-160044(%rbp), %eax
	addl	$3, %eax
	cltq
	movl	s+4(,%rax,8), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	subl	-160080(%rbp), %eax
	addl	%eax, -160048(%rbp)
	addl	$4, -160044(%rbp)
.L3:
	cmpl	$4999, -160044(%rbp)
	jle	.L4
	movl	-160060(%rbp), %eax
	movl	-160068(%rbp), %edx
	addl	%eax, %edx
	movl	-160052(%rbp), %eax
	addl	%edx, %eax
	addl	%eax, -160076(%rbp)
	movl	-160056(%rbp), %eax
	movl	-160064(%rbp), %edx
	addl	%eax, %edx
	movl	-160048(%rbp), %eax
	addl	%edx, %eax
	addl	%eax, -160072(%rbp)
	movl	-160076(%rbp), %eax
	cmpl	-160072(%rbp), %eax
	jge	.L5
	movl	-160080(%rbp), %eax
	cltq
	movl	-160076(%rbp), %edx
	movl	%edx, -160000(%rbp,%rax,4)
	jmp	.L6
.L5:
	movl	-160080(%rbp), %eax
	cltq
	movl	-160072(%rbp), %edx
	movl	%edx, -160000(%rbp,%rax,4)
.L6:
	addl	$1, -160080(%rbp)
.L2:
	cmpl	$40000, -160080(%rbp)
	jle	.L7
	leaq	-160016(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	-160016(%rbp), %rdx
	movq	-160032(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	cvtsi2sdq	%rax, %xmm1
	movq	-160008(%rbp), %rdx
	movq	-160024(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC0(%rip), %xmm2
	divsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -160040(%rbp)
	movq	-160040(%rbp), %rax
	movq	%rax, -160088(%rbp)
	movsd	-160088(%rbp), %xmm0
	movl	$.LC1, %edi
	movl	$1, %eax
	call	printf
	movl	-4(%rbp), %edx
	movl	-160000(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$10, %edi
	call	putchar
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
