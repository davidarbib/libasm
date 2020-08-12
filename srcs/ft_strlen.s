section .text
	global ft_strlen

ft_strlen:
	push r15
	mov r15, -1				;	i = -1

notnullchar:
	inc	r15					;	i++
	cmp byte [rdi + r15], 0	; 	if s[i] != 0
	jne notnullchar			;		loop
	
	mov	rax, r15			;	return (i)
	pop r15
	ret
