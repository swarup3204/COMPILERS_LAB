	.file	"assign1.c" 
	# specifies the name of the source file associated with the object file.
	.text  
	# defines current section as text.
	.section	.rodata 
	# The .section directive makes .rodata the current section. If section does not exist, a new section with the specified name and attributes is created. ro means read only
	.align 8 
	# this directive tells next data will be aligned by %8  bytes
.LC0: 												# label of f-string-1st printf
	# LC means local constant,i.e,it is label of a local constant with id 0
	.string	"Enter the string (all lowrer case): " 
	# places character in string into object module at current location and terminates string with null byte
.LC1:
	.string	"%s"									# label of f-string scanf
.LC2:
	.string	"Length of the string: %d\n"			# label of f-string 2nd printf
	.align 8
.LC3:
	.string	"The string in descending order: %s\n"	# label of f-string 3rd printf
	.text
	.globl	main
	 # .globl directive tells the assembler that the symbol main is a global symbol.
	.type	main, @function
	 # defines type of symbol main,i.e,function

main:  # start of main function

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
	# load address of input string(address of str[0]) to raxx	
	movq	%rax, %rsi
	# move address of input string to rsi(2nd argument to function scanf)
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
	# load address of sdtring "Length of the string: %d\n" to rax
	movq	%rax, %rdi
	# move address of string "Length of the string: %d\n" to rdi(1st argument to function printf)
	movl	$0, %eax
	# set value of eax to 0
	call	printf@PLT
	# call printf function defined in header file
	leaq	-32(%rbp), %rdx
	# load address of empty string dest to rdx(3rd argument to function sort)
	movl	-68(%rbp), %ecx
	# move value of length of string stored in stack frame 68 bytes before address pointed to by base pointer to ecx
	leaq	-64(%rbp), %rax
	# load address of input string(address of str[0]) to rax
	movl	%ecx, %esi
	# move value of length of string stored in ecx to esi(2nd argument to function sort)
	movq	%rax, %rdi
	# move address of input string to rdi(1st argument to function sort)
	call	sort
	# calls sort function defined in source file to sort string alphabetically
	leaq	-32(%rbp), %rax
	# load address of dest string(reverse sorted string) to rax
	movq	%rax, %rsi
	# move address of reverse sorted string ,dest to rsi(2nd argument to function printf)
	leaq	.LC3(%rip), %rax
	# load address of string "The string in descending order: %s\n" to rax
	movq	%rax, %rdi
	# move address of string "The string in descending order: %s\n" to rdi(1st argument to function printf)
	movl	$0, %eax
	# set value of eax to 0
	call	printf@PLT
	# call printf function defined in header file
	movl	$0, %eax
	# set value of eax to 0
	movq	-8(%rbp), %rdx
	# move value stored in 8 bytes before address pointed to by rbp to rdx
	subq	%fs:40, %rdx
	# fs is segment register
	je	.L3
	# jump to .	L3
	call	__stack_chk_fail@PLT

.L3:						
	leave
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
	# move stack pointer to base pointer
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	# move address of input string to stack frame 24 bytes before address pointed to by base pointer
	movl	$0, -4(%rbp)
	# set value of 4 bytes before address pointed to by base pointer to 0 for i.the loop iterator
	jmp	.L5
	# jump to .L5
.L6:
	addl	$1, -4(%rbp)
	# increment value of 4 bytes before address pointed to by base pointer by 1,i.e,incrementing i by 1
.L5:
	movl	-4(%rbp), %eax
	# move value of 4 bytes before address pointed to by base pointer to eax,i.e,which stores length of string
	movslq	%eax, %rdx
	# move value of eax to rdx,i.e,which stores length of string in 64 bit format
	movq	-24(%rbp), %rax
	# move address of input string to rax
	addq	%rdx, %rax
	# add value of rdx to rax,i.e,which stores address of current character of string
	movzbl	(%rax), %eax
	# move value of current character of string to eax
	testb	%al, %al
	# test if value of byte stored in address pointed to by rax is 0
	jne	.L6
	# if value of byte stored in address pointed to by rax is not 0,then jump to .L6,i.e,not reached end of string so increment i
	movl	-4(%rbp), %eax
	# move value of 4 bytes before address pointed to by base pointer to eax,i.e,which stores length of string
	popq	%rbp
	# pop base pointer from stack
	.cfi_def_cfa 7, 8
	ret
	# return
	.cfi_endproc
