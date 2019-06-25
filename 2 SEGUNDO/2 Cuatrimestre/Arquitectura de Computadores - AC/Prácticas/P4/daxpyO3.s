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
	jle	.L29
	movq	8(%rsi), %rdi
	movq	%rsi, %r12
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol
	movq	16(%r12), %rdi
	movq	%rax, %r14
	xorl	%esi, %esi
	movl	$10, %edx
	movl	%eax, %ebx
	call	strtol
	movq	%rax, -104(%rbp)
	movl	%eax, -108(%rbp)
	movslq	%r14d, %rax
	leaq	18(,%rax,4), %rax
	andq	$-16, %rax
	subq	%rax, %rsp
	leaq	3(%rsp), %rsi
	subq	%rax, %rsp
	leaq	3(%rsp), %rax
	movq	%rsi, -96(%rbp)
	shrq	$2, -96(%rbp)
	movq	%rax, -88(%rbp)
	shrq	$2, -88(%rbp)
	testl	%r14d, %r14d
	movq	-96(%rbp), %rdi
	movq	-88(%rbp), %rax
	leaq	0(,%rdi,4), %r13
	leaq	0(,%rax,4), %r12
	jle	.L3
	xorl	%r15d, %r15d
	.p2align 4,,10
	.p2align 3
.L5:
	call	rand
	cltd
	idivl	%ebx
	movl	%edx, 0(%r13,%r15,4)
	call	rand
	cltd
	idivl	%ebx
	movl	%edx, (%r12,%r15,4)
	addq	$1, %r15
	cmpl	%r15d, %ebx
	jg	.L5
	leaq	-80(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	%r12, %rax
	andl	$15, %eax
	shrq	$2, %rax
	negq	%rax
	andl	$3, %eax
	cmpl	%r14d, %eax
	cmova	%r14d, %eax
	cmpl	$4, %r14d
	cmovbe	%r14d, %eax
	testl	%eax, %eax
	je	.L18
	movq	-96(%rbp), %rcx
	movq	-104(%rbp), %rsi
	movl	0(,%rcx,4), %edx
	imull	%esi, %edx
	addl	%edx, (%r12)
	cmpl	$1, %eax
	jbe	.L19
	movl	4(,%rcx,4), %edx
	imull	%esi, %edx
	addl	%edx, 4(%r12)
	cmpl	$2, %eax
	jbe	.L20
	movl	8(,%rcx,4), %edx
	imull	%esi, %edx
	addl	%edx, 8(%r12)
	cmpl	$3, %eax
	jbe	.L21
	movl	12(,%rcx,4), %edx
	imull	%esi, %edx
	addl	%edx, 12(%r12)
	movl	$4, %edx
.L12:
	cmpl	%eax, %r14d
	je	.L16
.L11:
	movl	%r14d, %r9d
	movl	%eax, %esi
	subl	%eax, %r9d
	movl	%r9d, %edi
	shrl	$2, %edi
	leal	0(,%rdi,4), %r8d
	testl	%r8d, %r8d
	je	.L14
	movd	-108(%rbp), %xmm5
	salq	$2, %rsi
	xorl	%eax, %eax
	leaq	0(%r13,%rsi), %r10
	xorl	%ecx, %ecx
	addq	%r12, %rsi
	pshufd	$0, %xmm5, %xmm2
	movdqa	%xmm2, %xmm3
	psrlq	$32, %xmm3
.L15:
	movdqu	(%r10,%rax), %xmm1
	addl	$1, %ecx
	movdqa	%xmm1, %xmm4
	psrlq	$32, %xmm1
	pmuludq	%xmm3, %xmm1
	pshufd	$8, %xmm1, %xmm1
	pmuludq	%xmm2, %xmm4
	pshufd	$8, %xmm4, %xmm0
	punpckldq	%xmm1, %xmm0
	paddd	(%rsi,%rax), %xmm0
	movdqa	%xmm0, (%rsi,%rax)
	addq	$16, %rax
	cmpl	%ecx, %edi
	ja	.L15
	addl	%r8d, %edx
	cmpl	%r8d, %r9d
	je	.L16
.L14:
	movslq	%edx, %rax
	movq	-104(%rbp), %rdi
	movl	0(%r13,%rax,4), %ecx
	imull	%edi, %ecx
	addl	%ecx, (%r12,%rax,4)
	leal	1(%rdx), %eax
	cmpl	%r14d, %eax
	jge	.L16
	cltq
	addl	$2, %edx
	movl	0(%r13,%rax,4), %ecx
	imull	%edi, %ecx
	addl	%ecx, (%r12,%rax,4)
	cmpl	%edx, %r14d
	jle	.L16
	movslq	%edx, %rdx
	movl	-104(%rbp), %eax
	imull	0(%r13,%rdx,4), %eax
	addl	%eax, (%r12,%rdx,4)
.L16:
	leaq	-64(%rbp), %rsi
	xorl	%edi, %edi
	subl	$1, %r14d
	movslq	%r14d, %r14
	call	clock_gettime
	movq	-64(%rbp), %rax
	subq	-80(%rbp), %rax
	movl	$.LC2, %esi
	movl	(%r12,%r14,4), %ecx
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	-56(%rbp), %rax
	subq	-72(%rbp), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	-88(%rbp), %rax
	movl	0(,%rax,4), %edx
	xorl	%eax, %eax
	divsd	.LC1(%rip), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -96(%rbp)
	call	__printf_chk
	movsd	-96(%rbp), %xmm0
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
.L18:
	.cfi_restore_state
	xorl	%edx, %edx
	jmp	.L11
.L21:
	movl	$3, %edx
	jmp	.L12
.L19:
	movl	$1, %edx
	jmp	.L12
.L20:
	movl	$2, %edx
	jmp	.L12
.L3:
	leaq	-80(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	jmp	.L16
.L29:
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
