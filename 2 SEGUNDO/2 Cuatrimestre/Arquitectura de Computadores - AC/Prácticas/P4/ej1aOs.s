	.file	"ej1a.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Primera componente: %d, \303\232ltima componente: %d"
.LC2:
	.string	"\nTiempo(seg) Producto Matriz-Matriz:"
.LC3:
	.string	"%11.9f\t"
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
	subq	$88, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movq	8(%rsi), %rdi
	call	atoi
	movslq	%eax, %rbx
	movl	%eax, %r13d
	xorl	%edx, %edx
	movq	%rbx, %rax
	imulq	%rbx, %rax
	salq	$2, %rbx
	shrq	$2, %rbx
	leaq	18(,%rax,4), %rax
	andq	$-16, %rax
	subq	%rax, %rsp
	movq	%rsp, -112(%rbp)
	subq	%rax, %rsp
	movq	%rsp, -120(%rbp)
	subq	%rax, %rsp
	movl	%r13d, %eax
	imull	%r13d, %eax
	leaq	3(%rsp), %r12
	shrq	$2, %r12
	leaq	0(,%r12,4), %r14
	movl	%eax, -92(%rbp)
	leaq	0(,%rbx,4), %rax
	movq	%r14, %rsi
	movq	%rax, -88(%rbp)
.L2:
	cmpl	%r13d, %edx
	jl	.L4
	movq	-112(%rbp), %rax
	xorl	%edi, %edi
	movq	%rax, -104(%rbp)
	jmp	.L5
.L4:
	xorl	%eax, %eax
.L6:
	cmpl	%eax, %r13d
	jle	.L18
	movl	$0, (%rsi,%rax,4)
	incq	%rax
	jmp	.L6
.L18:
	incl	%edx
	addq	-88(%rbp), %rsi
	jmp	.L2
.L19:
	movq	-88(%rbp), %rax
	addq	%rax, -104(%rbp)
	incl	%edi
.L5:
	cmpl	%r13d, %edi
	jge	.L8
	movslq	%edi, %rax
	xorl	%r15d, %r15d
	movq	%rax, -128(%rbp)
.L9:
	cmpl	%r13d, %r15d
	jge	.L19
	movl	%edi, -96(%rbp)
	call	rand
	cltd
	idivl	-92(%rbp)
	movq	-104(%rbp), %rax
	movl	%edx, (%rax,%r15,4)
	call	rand
	cltd
	movslq	%r15d, %r8
	movl	-96(%rbp), %edi
	idivl	-92(%rbp)
	movq	-120(%rbp), %rax
	incq	%r15
	imulq	%rbx, %r8
	addq	-128(%rbp), %r8
	movl	%edx, (%rax,%r8,4)
	jmp	.L9
.L8:
	leaq	-80(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	xorl	%esi, %esi
	xorl	%r8d, %r8d
.L10:
	cmpl	%r13d, %r8d
	jge	.L14
	movq	-112(%rbp), %rcx
	movq	-120(%rbp), %rdi
	leaq	(%r14,%rsi), %r10
	xorl	%eax, %eax
	leaq	(%rcx,%rsi), %r11
.L15:
	cmpl	%eax, %r13d
	jle	.L12
	xorl	%edx, %edx
.L13:
	cmpl	%edx, %r13d
	jle	.L20
	movl	(%r11,%rdx,4), %r9d
	imull	(%rdi,%rdx,4), %r9d
	incq	%rdx
	addl	%r9d, (%r10,%rax,4)
	jmp	.L13
.L20:
	incq	%rax
	addq	-88(%rbp), %rdi
	jmp	.L15
.L12:
	incl	%r8d
	addq	-88(%rbp), %rsi
	jmp	.L10
.L14:
	leaq	-64(%rbp), %rsi
	xorl	%edi, %edi
	incq	%rbx
	call	clock_gettime
	movq	-64(%rbp), %rax
	subq	-80(%rbp), %rax
	leal	-1(%r13), %ecx
	movl	0(,%r12,4), %edx
	movl	$.LC1, %esi
	movl	$1, %edi
	movslq	%ecx, %rcx
	imulq	%rcx, %rbx
	cvtsi2sdq	%rax, %xmm0
	movq	-56(%rbp), %rax
	subq	-72(%rbp), %rax
	movl	(%r14,%rbx,4), %ecx
	cvtsi2sdq	%rax, %xmm1
	xorl	%eax, %eax
	divsd	.LC0(%rip), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -88(%rbp)
	call	__printf_chk
	movl	$.LC2, %edi
	call	puts
	movsd	-88(%rbp), %xmm0
	movl	$.LC3, %esi
	movl	$1, %edi
	movb	$1, %al
	call	__printf_chk
	movl	$10, %edi
	call	putchar
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
.LC0:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
