	.file	"figura1a.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Tiempo(seg):%11.9f\t\n"
.LC2:
	.string	"Primera componente: %d, \303\232ltima componente: %d"
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
.LFB21:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	xorl	%edi, %edi
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$160032, %rsp
	.cfi_def_cfa_offset 160064
	movq	%rsp, %rsi
	leaq	36(%rsp), %rbp
	call	clock_gettime
	movl	$1, %edx
.L2:
	movl	$s, %eax
	xorl	%ebx, %ebx
	xorl	%r11d, %r11d
	xorl	%r10d, %r10d
	xorl	%r9d, %r9d
	xorl	%r8d, %r8d
	xorl	%edi, %edi
	xorl	%esi, %esi
	xorl	%ecx, %ecx
.L7:
	movl	(%rax), %r12d
	addq	$32, %rax
	leal	(%rdx,%r12,2), %r12d
	addl	%r12d, %ecx
	movl	-24(%rax), %r12d
	leal	(%rdx,%r12,2), %r12d
	addl	%r12d, %edi
	movl	-16(%rax), %r12d
	leal	(%rdx,%r12,2), %r12d
	addl	%r12d, %r9d
	movl	-8(%rax), %r12d
	leal	(%rdx,%r12,2), %r12d
	addl	%r12d, %r11d
	imull	$3, -28(%rax), %r12d
	subl	%edx, %r12d
	addl	%r12d, %esi
	imull	$3, -20(%rax), %r12d
	subl	%edx, %r12d
	addl	%r12d, %r8d
	imull	$3, -12(%rax), %r12d
	subl	%edx, %r12d
	addl	%r12d, %r10d
	imull	$3, -4(%rax), %r12d
	subl	%edx, %r12d
	addl	%r12d, %ebx
	cmpq	$s+40000, %rax
	jne	.L7
	addl	%r9d, %edi
	addl	%r10d, %r8d
	addl	%edi, %r11d
	addl	%r8d, %ebx
	addl	%r11d, %ecx
	addl	%ebx, %esi
	cmpl	%esi, %ecx
	cmovge	%esi, %ecx
	incl	%edx
	addq	$4, %rbp
	movl	%ecx, -4(%rbp)
	cmpl	$40001, %edx
	jne	.L2
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	movl	$.LC1, %esi
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movb	$1, %al
	divsd	.LC0(%rip), %xmm1
	addsd	%xmm1, %xmm0
	call	__printf_chk
	movl	160028(%rsp), %ecx
	movl	32(%rsp), %edx
	movl	$.LC2, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movl	$10, %edi
	call	putchar
	addq	$160032, %rsp
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE21:
	.size	main, .-main
	.comm	s,40000,16
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
