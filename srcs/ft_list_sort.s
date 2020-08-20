section .text
	global ft_list_sort

ft_list_sort :	
	cmp rdi, 0										; if &head == NULL
	je end_error									; 	end_error
	cmp qword [rdi], 0								; if head == NULL
	je end_error									; 	end_error
	push r12
	push r13
	push r14
	push r15

outer_loop :
	mov r12, qword [rdi]							; node = head	
	mov r10, 0										; chaos = 0

inner_loop :
	cmp qword [r12 + 8], 0							; if !node->next
	je after_swap									; 	after_swap
	mov r13, rsi 									; tmp = (*cmp) 
	mov r15, qword [r12 + 8]						; arg2 = node->next->data
	mov rsi, qword [r15]							; ...
	push rdi
	mov rdi, qword [r12]							; arg1 = node->data
	push r12
	push r10
	call r13										; call tmp  (i.e. call cmp)
	pop r10
	pop r12
	pop rdi
	mov rsi, r13
	cdqe											; sign extension for cmp return
	cmp rax, 0										; if cmp return < 0
	jle after_swap									; 	no swap

swap_call :
	mov r10, 1										; chaos = 1
	push rdi
	push rsi
	mov rdi, qword [r12]							; swap(node->data, node->next->data) 
	mov r13, qword [r12 + 8]						; ...
	mov rsi, qword [r13]							; ...
	push r10
	call swap_data 									; ...
	pop r10
	mov qword [r12], rdi							; ...
	mov qword [r13], rsi							; ...
	pop rsi
	pop rdi
	
after_swap :  
	mov r12, qword [r12 + 8]						; node = node->next		
	cmp r12, 0										; if node != NULL
	jne inner_loop									; 	inner_loop

end_inner_loop :
	cmp r10, 1										; if chaos == 1
	je outer_loop									; 	outer_loop

end :
	pop r15
	pop r14
	pop r13
	pop r12
	ret

end_error :
	ret

swap_data :
	push r13
	mov r13, rsi									; tmp = node->next->data
	mov rsi, rdi									; node->next->data = node->data
	mov rdi, r13									; node_data = tmp
	pop r13
	ret
