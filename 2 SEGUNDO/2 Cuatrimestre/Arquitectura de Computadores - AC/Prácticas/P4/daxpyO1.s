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
	.text
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
	jg	.L2
	movq	stderr(%rip), %rcx
	movl	$26, %edx
	movl	$1, %esi
	movl	$.LC0, %edi
	call	fwrite
	movl	$-1, %edi
	call	exit
.L2:
	movq	%rsi, %r12
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol
	movq	%rax, %r14
	movq	%rax, -96(%rbp)
	movl	%eax, %ebx
	movq	16(%r12), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol
	movl	%eax, %r15d
	movslq	%r14d, %rax
	leaq	18(,%rax,4), %rax
	andq	$-16, %rax
	subq	%rax, %rsp
	movq	%rsp, %r14
	subq	%rax, %rsp
	leaq	3(%rsp), %rax
	shrq	$2, %rax
	movq	%rax, -104(%rbp)
	salq	$2, %rax
	movq	%rax, -112(%rbp)
	movq	%rax, %r13
	testl	%ebx, %ebx
	jle	.L3
	movl	$0, %r12d
.L5:
	call	rand
	cltd
	idivl	%ebx
	movl	%edx, (%r14,%r12,4)
	call	rand
	cltd
	idivl	%ebx
	movl	%edx, 0(%r13,%r12,4)
	addq	$1, %r12
	cmpl	%r12d, %ebx
	jg	.L5
	jmp	.L4
.L7:
	movl	%r15d, %edx
	imull	(%r14,%rax,4), %edx
	addl	%edx, 0(%r13,%rax,4)
	addq	$1, %rax
	cmpl	%eax, %ebx
	jg	.L7
	jmp	.L8
.L4:
	leaq	-80(%rbp), %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	$0, %eax
	jmp	.L7
.L3:
	leaq	-80(%rbp), %rsi
	movl	$0, %edi
	call	clock_gettime
.L8:
	leaq	-64(%rbp), %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	-64(%rbp), %rax
	subq	-80(%rbp), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	-56(%rbp), %rax
	subq	-72(%rbp), %rax
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC1(%rip), %xmm0
	addsd	%xmm0, %xmm1
	movsd	%xmm1, -88(%rbp)
	movl	-96(%rbp), %eax
	subl	$1, %eax
	cltq
	movq	-112(%rbp), %rcx
	movl	(%rcx,%rax,4), %ecx
	movq	-104(%rbp), %rax
	movl	0(,%rax,4), %edx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movsd	-88(%rbp), %xmm0
	movl	$.LC3, %esi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk
	movl	$0, %eax
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
.LFE39:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
