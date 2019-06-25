	.file	"ej1a.c"
	.section	.rodata
	.align 8
.LC1:
	.string	"Primera componente: %d, \303\232ltima componente: %d"
	.align 8
.LC2:
	.string	"\nTiempo(seg) Producto Matriz-Matriz:"
.LC3:
	.string	"%11.9f\t"
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
	subq	$392, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movl	%edi, -196(%rbp)
	movq	%rsi, -208(%rbp)
	movq	%rsp, %rax
	movq	%rax, -392(%rbp)
	movq	-208(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -168(%rbp)
	movl	-168(%rbp), %esi
	movl	-168(%rbp), %edi
	movslq	%esi, %rax
	subq	$1, %rax
	movq	%rax, -160(%rbp)
	movslq	%esi, %rax
	movq	%rax, -224(%rbp)
	movq	$0, -216(%rbp)
	movslq	%esi, %rax
	salq	$2, %rax
	movq	%rax, -224(%rbp)
	movslq	%edi, %rax
	subq	$1, %rax
	movq	%rax, -152(%rbp)
	movslq	%esi, %rax
	movq	%rax, %r14
	movl	$0, %r15d
	movslq	%edi, %rax
	movq	%rax, %r12
	movl	$0, %r13d
	movq	%r15, %rdx
	imulq	%r12, %rdx
	movq	%r13, %rax
	imulq	%r14, %rax
	leaq	(%rdx,%rax), %rcx
	movq	%r14, %rax
	mulq	%r12
	addq	%rdx, %rcx
	movq	%rcx, %rdx
	movslq	%esi, %rax
	movq	%rax, -240(%rbp)
	movq	$0, -232(%rbp)
	movslq	%edi, %rax
	movq	%rax, -256(%rbp)
	movq	$0, -248(%rbp)
	movq	-240(%rbp), %r14
	movq	-232(%rbp), %r15
	movq	%r15, %rdx
	movq	-256(%rbp), %r10
	movq	-248(%rbp), %r11
	imulq	%r10, %rdx
	movq	%r11, %rax
	imulq	%r14, %rax
	leaq	(%rdx,%rax), %rcx
	movq	%r14, %rax
	mulq	%r10
	addq	%rdx, %rcx
	movq	%rcx, %rdx
	movslq	%esi, %rdx
	movslq	%edi, %rax
	imulq	%rdx, %rax
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ebx
	movl	$0, %edx
	divq	%rbx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -144(%rbp)
	movl	-168(%rbp), %esi
	movl	-168(%rbp), %edi
	movslq	%esi, %rax
	subq	$1, %rax
	movq	%rax, -136(%rbp)
	movslq	%esi, %rax
	movq	%rax, -416(%rbp)
	movq	$0, -408(%rbp)
	movslq	%esi, %rax
	leaq	0(,%rax,4), %r13
	movslq	%edi, %rax
	subq	$1, %rax
	movq	%rax, -128(%rbp)
	movslq	%esi, %rax
	movq	%rax, -272(%rbp)
	movq	$0, -264(%rbp)
	movslq	%edi, %rax
	movq	%rax, -288(%rbp)
	movq	$0, -280(%rbp)
	movq	-272(%rbp), %r10
	movq	-264(%rbp), %r11
	movq	%r11, %rdx
	movq	-288(%rbp), %r8
	movq	-280(%rbp), %r9
	imulq	%r8, %rdx
	movq	%r9, %rax
	imulq	%r10, %rax
	leaq	(%rdx,%rax), %rcx
	movq	%r10, %rax
	mulq	%r8
	addq	%rdx, %rcx
	movq	%rcx, %rdx
	movslq	%esi, %rax
	movq	%rax, -304(%rbp)
	movq	$0, -296(%rbp)
	movslq	%edi, %rax
	movq	%rax, -320(%rbp)
	movq	$0, -312(%rbp)
	movq	-304(%rbp), %r8
	movq	-296(%rbp), %r9
	movq	%r9, %rdx
	movq	-320(%rbp), %r14
	movq	-312(%rbp), %r15
	imulq	%r14, %rdx
	movq	%r15, %rax
	imulq	%r8, %rax
	leaq	(%rdx,%rax), %rcx
	movq	%r8, %rax
	mulq	%r14
	addq	%rdx, %rcx
	movq	%rcx, %rdx
	movslq	%esi, %rdx
	movslq	%edi, %rax
	imulq	%rdx, %rax
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ebx
	movl	$0, %edx
	divq	%rbx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -120(%rbp)
	movl	-168(%rbp), %esi
	movl	-168(%rbp), %edi
	movslq	%esi, %rax
	subq	$1, %rax
	movq	%rax, -112(%rbp)
	movslq	%esi, %rax
	movq	%rax, -432(%rbp)
	movq	$0, -424(%rbp)
	movslq	%esi, %rax
	leaq	0(,%rax,4), %r12
	movslq	%edi, %rax
	subq	$1, %rax
	movq	%rax, -104(%rbp)
	movslq	%esi, %rax
	movq	%rax, -336(%rbp)
	movq	$0, -328(%rbp)
	movslq	%edi, %rax
	movq	%rax, -352(%rbp)
	movq	$0, -344(%rbp)
	movq	-336(%rbp), %r14
	movq	-328(%rbp), %r15
	movq	%r15, %rdx
	movq	-352(%rbp), %r10
	movq	-344(%rbp), %r11
	imulq	%r10, %rdx
	movq	%r11, %rax
	imulq	%r14, %rax
	leaq	(%rdx,%rax), %rcx
	movq	%r14, %rax
	mulq	%r10
	addq	%rdx, %rcx
	movq	%rcx, %rdx
	movslq	%esi, %rax
	movq	%rax, -368(%rbp)
	movq	$0, -360(%rbp)
	movslq	%edi, %rax
	movq	%rax, -384(%rbp)
	movq	$0, -376(%rbp)
	movq	-368(%rbp), %r10
	movq	-360(%rbp), %r11
	movq	%r11, %rdx
	movq	-384(%rbp), %r8
	movq	-376(%rbp), %r9
	imulq	%r8, %rdx
	movq	%r9, %rax
	imulq	%r10, %rax
	leaq	(%rdx,%rax), %rcx
	movq	%r10, %rax
	mulq	%r8
	addq	%rdx, %rcx
	movq	%rcx, %rdx
	movslq	%esi, %rdx
	movslq	%edi, %rax
	imulq	%rdx, %rax
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ebx
	movl	$0, %edx
	divq	%rbx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -96(%rbp)
	movl	-168(%rbp), %eax
	imull	-168(%rbp), %eax
	movl	%eax, -164(%rbp)
	movl	$0, -180(%rbp)
	jmp	.L2
.L5:
	movl	$0, -176(%rbp)
	jmp	.L3
.L4:
	movq	%r12, %rsi
	shrq	$2, %rsi
	movq	-96(%rbp), %rax
	movl	-176(%rbp), %edx
	movslq	%edx, %rcx
	movl	-180(%rbp), %edx
	movslq	%edx, %rdx
	imulq	%rsi, %rdx
	addq	%rcx, %rdx
	movl	$0, (%rax,%rdx,4)
	addl	$1, -176(%rbp)
.L3:
	movl	-176(%rbp), %eax
	cmpl	-168(%rbp), %eax
	jl	.L4
	addl	$1, -180(%rbp)
.L2:
	movl	-180(%rbp), %eax
	cmpl	-168(%rbp), %eax
	jl	.L5
	movl	$0, -180(%rbp)
	jmp	.L6
.L9:
	movl	$0, -176(%rbp)
	jmp	.L7
.L8:
	movq	-224(%rbp), %rbx
	shrq	$2, %rbx
	call	rand
	cltd
	idivl	-164(%rbp)
	movq	-144(%rbp), %rax
	movl	-176(%rbp), %ecx
	movslq	%ecx, %rsi
	movl	-180(%rbp), %ecx
	movslq	%ecx, %rcx
	imulq	%rbx, %rcx
	addq	%rsi, %rcx
	movl	%edx, (%rax,%rcx,4)
	movq	%r13, %rbx
	shrq	$2, %rbx
	call	rand
	cltd
	idivl	-164(%rbp)
	movq	-120(%rbp), %rax
	movl	-180(%rbp), %ecx
	movslq	%ecx, %rsi
	movl	-176(%rbp), %ecx
	movslq	%ecx, %rcx
	imulq	%rbx, %rcx
	addq	%rsi, %rcx
	movl	%edx, (%rax,%rcx,4)
	addl	$1, -176(%rbp)
.L7:
	movl	-176(%rbp), %eax
	cmpl	-168(%rbp), %eax
	jl	.L8
	addl	$1, -180(%rbp)
.L6:
	movl	-180(%rbp), %eax
	cmpl	-168(%rbp), %eax
	jl	.L9
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	$0, -180(%rbp)
	jmp	.L10
.L15:
	movl	$0, -176(%rbp)
	jmp	.L11
.L14:
	movl	$0, -172(%rbp)
	jmp	.L12
.L13:
	movq	%r12, %r8
	shrq	$2, %r8
	movq	%r12, %rsi
	shrq	$2, %rsi
	movq	-96(%rbp), %rax
	movl	-176(%rbp), %edx
	movslq	%edx, %rcx
	movl	-180(%rbp), %edx
	movslq	%edx, %rdx
	imulq	%rsi, %rdx
	addq	%rcx, %rdx
	movl	(%rax,%rdx,4), %edx
	movq	-224(%rbp), %rdi
	shrq	$2, %rdi
	movq	-144(%rbp), %rax
	movl	-172(%rbp), %ecx
	movslq	%ecx, %rsi
	movl	-180(%rbp), %ecx
	movslq	%ecx, %rcx
	imulq	%rdi, %rcx
	addq	%rsi, %rcx
	movl	(%rax,%rcx,4), %ecx
	movq	%r13, %r9
	shrq	$2, %r9
	movq	-120(%rbp), %rax
	movl	-172(%rbp), %esi
	movslq	%esi, %rdi
	movl	-176(%rbp), %esi
	movslq	%esi, %rsi
	imulq	%r9, %rsi
	addq	%rdi, %rsi
	movl	(%rax,%rsi,4), %eax
	imull	%ecx, %eax
	leal	(%rdx,%rax), %ecx
	movq	-96(%rbp), %rax
	movl	-176(%rbp), %edx
	movslq	%edx, %rsi
	movl	-180(%rbp), %edx
	movslq	%edx, %rdx
	imulq	%r8, %rdx
	addq	%rsi, %rdx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -172(%rbp)
.L12:
	movl	-172(%rbp), %eax
	cmpl	-168(%rbp), %eax
	jl	.L13
	addl	$1, -176(%rbp)
.L11:
	movl	-176(%rbp), %eax
	cmpl	-168(%rbp), %eax
	jl	.L14
	addl	$1, -180(%rbp)
.L10:
	movl	-180(%rbp), %eax
	cmpl	-168(%rbp), %eax
	jl	.L15
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
	movsd	.LC0(%rip), %xmm2
	divsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -88(%rbp)
	movq	%r12, %rsi
	shrq	$2, %rsi
	movl	-168(%rbp), %eax
	leal	-1(%rax), %edx
	movl	-168(%rbp), %eax
	leal	-1(%rax), %ecx
	movq	-96(%rbp), %rax
	movslq	%ecx, %rcx
	movslq	%edx, %rdx
	imulq	%rsi, %rdx
	addq	%rcx, %rdx
	movl	(%rax,%rdx,4), %edx
	movq	-96(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$.LC2, %edi
	call	puts
	movq	-88(%rbp), %rax
	movq	%rax, -224(%rbp)
	movsd	-224(%rbp), %xmm0
	movl	$.LC3, %edi
	movl	$1, %eax
	call	printf
	movl	$10, %edi
	call	putchar
	movq	-392(%rbp), %rsp
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
.LC0:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
