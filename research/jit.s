	.file	"jit.c"
	.text
.globl MAP
	.def	MAP;	.scl	2;	.type	32;	.endef
MAP:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movq	16(%rbp), %rax
	movl	32(%rbp), %edx
	movl	%edx, 16(%rax)
	movq	16(%rbp), %rax
	movl	16(%rax), %ecx
	movq	16(%rbp), %rax
	movq	24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	16(%rbp), %rax
	movq	8(%rax), %rax
	movl	%ecx, %r9d
	movl	$12288, %r8d
	movq	%rax, %rdx
	movl	$0, %ecx
	movq	__imp_VirtualAlloc(%rip), %rax
	call	*%rax
	movq	16(%rbp), %rdx
	movq	%rax, (%rdx)
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	leave
	ret
.globl UNMAP
	.def	UNMAP;	.scl	2;	.type	32;	.endef
UNMAP:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	movl	$32768, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	movq	__imp_VirtualFree(%rip), %rax
	call	*%rax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	leave
	ret
.globl PROTECT
	.def	PROTECT;	.scl	2;	.type	32;	.endef
PROTECT:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$56, %rsp
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	24(%rbp), %edx
	movl	%edx, 16(%rax)
	movq	16(%rbp), %rax
	movl	16(%rax), %ecx
	movq	16(%rbp), %rax
	movq	8(%rax), %rdx
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	movq	-24(%rbp), %rbx
	movq	%rbx, %r9
	movl	%ecx, %r8d
	movq	%rax, %rcx
	movq	__imp_VirtualProtect(%rip), %rax
	call	*%rax
	addq	$56, %rsp
	popq	%rbx
	leave
	ret
	.section .rdata,"dr"
.LC0:
	.ascii "MAP\0"
	.text
.globl alloc_writable_memory
	.def	alloc_writable_memory;	.scl	2;	.type	32;	.endef
alloc_writable_memory:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movq	%rcx, 16(%rbp)
	movq	-8(%rbp), %rax
	movl	$4, %r8d
	movq	16(%rbp), %rdx
	movq	%rax, %rcx
	call	MAP
	movq	%rax, -16(%rbp)
	cmpq	$-1, -16(%rbp)
	jne	.L5
	leaq	.LC0(%rip), %rcx
	call	perror
	movl	$0, %eax
	jmp	.L6
.L5:
	movq	-16(%rbp), %rax
.L6:
	leave
	ret
	.section .rdata,"dr"
.LC1:
	.ascii "PROTECT\0"
	.text
.globl make_memory_executable
	.def	make_memory_executable;	.scl	2;	.type	32;	.endef
make_memory_executable:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	$32, %edx
	movq	16(%rbp), %rcx
	call	PROTECT
	cmpl	$-1, %eax
	jne	.L8
	leaq	.LC1(%rip), %rcx
	call	perror
	movl	$-1, %eax
	jmp	.L9
.L8:
	movl	$0, %eax
.L9:
	leave
	ret
.globl emit_code_into_memory
	.def	emit_code_into_memory;	.scl	2;	.type	32;	.endef
emit_code_into_memory:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movq	%rcx, 16(%rbp)
	movb	$85, -16(%rbp)
	movb	$72, -15(%rbp)
	movb	$-119, -14(%rbp)
	movb	$-27, -13(%rbp)
	movb	$-119, -12(%rbp)
	movb	$77, -11(%rbp)
	movb	$16, -10(%rbp)
	movb	$-117, -9(%rbp)
	movb	$69, -8(%rbp)
	movb	$16, -7(%rbp)
	movb	$-125, -6(%rbp)
	movb	$-64, -5(%rbp)
	movb	$2, -4(%rbp)
	movb	$-55, -3(%rbp)
	movb	$-61, -2(%rbp)
	movb	$-112, -1(%rbp)
	leaq	-16(%rbp), %rax
	movl	$16, %r8d
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	memcpy
	leave
	ret
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC2:
	.ascii "Starting jit\0"
.LC3:
	.ascii "result = %li\12\0"
	.text
.globl main
	.def	main;	.scl	2;	.type	32;	.endef
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	leaq	.LC2(%rip), %rcx
	call	puts
	movl	$1024, %ecx
	call	alloc_writable_memory
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	emit_code_into_memory
	movq	-8(%rbp), %rax
	movl	$1024, %edx
	movq	%rax, %rcx
	call	make_memory_executable
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	$2, %ecx
	call	*%rax
	movl	%eax, %edx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	UNMAP
	movl	$0, %eax
	leave
	ret
	.def	perror;	.scl	2;	.type	32;	.endef
	.def	memcpy;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
