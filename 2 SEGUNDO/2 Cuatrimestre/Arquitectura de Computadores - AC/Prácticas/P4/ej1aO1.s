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
	subq	$120, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol
	movq	%rax, %rcx
	movq	%rax, -144(%rbp)
	cltq
	leaq	0(,%rax,4), %rdi
	movq	%rdi, -136(%rbp)
	imulq	%rax, %rax
	leaq	18(,%rax,4), %rax
	andq	$-16, %rax
	subq	%rax, %rsp
	movq	%rsp, %r14
	subq	%rax, %rsp
	movq	%rsp, %r15
	subq	%rax, %rsp
	leaq	3(%rsp), %rax
	shrq	$2, %rax
	movq	%rax, -152(%rbp)
	salq	$2, %rax
	movq	%rax, %rdx
	movq	%rax, -160(%rbp)
	movl	%ecx, %r13d
	imull	%ecx, %r13d
	testl	%ecx, %ecx
	jle	.L2
	movl	%ecx, %ebx
	shrq	$2, %rdi
	movq	%rdi, -96(%rbp)
	leaq	0(,%rdi,4), %rax
	movq	%rax, %rsi
	movq	%rax, -112(%rbp)
	movq	%rdx, -128(%rbp)
	movl	$0, %ecx
	jmp	.L3
.L7:
	movl	$0, (%rdx,%rax,4)
	addq	$1, %rax
	cmpl	%eax, %ebx
	jg	.L7
	addl	$1, %ecx
	addq	%rsi, %rdx
	cmpl	%ebx, %ecx
	jl	.L3
	movq	%r14, -120(%rbp)
	movl	$0, -100(%rbp)
	jmp	.L6
.L3:
	movl	$0, %eax
	jmp	.L7
.L10:
	call	rand
	cltd
	idivl	%r13d
	movl	%edx, (%r14,%r12,4)
	call	rand
	movslq	%r12d, %rcx
	imulq	-96(%rbp), %rcx
	addq	-88(%rbp), %rcx
	cltd
	idivl	%r13d
	movl	%edx, (%r15,%rcx,4)
	addq	$1, %r12
	cmpl	%r12d, %ebx
	jg	.L10
	addl	$1, -100(%rbp)
	addq	-112(%rbp), %r14
	cmpl	%ebx, -100(%rbp)
	jge	.L9
.L6:
	movl	$0, %r12d
	movslq	-100(%rbp), %rax
	movq	%rax, -88(%rbp)
	jmp	.L10
.L13:
	movl	(%rdi,%rax,4), %r10d
	imull	(%rsi,%rax,4), %r10d
	addl	%r10d, %edx
	addq	$1, %rax
	cmpl	%eax, %ebx
	jg	.L13
	movl	%edx, (%rcx)
	addl	$1, %r9d
	addq	$4, %r8
	addq	%r14, %rsi
	cmpl	%ebx, %r9d
	jge	.L12
.L15:
	movq	%r8, %rcx
	movl	(%r8), %edx
	movl	$0, %eax
	jmp	.L13
.L12:
	addl	$1, %r12d
	addq	%r13, %r11
	cmpl	%ebx, %r12d
	jge	.L14
.L16:
	movq	%r15, %rsi
	movq	-128(%rbp), %rax
	leaq	(%rax,%r11), %r8
	movl	$0, %r9d
	movq	-120(%rbp), %rax
	leaq	(%rax,%r11), %rdi
	jmp	.L15
.L9:
	leaq	-80(%rbp), %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	-112(%rbp), %r14
	movq	%r14, %r13
	movl	$0, %r11d
	movl	$0, %r12d
	jmp	.L16
.L2:
	leaq	-80(%rbp), %rsi
	movl	$0, %edi
	call	clock_gettime
.L14:
	leaq	-64(%rbp), %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	-64(%rbp), %rax
	subq	-80(%rbp), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	-56(%rbp), %rax
	subq	-72(%rbp), %rax
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC0(%rip), %xmm0
	addsd	%xmm0, %xmm1
	movsd	%xmm1, -88(%rbp)
	movq	-136(%rbp), %rdx
	shrq	$2, %rdx
	movl	-144(%rbp), %eax
	subl	$1, %eax
	addq	$1, %rdx
	cltq
	imulq	%rdx, %rax
	movq	-160(%rbp), %rcx
	movl	(%rcx,%rax,4), %ecx
	movq	-152(%rbp), %rax
	movl	0(,%rax,4), %edx
	movl	$.LC1, %esi
	movl	$1, %edi
	movl	$0, %eax
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
.LC0:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
