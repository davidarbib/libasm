section .text
	extern __errno_location
	global ft_read

ft_read : 
	mov rax, 0						;	ret = read(...) 
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