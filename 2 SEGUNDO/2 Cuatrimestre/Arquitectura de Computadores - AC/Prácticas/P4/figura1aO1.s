	.file	"figura1a.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Tiempo(seg):%11.9f\t\n"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"Primera componente: %d, \303\232ltima componente: %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB39:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$160040, %rsp
	.cfi_def_cfa_offset 160080
	movq	%rsp, %rsi
	movl	$0, %edi
	call	clock_gettime
	leaq	36(%rsp), %r13
	movl	$1, %edx
	movl	$s+40000, %r12d
	jmp	.L2
.L7:
	movl	(%rax), %ecx
	leal	(%rdx,%rcx,2), %ecx
	addl	%ecx, %esi
	movl	8(%rax), %ecx
	leal	(%rdx,%rcx,2), %ecx
	addl	%ecx, %r8d
	movl	16(%rax), %ecx
	leal	(%rdx,%rcx,2), %ecx
	addl	%ecx, %r10d
	movl	24(%rax), %ecx
	leal	(%rdx,%rcx,2), %ecx
	addl	%ecx, %ebx
	movl	4(%rax), %ecx
	leal	(%rcx,%rcx,2), %ecx
	subl	%edx, %ecx
	addl	%ecx, %edi
	movl	12(%rax), %ecx
	leal	(%rcx,%rcx,2), %ecx
	subl	%edx, %ecx
	addl	%ecx, %r9d
	movl	20(%rax), %ecx
	leal	(%rcx,%rcx,2), %ecx
	subl	%edx, %ecx
	addl	%ecx, %r11d
	movl	28(%rax), %ecx
	leal	(%rcx,%rcx,2), %ecx
	subl	%edx, %ecx
	addl	%ecx, %ebp
	addq	$32, %rax
	cmpq	%r12, %rax
	jne	.L7
	addl	%r10d, %r8d
	leal	(%rsi,%rbx), %eax
	addl	%r11d, %r9d
	addl	%r9d, %ebp
	addl	%ebp, %edi
	leal	(%rax,%r8), %eax
	cmpl	%edi, %eax
	cmovge	%edi, %eax
	movl	%eax, 0(%r13)
	addl	$1, %edx
	addq	$4, %r13
	cmpl	$40001, %edx
	je	.L6
.L2:
	movl	$s, %eax
	movl	$0, %ebp
	movl	$0, %ebx
	movl	$0, %r11d
	movl	$0, %r10d
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %edi
	movl	$0, %esi
	jmp	.L7
.L6:
	leaq	16(%rsp), %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC0(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movl	$.LC1, %esi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk
	movl	160028(%rsp), %ecx
	movl	32(%rsp), %edx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$10, %edi
	call	putchar
	addq	$160040, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
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
