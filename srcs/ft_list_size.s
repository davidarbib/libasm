section .text
	global ft_list_size

ft_list_size :
	mov rax, 0										; size = 0
	cmp rdi, 0										; if node == NULL
	je end											; 	end

loop :
	mov rdi, qword [rdi + 8]						; node = node->next		
	inc rax											; size++
	cmp rdi, 0										; if node != NULL
	jne loop										; 	 loop

end :
	ret
