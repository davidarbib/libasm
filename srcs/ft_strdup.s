section .text
	global ft_strdup 
	extern ft_strlen
	extern ft_strcpy
	extern malloc

ft_strdup:
	call ft_strlen
	push rdi										;	push(s)
	mov rdi, rax									;	len = ft_strlen(s)
	inc rdi											;	len++
	call malloc										;	s_out = malloc(len)
	cmp rax, 0										;
	je byebye										; [malloc protection]
	mov rdi, rax
	pop rsi											;	pop(s)
	call ft_strcpy									; 	ft_strcpy(s_out, s)
	ret

byebye :
	ret
