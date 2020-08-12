section .text
	extern __errno_location
	global ft_write

ft_write : 
	mov rax, 1						;	ret = read(...) 
	syscall							;	
	cmp rax, 0						;	if ret < 0
	jl my_error						;		goto my_error
	ret

my_error :
	neg rax							;	
	push r12						;
	mov r12, rax					;	r12 : -ret
	call __errno_location
	mov [rax], r12					;	*errno = -ret
	pop r12
	mov rax, -1
	ret
