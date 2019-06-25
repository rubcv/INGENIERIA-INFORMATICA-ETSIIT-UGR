	.file	"figura1a.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Tiempo(seg):%11.9f\t\n"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"Primera componente: %d, \303\232ltima componente: %d"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB39:
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
	leaq	36(%rsp), %r12
	call	clock_gettime
	movl	$1, %edx
	.p2align 4,,10
	.p2align 3
.L2:
	movl	$s, %eax
	xorl	%ebp, %ebp
	xorl	%ebx, %ebx
	xorl	%r11d, %r11d
	xorl	%r10d, %r10d
	xorl	%r9d, %r9d
	xorl	%r8d, %r8d
	xorl	%edi, %edi
	xorl	%esi, %esi
	.p2align 4,,10
	.p2align 3
.L7:
	movl	(%rax), %ecx
	addq	$32, %rax
	leal	(%rdx,%rcx,2), %ecx
	addl	%ecx, %esi
	movl	-24(%rax), %ecx
	leal	(%rdx,%rcx,2), %ecx
	addl	%ecx, %r8d
	movl	-16(%rax), %ecx
	leal	(%rdx,%rcx,2), %ecx
	addl	%ecx, %r10d
	movl	-8(%rax), %ecx
	leal	(%rdx,%rcx,2), %ecx
	addl	%ecx, %ebx
	movl	-28(%rax), %ecx
	leal	(%rcx,%rcx,2), %ecx
	subl	%edx, %ecx
	addl	%ecx, %edi
	movl	-20(%rax), %ecx
	leal	(%rcx,%rcx,2), %ecx
	subl	%edx, %ecx
	addl	%ecx, %r9d
	movl	-12(%rax), %ecx
	leal	(%rcx,%rcx,2), %ecx
	subl	%edx, %ecx
	addl	%ecx, %r11d
	movl	-4(%rax), %ecx
	leal	(%rcx,%rcx,2), %ecx
	subl	%edx, %ecx
	addl	%ecx, %ebp
	cmpq	$s+40000, %rax
	jne	.L7
	addl	%r10d, %r8d
	addl	%r11d, %r9d
	addl	%r8d, %ebx
	addl	%r9d, %ebp
	addl	%ebx, %esi
	addl	%ebp, %edi
	cmpl	%edi, %esi
	cmovge	%edi, %esi
	addl	$1, %edx
	addq	$4, %r12
	movl	%esi, -4(%r12)
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
	movl	$1, %eax
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
.LFE39:
	.size	main, .-main
	.comm	s,40000,32
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
