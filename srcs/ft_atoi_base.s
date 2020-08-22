MINUS equ	45
PLUS equ	43
SPACE equ	32
FFEED equ	12
HTAB equ	9
LFEED equ	10
CRETURN equ	13
VTAB equ	11
ZERO equ	48
NINE equ	57

section .data
	present_chars: times 128 dd -1	; store char presence in base to detect 
									; duplicates and position to compute base
									; change 
section .text
	global ft_atoi_base
	extern ft_strlen

ft_atoi_base :
	cmp rdi, 0										; if s == NULL
	je end_error									; 	end error
	call check_base
	cmp rax, 0										; if check_base == 0
	je direct_end									;	before stack manip end
	;mov [present_chars], -1						; present_chars[0] = -1
	push r12
	push r13
	push r14
	push r15
	mov r12, -1										; i = -1
	mov r14, 1										; sign = 1
	mov r15, 0										; nb = 0

loop_atoi :
	inc r12											; i++
	movzx r13, byte [rdi + r12]						; char c = s[i]

	; while (c is whitespace)
	cmp r13, SPACE
	je loop_atoi
	cmp r13, FFEED
	je loop_atoi
	cmp r13, HTAB
	je loop_atoi
	cmp r13, LFEED
	je loop_atoi
	cmp r13, CRETURN
	je loop_atoi
	cmp r13, VTAB
	je loop_atoi
	; -------------------------

	cmp r13, MINUS									; if c = '-' 
	je minus_case									; 	goto minus_case
	cmp r13, PLUS									; if c == '+' 
	je plus_case									;	goto plus_case
	jne loop_compute								; goto loop_compute	

minus_case :
	mov r14, -1										; sign = -1

plus_case :
	inc r12											; i++

loop_compute :
	movzx r13, byte [rdi + r12]						; char c = s[i]
	cmp r13, 0										; if c == 0
	je end											;	end atoi
	cmp dword [present_chars + r13 * 4], -1			; if present_chars[c] == -1
	je end											;	end atoi
	imul r15, rax									; nb *= len
	add r15, [present_chars + r13 * 4]				; nb += presents_chars[c]
	inc r12											; i++
	cmp byte [rdi + r12], 0							; if (s[i] == 0)
	jne loop_compute								; 	loop compute

end :
	imul r15, r14									; nb *= sign
	mov rax, r15									; return (nb)
	pop r15
	pop r14
	pop r13
	pop r12

direct_end :
	ret

end_error:
	mov rax, 0										; return (0)
	ret												

					;-------------------------------------;
					;			base check modules	      ;
					;-------------------------------------;

check_base : 
	push r12
	push r13
	cmp byte [rsi], 0
	je base_error
	cmp byte [rsi + 1], 0
	je base_error
	mov r12, 0										; i = 0

loop_check :
	movzx r13, byte [rsi + r12]						; char c = base[i]

	;	if c == '\f' or '\t' or '\n' or ' ' or '\r' or '\v'
	;			goto base_error

	cmp r13, MINUS
	je base_error
	cmp r13, PLUS
	je base_error
	cmp r13, SPACE
	je base_error
	cmp r13, FFEED
	je base_error
	cmp r13, HTAB
	je base_error
	cmp r13, LFEED
	je base_error
	cmp r13, CRETURN
	je base_error
	cmp r13, VTAB
	je base_error
	;	---------------------------------------------------

	cmp dword [present_chars + r13 * 4], -1			; if present_chars[c] > -1
	jg	base_error									;		goto end_error
	mov dword [present_chars + r13 * 4], r12d		; present_chars[c] = i
	inc r12											; i++
	cmp byte [rsi + r12], 0 						; if base[i] != 0	
	jne loop_check									; 		loop
	mov rax, r12									; return (i)
	pop r13
	pop r12
	ret											

base_error :
	pop r13
	pop r12
	mov rax, 0									; return (0)
	ret
