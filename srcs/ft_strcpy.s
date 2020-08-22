section .text
	global ft_strcpy 

ft_strcpy:
	cmp rdi, 0										; if dest == NULL
	je end_error									; 	end error
	cmp rsi, 0										; if src == NULL
	je end_error									; 	end error
	push r12
	push r15
	mov	rax, rdi 
	mov r15, 0										;	i = 0

loop:
	mov r12b, byte [rsi + r15]						;	tmp = src[i]
	mov [rax+r15], r12b								; 	dest[i] = tmp
	inc r15											;	i++
	cmp r12b, 0										; 	if tmp != 0
	jne	loop										;		loop	 
	pop r15
	pop r12
	ret

end_error:
	mov rax, 0										; return (NULL)
	ret												
