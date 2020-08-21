section .text
	global ft_list_remove_if
	extern free

ft_list_remove_if :	
	cmp rdi, 0										; if &head == NULL
	je end_error									; 	end_error
	cmp qword [rdi], 0								; if head == NULL
	je end_error									; 	end_error
	push r12
	push r13
	push r14
	push r15

cmp_head :
	mov r12, qword [rdi]							; head = *(&head)
	push rdi
	mov rdi, qword [r12]							; arg1 = head->data

	push rsi
	push rdx
	push rcx
	call rdx										; call tmp  (i.e. call cmp)
	pop rcx
	pop rdx
	pop rsi
	pop rdi

	cmp rax, 0
	jne lst_fwd

	mov r13, qword [r12 + 8]						; tmp = head->next

	push rdi
	mov rdi, qword [r12]
	push rsi
	push rdx
	push rcx
	call rcx										; free_fct(head->data) 
	mov rdi, r12
	call free										; free(head)
	pop rcx
	pop rdx
	pop rsi
	pop rdi
	
	mov qword [rdi], r13							; head = tmp
	cmp r13, 0										; if head == NULL
	je end											; 	end
	jmp cmp_head									; loop cmp_head

lst_fwd :
	lea r14, [r12 + 8]								; ante_next = [head/node]->next
	mov r12, qword [r14]							; node = ante_next
	cmp r12, 0										; if node == NULL
	je end											; 	end

cmp_node :
	push rdi
	mov rdi, qword [r12]							; arg1 = node->data
	push rsi
	push rdx
	push rcx
	call rdx										; call tmp  (i.e. call cmp)
	pop rcx
	pop rdx
	pop rsi
	pop rdi

	cmp rax, 0
	jne lst_fwd
	mov r13, qword [r12 + 8]						; tmp = node->next

	push rdi
	mov rdi, qword [r12]
	push rsi
	push rdx
	push rcx
	call rcx										; free_fct(head->data) 
	mov rdi, r12
	call free										; free(head)
	pop rcx
	pop rdx
	pop rsi
	pop rdi
	
	mov r12, r13									; node = tmp
	mov qword [r14], r13							; ante_next = tmp
	cmp r13, 0
	je end
	jmp cmp_node

end :
	pop r15
	pop r14
	pop r13
	pop r12

end_error :
	ret