.LFE1:
	# epilogue of function
	.size	length, .-length
	.globl	sort
	.type	sort, @function
sort:
.LFB2:
	.cfi_startproc
	endbr64
	# prologue of function
	pushq	%rbp
	# push base pointer to stack frame
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	# move stack pointer to base pointer
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	# decrement stack pointer by 48 bytes to make space for variables
	movq	%rdi, -24(%rbp)
	# move address of str to stack frame 24 bytes before address pointed to by base pointer
	movl	%esi, -28(%rbp)
	# move value of esi  which is length of string (4 bytes) to stack frame 28 bytes before address pointed to by base pointer
	movq	%rdx, -40(%rbp)
	# move value of rdx,the address of destination string dest to stack frame 40 bytes before address pointed to by base pointer
	movl	$0, -8(%rbp)								# i <--- 0
	# set value of 8 bytes before address pointed to by base pointer to 0 for i,the loop iterator
	jmp	.L9
	# jump to .L9
.L13:
	movl	$0, -4(%rbp)
	# set value of 4 bytes before address pointed to by base pointer to 0 i.e,initialise j,the inner loop iterator
	jmp	.L10
	# jump to .L10
.L12:
	movl	-8(%rbp), %eax					# eax <--- i
	# move long value at 8 bytes before address pointed to by base pointer to eax,i.e,the value of i
	movslq	%eax, %rdx						# rdx <--- eax
	# move value of eax to rdx,i.e,the value of i is stored in 64 bit format
	movq	-24(%rbp), %rax					# rax <--- M[rbp-24]
	# move address of str to rax
	addq	%rdx, %rax						# rdx <--- rdx + rax
	# add value of rdx to rax,i.e,the address of str[i] is stored in rax
	movzbl	(%rax), %edx					# edx <--- str[i]
	# move value of str[i] to edx
	movl	-4(%rbp), %eax					# eax <--- j
	# move value of 4 bytes before address pointed to by base pointer to eax,i.e,the value of j,the inner loop iterator
	movslq	%eax, %rcx						# rcx <--- eax
	# move value of eax to rcx,i.e,the value of j is stored in 64 bit format
	movq	-24(%rbp), %rax					# rax <--- M[rbp-24]
	# move address of str to rax
	addq	%rcx, %rax						# rcx <--- rcx + rax
	# add value of rcx to rax,i.e,the address of str[j] is stored in rax
	movzbl	(%rax), %eax					# eax <--- str[j]
	# move value of str[j] to eax
	cmpb	%al, %dl						# compare str[i] and str[j]
	# compare value of byte stored in address pointed to by rax with value of byte stored in address pointed to by rdx,i.e,str[i] and str[j]
	jge	.L11								
	# if str[i]>str[j] do nothing and jump to L11
	movl	-8(%rbp), %eax				   # eax <--- i
	# move value of 8 bytes before address pointed to by base pointer to eax,i.e,the value of i
	movslq	%eax, %rdx					   # rdx <--- eax
	# move 	value of eax to rdx,i.e,the value of i is stored in 64 bit format
	movq	-24(%rbp), %rax				   # rax <--- M[rbp-24]
	# move address of str to rax
	addq	%rdx, %rax					   # rax <--- rdx + rax
	# add value of rdx to rax,i.e,the address of str[i] is stored in rdx
	movzbl	(%rax), %eax
	# move value of str[i] to eax
	movb	%al, -9(%rbp)					# temp <--- str[i]

	movl	-4(%rbp), %eax					# eax <--- j
	
	movslq	%eax, %rdx						# rdx <--- j

	movq	-24(%rbp), %rax					# rax <--- str

	addq	%rdx, %rax						# rax <--- j

	movl	-8(%rbp), %edx					# edx <--- i

	movslq	%edx, %rcx						# rcx <--- i

	movq	-24(%rbp), %rdx					# rdx <--- str
	
	addq	%rcx, %rdx						# rdx <--- str+i

	movzbl	(%rax), %eax					# eax <--- str[j]

	movb	%al, (%rdx)						# str[i] <--- str[j]

	movl	-4(%rbp), %eax					# eax <--- j

	movslq	%eax, %rdx						# rdx <--- j

	movq	-24(%rbp), %rax					# rax <--- str

	addq	%rax, %rdx						# rdx <--- str+j

	movzbl	-9(%rbp), %eax					# eax <--- temp

	movb	%al, (%rdx)						# str[j] <--- temp

