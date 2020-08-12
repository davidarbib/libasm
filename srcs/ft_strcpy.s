section .text
	global ft_strcpy 

ft_strcpy:
	mov	rax, rdi 
	mov r15, 0										;	i = 0

loop:
	mov r12b, byte [rsi + r15]						;	tmp = src[i]
	mov [rax+r15], r12b								; 	dest[i] = tmp
	inc r15											;	i++
	cmp r12b, 0										; 	if tmp != 0
	jne	loop										;		loop	 
	ret												;
