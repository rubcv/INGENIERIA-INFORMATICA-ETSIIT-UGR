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
	subq	$152, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movq	8(%rsi), %rdi
	xorl	%esi, %esi
	call	strtol
	movq	%rax, %rdi
	movl	%eax, %ebx
	movq	%rax, -192(%rbp)
	movl	%eax, %ecx
	movl	%eax, -96(%rbp)
	cltq
	leaq	0(,%rax,4), %r12
	imulq	%rax, %rax
	imull	%edi, %ebx
	leaq	18(,%rax,4), %rax
	andq	$-16, %rax
	subq	%rax, %rsp
	movq	%rsp, -112(%rbp)
	subq	%rax, %rsp
	movq	%rsp, %r14
	subq	%rax, %rsp
	leaq	3(%rsp), %rax
	movq	%rax, -176(%rbp)
	shrq	$2, -176(%rbp)
	movq	-176(%rbp), %rax
	salq	$2, %rax
	testl	%edi, %edi
	movq	%rax, %r15
	movq	%rax, -184(%rbp)
	jle	.L2
	shrq	$2, %r12
	xorl	%r13d, %r13d
	movl	%ebx, -100(%rbp)
	leaq	0(,%r12,4), %rdi
	movq	%r12, -88(%rbp)
	movl	%ecx, %r12d
	movq	%r14, -120(%rbp)
	movl	%ecx, -104(%rbp)
	movq	%r15, %r14
	movq	%rdi, -152(%rbp)
	movl	%r13d, %r15d
	salq	$2, %r12
	movl	%ecx, %ebx
	movq	%rdi, %r13
	.p2align 4,,10
	.p2align 3
.L3:
	xorl	%esi, %esi
	movq	%r14, %rdi
	movq	%r12, %rdx
	addl	$1, %r15d
	addq	%r13, %r14
	call	memset
	cmpl	%ebx, %r15d
	jl	.L3
	movq	-120(%rbp), %r14
	movq	-112(%rbp), %r12
	movl	-100(%rbp), %ebx
	movl	$0, -100(%rbp)
	.p2align 4,,10
	.p2align 3
.L4:
	movslq	-100(%rbp), %r15
	xorl	%r13d, %r13d
	.p2align 4,,10
	.p2align 3
