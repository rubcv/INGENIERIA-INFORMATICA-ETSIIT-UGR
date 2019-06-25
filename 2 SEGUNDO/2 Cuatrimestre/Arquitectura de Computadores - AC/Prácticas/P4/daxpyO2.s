	.file	"daxpy.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Falta valor N y/o valor a\n"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"Primera componente: %d \303\232ltima componente: %d"
	.section	.rodata.str1.1
.LC3:
	.string	"\nTiempo(seg) DAXPY: %11.9f\t\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB39:
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
	subq	$72, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	cmpl	$2, %edi
	jle	.L12
	movq	8(%rsi), %rdi
	movq	%rsi, %r12
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol
	movq	16(%r12), %rdi
	movq	%rax, %r15
	xorl	%esi, %esi
	movl	$10, %edx
	movl	%eax, %ebx
	movq	%rax, -96(%rbp)
	call	strtol
	movl	%eax, %r13d
	movslq	%r15d, %rax
	leaq	18(,%rax,4), %rax
	andq	$-16, %rax
	subq	%rax, %rsp
	movq	%rsp, %r12
	subq	%rax, %rsp
	leaq	3(%rsp), %rax
	movq	%rax, -88(%rbp)
	shrq	$2, -88(%rbp)
	testl	%ebx, %ebx
	movq	-88(%rbp), %rax
	leaq	0(,%rax,4), %r15
	jle	.L3
	xorl	%r14d, %r14d
	.p2align 4,,10
	.p2align 3
.L5:
	call	rand
	cltd
	idivl	%ebx
	movl	%edx, (%r12,%r14,4)
	call	rand
	cltd
	idivl	%ebx
	movl	%edx, (%r15,%r14,4)
	addq	$1, %r14
	cmpl	%r14d, %ebx
	jg	.L5
	leaq	-80(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L7:
	movl	(%r12,%rax,4), %edx
	imull	%r13d, %edx
	addl	%edx, (%r15,%rax,4)
	addq	$1, %rax
	cmpl	%eax, %ebx
	jg	.L7
.L8:
	leaq	-64(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	-64(%rbp), %rax
	subq	-80(%rbp), %rax
	movl	$.LC2, %esi
	movl	-96(%rbp), %r14d
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	-56(%rbp), %rax
	subq	-72(%rbp), %rax
	subl	$1, %r14d
	movslq	%r14d, %r14
	movl	(%r15,%r14,4), %ecx
	cvtsi2sdq	%rax, %xmm1
	movq	-88(%rbp), %rax
	movl	0(,%rax,4), %edx
	xorl	%eax, %eax
	divsd	.LC1(%rip), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -104(%rbp)
	call	__printf_chk
	movsd	-104(%rbp), %xmm0
	movl	$.LC3, %esi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk
	leaq	-40(%rbp), %rsp
	xorl	%eax, %eax
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L3:
	.cfi_restore_state
	leaq	-80(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	jmp	.L8
.L12:
	movq	stderr(%rip), %rcx
	movl	$.LC0, %edi
	movl	$26, %edx
	movl	$1, %esi
	call	fwrite
	orl	$-1, %edi
	call	exit
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
