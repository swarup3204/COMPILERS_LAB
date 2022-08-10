	.file	"assign1.c" 
	# specifies the name of the source file associated with the object file.
	.text  
	# defines current section as text.
	.section	.rodata 
	# The .section directive makes .rodata the current section. If section does not exist, a new section with the specified name and attributes is created. ro means read only
	.align 8 
	# this directive tells next data will be aligned by %8  bytes
.LC0: 
	# LC means local constant,i.e,it is label of a local constant with id 0
	.string	"Enter the string (all lowrer case): " 
	# places character in string into object module at current location and terminates string with null byte
.LC1:
	.string	"%s"
.LC2:
	.string	"Length of the string: %d\n"
	.align 8
.LC3:
	.string	"The string in descending order: %s\n"
	.text
	.globl	main
	 # .globl directive tells the assembler that the symbol main is a global symbol.
	.type	main, @function
	 # defines type of symbol main,i.e,function

main:   # start of main function

.LFB0: # function beginning label with id 0

	# prologue of function
	.cfi_startproc
	endbr64
	# rsp  value decremented on push operation as stack frame grows from higher to lower addresses 
	pushq	%rbp
	# push base pointer to stack
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	# move stack pointer to base pointer
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	# allocate space for local variables on stack ,size = 80 bytes
	movq	%fs:40, %rax
	# move value of fs segment register to rax
	movq	%rax, -8(%rbp)
	# move value stored in rax to 8 bytes before address pointed to by rbp
	xorl	%eax, %eax  
	# set contents of eax as 0,needed as eax stores the value to be returned by function
	leaq	.LC0(%rip), %rax
	# load address of string "Enter the string (all lowrer case): " to rax
	movq	%rax, %rdi
	# move address of string "Enter the string (all lowrer case): " to rdi(1st argument to function printf)
	movl	$0, %eax
	# set value of eax to 0
	call	printf@PLT
	# call printf function defined in header files
	leaq	-64(%rbp), %rax
	# load address of input string(address of str[0]) to rax
	movq	%rax, %rsi
	# move address of input string str to rsi(2nd argument to function scanf)
	leaq	.LC1(%rip), %rax
	# load address of string "%s" to rax
	movq	%rax, %rdi
	# move address of string "%s" to rdi(1st argument to function scanf)
	movl	$0, %eax
	# set value of eax to 0
	call	__isoc99_scanf@PLT 
	# calls scanf defined in header file to take string input
	leaq	-64(%rbp), %rax
	# load address of input string(address of str[0]) into rax
	movq	%rax, %rdi
	# move address of input string to rdi(1st argument to function length)
	call	length  
	# calls length function defined in header file to find length of string
	movl	%eax, -68(%rbp)
    # move value of length of string stored in eax(the returned value by length function) to stack frame 68 bytes before address pointed to by base pointer 
	movl	-68(%rbp), %eax
	# move value of length of string stored in stack frame 68 bytes before address pointed to by base pointer to eax
	movl	%eax, %esi
	# move value of length of string stored in eax to esi(2nd argument to function sort)
	leaq	.LC2(%rip), %rax
	# load address of string "Length of the string: %d\n" to rax
	movq	%rax, %rdi
	# move address of string "Length of the string: %d\n" to rdi(1st argument to function printf)
	movl	$0, %eax
	# set value of eax to 0
	call	printf@PLT
	# call printf function defined in header file
	leaq	-32(%rbp), %rdx
	# 
	movl	-68(%rbp), %ecx

	leaq	-64(%rbp), %rax

	movl	%ecx, %esi

	movq	%rax, %rdi

	call	sort
	# calls sort function defined in source file to sort string alphabetically
	leaq	-32(%rbp), %rax
	#
	movq	%rax, %rsi

	leaq	.LC3(%rip), %rax

	movq	%rax, %rdi

	movl	$0, %eax

	call	printf@PLT

	movl	$0, %eax

	movq	-8(%rbp), %rdx

	subq	%fs:40, %rdx

	je	.L3

	call	__stack_chk_fail@PLT

.L3:
	leave
	# epilogue of function
	.cfi_def_cfa 7, 8
	ret
	# return from function
	.cfi_endproc

.LFE0:
	.size	main, .-main
	.globl	length
	.type	length, @function

length:

.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L5
.L6:
	addl	$1, -4(%rbp)
.L5:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L6
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	length, .-length
	.globl	sort
	.type	sort, @function
sort:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	%rdx, -40(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L9
.L13:
	movl	$0, -4(%rbp)
	jmp	.L10
.L12:
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %edx
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	jge	.L11
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movb	%al, -9(%rbp)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rcx
	movq	-24(%rbp), %rdx
	addq	%rcx, %rdx
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movzbl	-9(%rbp), %eax
	movb	%al, (%rdx)
.L11:
	addl	$1, -4(%rbp)
.L10:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L12
	addl	$1, -8(%rbp)
.L9:
	movl	-8(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L13
	movq	-40(%rbp), %rdx
	movl	-28(%rbp), %ecx
	movq	-24(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	reverse
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	sort, .-sort
	.globl	reverse
	.type	reverse, @function
reverse:
.LFB3:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	%rdx, -40(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L15
.L20:
	movl	-28(%rbp), %eax
	subl	-8(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -4(%rbp)
	nop
	movl	-28(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cmpl	%eax, -4(%rbp)
	jl	.L18
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	je	.L23
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movb	%al, -9(%rbp)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rcx
	movq	-24(%rbp), %rdx
	addq	%rcx, %rdx
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movzbl	-9(%rbp), %eax
	movb	%al, (%rdx)
	jmp	.L18
.L23:
	nop
.L18:
	addl	$1, -8(%rbp)
.L15:
	movl	-28(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cmpl	%eax, -8(%rbp)
	jl	.L20
	movl	$0, -8(%rbp)
	jmp	.L21
.L22:
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rcx
	movq	-40(%rbp), %rdx
	addq	%rcx, %rdx
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	addl	$1, -8(%rbp)
.L21:
	movl	-8(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L22
	nop
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	reverse, .-reverse
	.ident	"GCC: (Ubuntu 11.2.0-19ubuntu1) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