.L9:
	call	rand
	cltd
	idivl	%ebx
	movl	%edx, (%r12,%r13,4)
	call	rand
	movslq	%r13d, %rsi
	cltd
	addq	$1, %r13
	imulq	-88(%rbp), %rsi
	idivl	%ebx
	addq	%r15, %rsi
	cmpl	%r13d, -96(%rbp)
	movl	%edx, (%r14,%rsi,4)
	jg	.L9
	addl	$1, -100(%rbp)
	addq	-152(%rbp), %r12
	movl	-96(%rbp), %eax
	cmpl	%eax, -100(%rbp)
	jl	.L4
	leaq	-80(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	-112(%rbp), %rax
	movq	-184(%rbp), %rbx
	movq	$0, -160(%rbp)
	movl	$0, -136(%rbp)
	movq	%rax, -168(%rbp)
	movq	%rbx, -144(%rbp)
	movq	%rax, %r13
	.p2align 4,,10
	.p2align 3
.L23:
	movq	-168(%rbp), %rax
	movl	-104(%rbp), %edi
	movslq	-136(%rbp), %rbx
	movq	-144(%rbp), %r9
	andl	$15, %eax
	shrq	$2, %rax
	negq	%rax
	andl	$3, %eax
	cmpl	%eax, %edi
	movl	%eax, %ecx
	movl	%edi, %eax
	cmovbe	%edi, %ecx
	cmpl	$6, %edi
	cmovbe	%edi, %ecx
	xorl	%r11d, %r11d
	xorl	%r8d, %r8d
	subl	%ecx, %eax
	movl	%ecx, %edi
	imulq	-88(%rbp), %rbx
	movl	%eax, -132(%rbp)
	shrl	$2, %eax
	movq	%rdi, -128(%rbp)
	movl	%eax, -112(%rbp)
	sall	$2, %eax
	movl	%eax, -100(%rbp)
	movq	%rdi, %rax
	addq	-160(%rbp), %rax
	leaq	0(%r13,%rbx,4), %rdi
	leaq	0(%r13,%rax,4), %r12
	jmp	.L22
	.p2align 4,,10
	.p2align 3
.L41:
	movslq	%r8d, %rdx
	movl	(%rdi), %esi
	imulq	-88(%rbp), %rdx
	leaq	(%r14,%rdx,4), %rdx
	imull	(%rdx), %esi
	addl	%esi, %eax
	cmpl	$1, %ecx
	je	.L27
	movl	4(%rdi), %esi
	imull	4(%rdx), %esi
	addl	%esi, %eax
	cmpl	$2, %ecx
	je	.L28
	movl	8(%rdi), %esi
	imull	8(%rdx), %esi
	addl	%esi, %eax
	cmpl	$3, %ecx
	je	.L29
	movl	12(%rdi), %esi
	imull	12(%rdx), %esi
	addl	%esi, %eax
	cmpl	$4, %ecx
	je	.L30
	movl	16(%rdi), %esi
	imull	16(%rdx), %esi
	addl	%esi, %eax
	cmpl	$5, %ecx
	je	.L31
	movl	20(%rdi), %esi
	imull	20(%rdx), %esi
	addl	%esi, %eax
	movl	$6, %esi
.L17:
	cmpl	%ecx, -104(%rbp)
	je	.L18
.L16:
	movl	-100(%rbp), %edx
	testl	%edx, %edx
	je	.L19
	movq	-128(%rbp), %rdx
	pxor	%xmm3, %xmm3
	xorl	%r10d, %r10d
	addq	%r11, %rdx
	leaq	(%r14,%rdx,4), %r15
	xorl	%edx, %edx
.L20:
	movdqu	(%r15,%rdx), %xmm1
	addl	$1, %r10d
	movdqa	%xmm1, %xmm4
	psrlq	$32, %xmm1
	movdqa	(%r12,%rdx), %xmm2
	pmuludq	(%r12,%rdx), %xmm4
	pshufd	$8, %xmm4, %xmm0
	addq	$16, %rdx
	psrlq	$32, %xmm2
	pmuludq	%xmm2, %xmm1
	pshufd	$8, %xmm1, %xmm1
	cmpl	%r10d, -112(%rbp)
	punpckldq	%xmm1, %xmm0
	paddd	%xmm0, %xmm3
	ja	.L20
	movdqa	%xmm3, %xmm5
	movl	-100(%rbp), %edx
	psrldq	$8, %xmm5
	paddd	%xmm5, %xmm3
	movdqa	%xmm3, %xmm6
	addl	%edx, %esi
	psrldq	$4, %xmm6
	paddd	%xmm6, %xmm3
	movd	%xmm3, -120(%rbp)
	movl	-120(%rbp), %r10d
	addl	%r10d, %eax
	cmpl	%edx, -132(%rbp)
	je	.L18
.L19:
	movslq	%r8d, %rdx
	movslq	%esi, %r15
	imulq	-88(%rbp), %rdx
	leaq	(%r15,%rbx), %r10
	movl	0(%r13,%r10,4), %r10d
	addq	%rdx, %r15
	imull	(%r14,%r15,4), %r10d
	leal	1(%rsi), %r15d
	addl	%r10d, %eax
	cmpl	-96(%rbp), %r15d
	jge	.L18
	movslq	%r15d, %r15
	addl	$2, %esi
	leaq	(%r15,%rbx), %r10
	addq	%rdx, %r15
	movl	0(%r13,%r10,4), %r10d
	imull	(%r14,%r15,4), %r10d
	addl	%r10d, %eax
	cmpl	-96(%rbp), %esi
	jge	.L18
	movslq	%esi, %rsi
	leaq	(%rsi,%rbx), %r10
	addq	%rsi, %rdx
	movl	0(%r13,%r10,4), %esi
	imull	(%r14,%rdx,4), %esi
	addl	%esi, %eax
.L18:
	movl	%eax, (%r9)
	addl	$1, %r8d
	addq	$4, %r9
	addq	-88(%rbp), %r11
	cmpl	-96(%rbp), %r8d
	jge	.L15
.L22:
	testl	%ecx, %ecx
	movl	(%r9), %eax
	jne	.L41
	xorl	%esi, %esi
	jmp	.L16
	.p2align 4,,10
	.p2align 3
.L31:
	movl	$5, %esi
	jmp	.L17
	.p2align 4,,10
	.p2align 3
.L30:
	movl	$4, %esi
	jmp	.L17
	.p2align 4,,10
	.p2align 3
.L29:
	movl	$3, %esi
	jmp	.L17
	.p2align 4,,10
	.p2align 3
.L28:
	movl	$2, %esi
	jmp	.L17
	.p2align 4,,10
	.p2align 3
.L27:
	movl	$1, %esi
	jmp	.L17
	.p2align 4,,10
	.p2align 3
.L15:
	addl	$1, -136(%rbp)
	movq	-152(%rbp), %rax
	addq	%rax, -144(%rbp)
	addq	%rax, -168(%rbp)
	movq	-88(%rbp), %rax
	addq	%rax, -160(%rbp)
	movl	-96(%rbp), %eax
	cmpl	%eax, -136(%rbp)
	jl	.L23
.L21:
	leaq	-64(%rbp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	-64(%rbp), %rax
	subq	-80(%rbp), %rax
	movl	$.LC1, %esi
	movl	-192(%rbp), %edx
	movq	-184(%rbp), %rbx
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	-56(%rbp), %rax
	subq	-72(%rbp), %rax
	subl	$1, %edx
	movslq	%edx, %rdx
	cvtsi2sdq	%rax, %xmm1
	movq	-88(%rbp), %rax
	addq	$1, %rax
	imulq	%rdx, %rax
	movl	(%rbx,%rax,4), %ecx
	movq	-176(%rbp), %rax
	divsd	.LC0(%rip), %xmm1
	movl	0(,%rax,4), %edx
	xorl	%eax, %eax
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -96(%rbp)
	call	__printf_chk
	movl	$.LC2, %edi
	call	puts
	movsd	-96(%rbp), %xmm0
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
	movq	%r12, -88(%rbp)
	jmp	.L21
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
