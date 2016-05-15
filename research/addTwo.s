	.file	"addTwo.c"
	.text
.globl addTwo
	.def	addTwo;	.scl	2;	.type	32;	.endef
addTwo:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %eax
	addl	$2, %eax
	leave
	ret