.L11:										# j increment label
	addl	$1, -4(%rbp)					# j <--- j + 1


.L10:										# loop label
	movl	-4(%rbp), %eax					# eax <--- j
	# move value of 4 bytes before address pointed to by base pointer to eax,i.e,j,the inner loop iterator
	cmpl	-28(%rbp), %eax					# compare j with n
	# compare length of string 28 bytes before address pointed to by base pointer to value of j,the inner loop iterator
	jl	.L12							    # if j<n jump to .L12
	#jump to .L12 if j < len of string	
	addl	$1, -8(%rbp)					# i <--- i + 1
	# add 1 to value of 8 bytes before address pointed to by base pointer,i.e,increment j by 1

.L9:	
	movl	-8(%rbp), %eax					# eax <--- i
	# move value of a double word 8 bytes before address pointed to by base pointer to eax,the variable i which is the loop iterator
	cmpl	-28(%rbp), %eax					# compare i with n
	# comparing two double words ,i and the length of string ,length stored 28 bytes before address pointed to by base pointer
	jl	.L13								# if i<n jump to .L13
	# jump  to L13 if i less than length of string 
	movq	-40(%rbp), %rdx					# rdx <--- dest
	# move the address of destination string dest to rdx(3rd argument of reverse function)
	movl	-28(%rbp), %ecx					# ecx <--- len
	# move the length of string (4 bytes) to ecx
	movq	-24(%rbp), %rax					# rax <--- str
	# move the address of string str to rax
	movl	%ecx, %esi						# esi <--- len
	# move the length of string to esi(4 bytes) (2nd argument of reverse function) 
	movq	%rax, %rdi						# rdi <--- str
	# move the address of string str to rdi(1st argument of reverse function)
	call	reverse
	# call reverse function to reverse the string
	nop
	# no operation
	leave
	# leave function
	.cfi_def_cfa 7, 8
	ret
	# return from function
	.cfi_endproc
.LFE2:
	# epilogue of sort function
	.size	sort, .-sort
	.globl	reverse
	.type	reverse, @function
reverse:
.LFB3:
	.cfi_startproc
	endbr64
	# prologue of function reverse
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)			  # rdi <--- str		
	# move the address of string str in rdi to 24 bytes before address pointed to by base pointer
	movl	%esi, -28(%rbp)			  # esi <--- len
	# move the length of string in esi(4 bytes) to 28 bytes before address pointed to by base pointer
	movq	%rdx, -40(%rbp)			  # rdx <--- dest
	# move the address of destination string in rdx to 40 bytes before address pointed to by base pointer
	movl	$0, -8(%rbp)			  # i <--- 0
	# move 0(4 bytes) to 8 bytes before address pointed to by base pointer,i.e,initialize i to 0 
	jmp	.L15
	# jump to L15
