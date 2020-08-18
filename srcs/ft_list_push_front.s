section .text
	global ft_list_push_front
	extern malloc

ft_list_push_front :
	push r10
	push r11
	push r12
	push rsi
	push rdi
	mov rdi, 16											;
	call malloc											; malloc(16)
	cmp rax, 0											; if 0x0
	je error_malloc										; 	error
	pop rdi
	mov r12, [rdi]										; new->next = head 
	mov [rax + 8], r12									; ... 
	pop rsi
	mov [rax], rsi										; new->data = data	
	mov [rdi], rax										; head = new
	pop r12
	pop r11	
	pop r10	
	ret

error_malloc :
	pop rdi	
	pop rsi	
	pop r12
	pop r11	
	pop r10	
	ret
