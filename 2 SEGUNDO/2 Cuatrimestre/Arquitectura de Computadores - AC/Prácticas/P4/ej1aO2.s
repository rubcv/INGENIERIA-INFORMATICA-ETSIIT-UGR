	.file	"ej1a.c"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC1:
	.string	"Primera componente: %d, \303\232ltima componente: %d"
	.align 8
.LC2:
	.string	"\nTiempo(seg) Producto Matriz-Matriz:"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC3:
	.string	"%11.9f\t"
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
	movl	$10, %edx
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$104, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movq	8(%rsi), %rdi
	xorl	%esi, %esi
	call	strtol
	movl	%eax, %r15d
	movq	%rax, %rbx
	movq	%rax, -144(%rbp)
	cltq
	leaq	0(,%rax,4), %r12
	imulq	%rax, %rax
	imull	%r15d, %ebx
	leaq	18(,%rax,4), %rax
	andq	$-16, %rax
	subq	%rax, %rsp
	movq	%rsp, -128(%rbp)
	subq	%rax, %rsp
	movq	%rsp, %r13
	subq	%rax, %rsp
	leaq	3(%rsp), %rax
	movq	%rax, -120(%rbp)
	shrq	$2, -120(%rbp)
	movq	-120(%rbp), %rax
	salq	$2, %rax
	testl	%r15d, %r15d
	movq	%rax, %rdx
	movq	%rax, -136(%rbp)
	jle	.L2
	shrq	$2, %r12
	xorl	%ecx, %ecx
	leaq	0(,%r12,4), %rax
	movq	%r12, -96(%rbp)
	movq	%rax, -112(%rbp)
	movq	%rax, %rsi
.L3:
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L7:
	movl	$0, (%rdx,%rax,4)
	addq	$1, %rax
	cmpl	%eax, %r15d
	jg	.L7
	addl	$1, %ecx
	addq	%rsi, %rdx
	cmpl	%r15d, %ecx
	jl	.L3
	movq	-128(%rbp), %r12
	movl	$0, -100(%rbp)
.L6:
	movslq	-100(%rbp), %rax
	xorl	%r14d, %r14d
	movq	%rax, -88(%rbp)
	.p2align 4,,10
	.p2align 3
.L10:
	call	rand
	cltd
	idivl	%ebx
	movl	%edx, (%r12,%r14,4)
	call	rand
	movslq	%r14d, %rsi
	cltd
	addq	$1, %r14
	imulq	-96(%rbp), %rsi
	idivl	%ebx
	addq	-88(%rbp), %rsi
	cmpl	%r14d, %r15d
	movl	%edx, 0(%r13,%rsi,4)
	jg	.L10
	addl	$1, -100(%rbp)
	addq	-112(%rbp), %r12
	cmpl	%r15d, -100(%rbp)
	jl	.L6
	leaq	-80(%rbp), %rsi
	xorl	%edi, %edi
	xorl	%ebx, %ebx
	call	clock_gettime
	movq	-112(%rbp), %r10
	movq	-128(%rbp), %r12
	xorl	%r11d, %r11d
	movq	-136(%rbp), %r14
.L16:
	leaq	(%r14,%r11), %r8
	leaq	(%r12,%r11), %rdi
	movq	%r13, %rsi
	xorl	%r9d, %r9d
	.p2align 4,,10
	.p2align 3
.L15:
	movl	(%r8), %ecx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L13:
	movl	(%rdi,%rax,4), %edx
	imull	(%rsi,%rax,4), %edx
	addq	$1, %rax
	addl	%edx, %ecx
	cmpl	%eax, %r15d
	jg	.L13
	addl	$1, %r9d
	movl	%ecx, (%r8)
	addq	%r10, %rsi
	addq	$4, %r8
	cmpl	%r15d, %r9d
	jl	.L15
	addl	$1, %ebx
	addq	%r10, %r11
	cmpl	%r15d, %ebx
	jl	.L16
.L14:
	leaq	-64(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	-64(%rbp), %rax
	subq	-80(%rbp), %rax
	movl	$.LC1, %esi
	movl	-144(%rbp), %edx
	movq	-136(%rbp), %rbx
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	-56(%rbp), %rax
	subq	-72(%rbp), %rax
	subl	$1, %edx
	movslq	%edx, %rdx
	cvtsi2sdq	%rax, %xmm1
	movq	-96(%rbp), %rax
	addq	$1, %rax
	imulq	%rdx, %rax
	movl	(%rbx,%rax,4), %ecx
	movq	-120(%rbp), %rax
	divsd	.LC0(%rip), %xmm1
	movl	0(,%rax,4), %edx
	xorl	%eax, %eax
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -88(%rbp)
	call	__printf_chk
	movl	$.LC2, %edi
	call	puts
	movsd	-88(%rbp), %xmm0
	movl	$.LC3, %esi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk
	movl	$10, %edi
	call	putchar
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
.L2:
	.cfi_restore_state
	leaq	-80(%rbp), %rsi
	xorl	%edi, %edi
	shrq	$2, %r12
	call	clock_gettime
	movq	%r12, -96(%rbp)
	jmp	.L14
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