.L20:
	movl	-28(%rbp), %eax 				# eax <--- len
	# move value of len(double word)to eax
	subl	-8(%rbp), %eax 					# eax <--- len-i
	# subtract the value of i from length of string(4 bytes),i.e,j=len-i
	subl	$1, %eax					    # eax <--- eax-1
	# subtract 1 (of size double word) from eax
	movl	%eax, -4(%rbp)					# j <--- eax
	# move the value in eax=len-i-1 to j
	nop
	# no operation
	movl	-28(%rbp), %eax					# eax <--- len
	# move value of len(double word) to eax
	movl	%eax, %edx   					# edx <--- len
	# move value of eax to edx

	# algorithm for dividing number by 2(any number whether positive,negative or zero)

	shrl	$31, %edx						# edx <--- edx/(2^31)
	# shift right edx by 31 bits
	addl	%edx, %eax						# eax <--- eax+edx
	# add edx to eax
	sarl	%eax
	# shift arithmetically right the value in eax and fill msb with original value 
	cmpl	%eax, -4(%rbp)					
	# compare  len/2 and j
	jl	.L18								# if j < len/2 exit inner loop
	# jump to .L18
	# move ahead if j>=len/2
	movl	-8(%rbp), %eax					# eax <--- i
	# move the value of i to eax
	cmpl	-4(%rbp), %eax
	# compare i and j
	je	.L23								# i == j
	# if i==j jump to .L23
	movl	-8(%rbp), %eax					# eax <--- i
	# move the value of i to eax
	movslq	%eax, %rdx						# rdx <--- i
	# move the value of i to rdx
	movq	-24(%rbp), %rax					# rax <--- str

	addq	%rdx, %rax						# rax <--- str+i

	movzbl	(%rax), %eax					# eax <--- str[i]

	movb	%al, -9(%rbp)					# temp <--- str[i]

	movl	-4(%rbp), %eax					# eax <--- j

	movslq	%eax, %rdx						# rdx <--- j 
	# move the value of j to rdx
	movq	-24(%rbp), %rax					# rax <--- str
	# move the address of string str to rax
	addq	%rdx, %rax					    # rax <--- str+j
	# add rdx to rax
	movl	-8(%rbp), %edx		            # edx <--- i
	# move the value of i to edx
	movslq	%edx, %rcx						# rcx <--- i
	# move the value of i to rcx
	movq	-24(%rbp), %rdx					# rdx <--- str
	# move the address of string str to rdx
	addq	%rcx, %rdx						# rdx <--- str+i
	# add rcx to rdx
	movzbl	(%rax), %eax       				# eax <--- str[i]
	# move the value of M[rax] to eax
	movb	%al, (%rdx)						# str[i] <--- str[j]

	movl	-4(%rbp), %eax					# eax <--- j
	# move the value of j to eax
	movslq	%eax, %rdx						# rdx <--- j
	# move the value of j to rdx
	movq	-24(%rbp), %rax					# rax <--- str
	# move the address of string str to rax
	addq	%rax, %rdx						# rdx <--- str+j
	# add rdx to rax
	movzbl	-9(%rbp), %eax					# eax <--- temp
	# move the value of temp to eax
	movb	%al, (%rdx)						# str[j] <--- temp
	# move temp to M[rdx]
	jmp	.L18
	# jump to .L18
.L23:
	nop
	# no operation
.L18:										# loop increment label
	addl	$1, -8(%rbp)   					# i <--- i+1
	# add 1 to value at address 8 bytes before rbp,i.e,i 
.L15:
	movl	-28(%rbp), %eax
	# move the length of string(4 bytes) to eax
	movl	%eax, %edx
	# move the length of string in eax to edx(4 bytes)
	shrl	$31, %edx
	# divide length of string by 2
	addl	%edx, %eax						# eax <--- eax + edx
	# add edx to eax
	sarl	%eax
	cmpl	%eax, -8(%rbp)
	# compare half the length of string to value of i,the loop iterator
	jl	.L20
	# jump to L20 if i < half the length of string
	movl	$0, -8(%rbp)
	# move 0(4 bytes) to 8 bytes before address pointed to by base pointer,i.e,initialize i to 0
	jmp	.L21
	# jump to L21 
.L22:
	movl	-8(%rbp), %eax				# eax <--- M[rbp-8],eax <--i
	# move value of i to eax
	movslq	%eax, %rdx					# rdx <--- eax
	movq	-24(%rbp), %rax				# rax <--- M[rbp-24]
	# move the address of string str to rax
	addq	%rdx, %rax					# rax <--- rax+rdx
	# add rdx to rax
	movl	-8(%rbp), %edx				# edx <--- M[rbp-8],edx <--i
	# move the value of i to edx
	movslq	%edx, %rcx					# rcx <--- edx
	# move the value of i to rcx
	movq	-40(%rbp), %rdx				# rdx <--- M[rbp-40]
	# move the address of string dest to rdx
	addq	%rcx, %rdx					# rdx <--- rdx+rcx
	# add rcx to rdx
	movzbl	(%rax), %eax				# eax <--- M[rax],eax <--str[i]
	# move value at location in rax to eax
	movb	%al, (%rdx)					# M[rdx] <--- al
	# move value at al to dest[i]
	addl	$1, -8(%rbp)				# i <--- i+1
	# add 1 to i
.L21:
	movl	-8(%rbp), %eax
	# move value of i to eax
	cmpl	-28(%rbp), %eax
	# compare i and length of string(len)
	jl	.L22
	# if i<len jump to .L22
	nop
	# no operation
	nop
	# no operation
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	# epilogue of function
	.size	reverse, .-reverse
	.ident	"GCC: (Ubuntu 11.2.0-19ubuntu1) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
	# numeric labels
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
