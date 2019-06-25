	.file	"daxpy.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Falta valor N y/o valor a\n"
.LC2:
	.string	"Primera componente: %d \303\232ltima componente: %d"
.LC3:
	.string	"\nTiempo(seg) DAXPY: %11.9f\t\n"
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
.LFB21:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	cmpl	$2, %edi
	jg	.L2
	movq	stderr(%rip), %rsi
	movl	$.LC0, %edi
	call	fputs
	orl	$-1, %edi
	call	exit
.L2:
	movq	8(%rsi), %rdi
	movq	%rsi, %r12
	xorl	%r15d, %r15d
	call	atoi
	movq	16(%r12), %rdi
	movl	%eax, %ebx
	call	atoi
	movl	%eax, -88(%rbp)
	movslq	%ebx, %rax
	leaq	18(,%rax,4), %rax
	andq	$-16, %rax
	subq	%rax, %rsp
	movq	%rsp, %r14
	subq	%rax, %rsp
	leaq	3(%rsp), %r12
	shrq	$2, %r12
	leaq	0(,%r12,4), %r13
.L3:
	cmpl	%r15d, %ebx
	jle	.L9
	call	rand
	cltd
	idivl	%ebx
	movl	%edx, (%r14,%r15,4)
	call	rand
	cltd
	idivl	%ebx
	movl	%edx, 0(%r13,%r15,4)
	incq	%r15
	jmp	.L3
.L9:
	leaq	-80(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	xorl	%eax, %eax
.L5:
	cmpl	%eax, %ebx
	jle	.L10
	movl	-88(%rbp), %edx
	imull	(%r14,%rax,4), %edx
	addl	%edx, 0(%r13,%rax,4)
	incq	%rax
	jmp	.L5
.L10:
	leaq	-64(%rbp), %rsi
	xorl	%edi, %edi
	decl	%ebx
	movslq	%ebx, %rbx
	call	clock_gettime
	movq	-64(%rbp), %rax
	subq	-80(%rbp), %rax
	movl	$.LC2, %esi
	movl	0(%r13,%rbx,4), %ecx
	movl	0(,%r12,4), %edx
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	-56(%rbp), %rax
	subq	-72(%rbp), %rax
	cvtsi2sdq	%rax, %xmm1
	xorl	%eax, %eax
	divsd	.LC1(%rip), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -88(%rbp)
	call	__printf_chk
	movsd	-88(%rbp), %xmm0
	movl	$.LC3, %esi
	movl	$1, %edi
	movb	$1, %al
	call	__printf_chk
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE21:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
