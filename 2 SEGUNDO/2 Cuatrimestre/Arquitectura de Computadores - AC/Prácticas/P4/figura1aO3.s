	.file	"figura1a.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC3:
	.string	"Tiempo(seg):%11.9f\t\n"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC4:
	.string	"Primera componente: %d, \303\232ltima componente: %d"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB39:
	.cfi_startproc
	subq	$160040, %rsp
	.cfi_def_cfa_offset 160048
	xorl	%edi, %edi
	movq	%rsp, %rsi
	call	clock_gettime
	movdqa	.LC1(%rip), %xmm11
	leaq	36(%rsp), %rdx
	leaq	160036(%rsp), %rcx
	movdqa	.LC0(%rip), %xmm0
	.p2align 4,,10
	.p2align 3
.L2:
	pxor	%xmm9, %xmm9
	movl	$s, %eax
	movdqa	%xmm0, %xmm10
	movdqa	%xmm9, %xmm8
	paddd	%xmm11, %xmm10
	movdqa	%xmm9, %xmm7
	movdqa	%xmm9, %xmm6
	movdqa	%xmm9, %xmm5
	movdqa	%xmm9, %xmm4
	movdqa	%xmm9, %xmm3
	movdqa	%xmm9, %xmm2
	.p2align 4,,10
	.p2align 3
.L5:
	movd	(%rax), %xmm1
	addq	$32, %rax
	pshufd	$0, %xmm1, %xmm1
	pslld	$1, %xmm1
	paddd	%xmm0, %xmm1
	paddd	%xmm1, %xmm2
	movd	-24(%rax), %xmm1
	pshufd	$0, %xmm1, %xmm1
	pslld	$1, %xmm1
	paddd	%xmm0, %xmm1
	paddd	%xmm1, %xmm3
	movd	-16(%rax), %xmm1
	pshufd	$0, %xmm1, %xmm1
	pslld	$1, %xmm1
	paddd	%xmm0, %xmm1
	paddd	%xmm1, %xmm4
	movd	-8(%rax), %xmm1
	pshufd	$0, %xmm1, %xmm1
	pslld	$1, %xmm1
	paddd	%xmm0, %xmm1
	paddd	%xmm1, %xmm5
	movd	-28(%rax), %xmm1
	pshufd	$0, %xmm1, %xmm12
	movdqa	%xmm12, %xmm1
	pslld	$1, %xmm1
	paddd	%xmm12, %xmm1
	psubd	%xmm0, %xmm1
	paddd	%xmm1, %xmm6
	movd	-20(%rax), %xmm1
	pshufd	$0, %xmm1, %xmm12
	movdqa	%xmm12, %xmm1
	pslld	$1, %xmm1
	paddd	%xmm12, %xmm1
	psubd	%xmm0, %xmm1
	paddd	%xmm1, %xmm7
	movd	-12(%rax), %xmm1
	pshufd	$0, %xmm1, %xmm12
	movdqa	%xmm12, %xmm1
	pslld	$1, %xmm1
	paddd	%xmm12, %xmm1
	psubd	%xmm0, %xmm1
	paddd	%xmm1, %xmm8
	movd	-4(%rax), %xmm1
	cmpq	$s+40000, %rax
	pshufd	$0, %xmm1, %xmm12
	movdqa	%xmm12, %xmm1
	pslld	$1, %xmm1
	paddd	%xmm12, %xmm1
	psubd	%xmm0, %xmm1
	paddd	%xmm1, %xmm9
	jne	.L5
	paddd	%xmm4, %xmm3
	paddd	%xmm5, %xmm3
	paddd	%xmm2, %xmm3
	movdqa	%xmm3, %xmm0
	paddd	%xmm8, %xmm7
	paddd	%xmm9, %xmm7
	paddd	%xmm6, %xmm7
	addq	$16, %rdx
	pcmpgtd	%xmm7, %xmm0
	pand	%xmm0, %xmm7
	pandn	%xmm3, %xmm0
	por	%xmm7, %xmm0
	movdqu	%xmm0, -16(%rdx)
	cmpq	%rcx, %rdx
	je	.L4
	movdqa	%xmm10, %xmm0
	jmp	.L2
.L4:
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	movl	$.LC3, %esi
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	divsd	.LC2(%rip), %xmm1
	addsd	%xmm1, %xmm0
	call	__printf_chk
	movl	160028(%rsp), %ecx
	movl	32(%rsp), %edx
	movl	$.LC4, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movl	$10, %edi
	call	putchar
	addq	$160040, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.comm	s,40000,32
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	1
	.long	2
	.long	3
	.long	4
	.align 16
.LC1:
	.long	4
	.long	4
	.long	4
	.long	4
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC2:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
