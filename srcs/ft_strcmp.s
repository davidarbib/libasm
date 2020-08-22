section .text
	global ft_strcmp

ft_strcmp:
	cmp rdi, 0										; if dest == NULL
	je end_error									; 	end error
	cmp rsi, 0										; if src == NULL
	je end_error									; 	end error
	push r11
	push r12
	push r15
	mov r15, 0										;	i = 0

loop:
	mov r11b, byte [rsi + r15]						;	tmp1 = s1[i]
	mov r12b, byte [rdi + r15]						;	tmp2 = s2[i]
	cmp r11b, 0										; 	if tmp1 == 0
	je	end											;		goto end	 
	cmp r12b, 0										; 	if tmp2 == 0
	je	end											;		goto end
	inc r15											;	i++
	cmp r11b, r12b									;	if tmp1 == tmp2
	je  loop
end:
	movzx rax, r12b									;
	movzx rbx, r11b									;
	sub rax, rbx									;	return (tmp1 - tmp2)
	pop r15
	pop r12
	pop r11
	ret												;

end_error:
	mov rax, 0										; return (NULL)
	ret												
