# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_atoi_base.s                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darbib <darbib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 01:07:16 by darbib            #+#    #+#              #
#    Updated: 2020/08/13 16:40:14 by darbib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINUS equ	55
PLUS equ	53
SPACE equ	32
FFEED equ	12
HTAB equ	9
LFEED equ	10
CRETURN equ	13
VTAB equ	11

section .data
	present_chars times 127 db 0	; store char presence to detect duplicates

section .text
	global ft_atoi_base

ft_atoi_base :
	call check_base								

check_base : 
	cmp [rsi], 0
	je end_error
	cmp [rsi + 1], 0
	je end_error
	push r12
	push r13
	mov r12, 0									; i = 0

loop_check :
	movzx r13, [rsi + r12]						; char c = base[i]

	;	if c == '\f' or '\t' or '\n' or ' ' or '\r' or '\v'
	;			goto end_error
	cmp r13, MINUS
	je end_error
	cmp r13, PLUS
	je end_error
	cmp r13, SPACE
	je end_error
	cmp r13, FFEED
	je end_error
	cmp r13, HTAB
	je end_error
	cmp r13, LFEED
	je end_error
	cmp r13, CRETURN
	je end_error
	cmp r13, VTAB
	je end_error
	;	---------------------------------------------------

	cmp [present_chars + r13], 1				; if present_chars[c] == 1
	je end_error								;		goto end_error
	mov [present_chars + r13], 1				; present_chars[c] = 1
	inc r12										; i++
	cmp [rsi + r12], 0 							; if base[i] != 0	
	jne loop_check								; 		loop
	pop r13
	pop r12
	ret											; return

end_error :
	mov rax, 0									; return (0)
	pop r13
	pop r12
	ret
