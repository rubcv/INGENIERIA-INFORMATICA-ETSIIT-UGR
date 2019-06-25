	.file	"daxpy.c"
	.section	.rodata
.LC0:
	.string	"Falta valor N y/o valor a\n"
	.align 8
.LC2:
	.string	"Primera componente: %d \303\232ltima componente: %d"
.LC3:
	.string	"\nTiempo(seg) DAXPY: %11.9f\t\n"
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
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$152, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movl	%edi, -148(%rbp)
	movq	%rsi, -160(%rbp)
	movq	%rsp, %rax
	movq	%rax, %rbx
	cmpl	$2, -148(%rbp)
	jg	.L2
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$26, %edx
	movl	$1, %esi
	movl	$.LC0, %edi
	call	fwrite
	movl	$-1, %edi
	call	exit
.L2:
	movq	-160(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -128(%rbp)
	movq	-160(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -124(%rbp)
	movl	-128(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -120(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, -176(%rbp)
	movq	$0, -168(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, -192(%rbp)
	movq	$0, -184(%rbp)
	cltq
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %esi
	movl	$0, %edx
	divq	%rsi
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -112(%rbp)
	movl	-128(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -104(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r14
	movl	$0, %r15d
	movslq	%eax, %rdx
	movq	%rdx, %r12
	movl	$0, %r13d
	cltq
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %esi
	movl	$0, %edx
	divq	%rsi
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -96(%rbp)
	movl	$0, -132(%rbp)
	jmp	.L3
.L4:
	call	rand
	cltd
	idivl	-128(%rbp)
	movl	%edx, %ecx
	movq	-112(%rbp), %rax
	movl	-132(%rbp), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	call	rand
	cltd
	idivl	-128(%rbp)
	movl	%edx, %ecx
	movq	-96(%rbp), %rax
	movl	-132(%rbp), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -132(%rbp)
.L3:
	movl	-132(%rbp), %eax
	cmpl	-128(%rbp), %eax
	jl	.L4
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	$0, -132(%rbp)
	jmp	.L5
.L6:
	movq	-112(%rbp), %rax
	movl	-132(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	imull	-124(%rbp), %eax
	movl	%eax, %ecx
	movq	-96(%rbp), %rax
	movl	-132(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	addl	%eax, %ecx
	movq	-96(%rbp), %rax
	movl	-132(%rbp), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -132(%rbp)
.L5:
	movl	-132(%rbp), %eax
	cmpl	-128(%rbp), %eax
	jl	.L6
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	-64(%rbp), %rdx
	movq	-80(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	cvtsi2sdq	%rax, %xmm1
	movq	-56(%rbp), %rdx
	movq	-72(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC1(%rip), %xmm2
	divsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -88(%rbp)
	movl	-128(%rbp), %eax
	leal	-1(%rax), %edx
	movq	-96(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %edx
	movq	-96(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movq	-88(%rbp), %rax
	movq	%rax, -176(%rbp)
	movsd	-176(%rbp), %xmm0
	movl	$.LC3, %edi
	movl	$1, %eax
	call	printf
	movq	%rbx, %rsp
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
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC1:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
