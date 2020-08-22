section .text
	global ft_strdup 
	extern ft_strlen
	extern ft_strcpy
	extern malloc

ft_strdup:
	cmp rdi, 0										; if dest == NULL
	je end_error									; 	end error
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

end_error:
	mov rax, 0										; return (NULL)
	ret												
