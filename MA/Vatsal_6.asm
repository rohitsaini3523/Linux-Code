%macro RW 4
	mov rax, %1
	mov rdi, %2
	mov rsi, %3
	mov rdx, %4
	syscall
%endmacro

section .data
	st db "Enter the number : "
	lst equ $-st
	m1 db "Factorial of the Number is : ",10
	l1 equ $-m1

section .bss
	num1 resw 1
	fact resb 2
	rtemp resb 2
	dtemp resb 1

section .text
global _start
_start:

	RW 1,1,st,lst
	RW 0,0,num1,1
	sub word[num1], 30H

	mov ax, word[num1]
	cmp ax, 1
	je exit 

	rec:
	dec word[num1]
	mul word[num1]
	cmp word[num1], 1
	jne rec

	mov word[fact], ax
	RW 1,1,m1,l1

	mov bp, 4
	mov ax, word[fact]

	up:
	rol ax, 4
	mov word[rtemp], ax
	and al, 0FH

	cmp al, 09H
	jbe down
	add al, 07H

	down:
	add al,30H

	mov byte[dtemp], al
	RW 1,1,dtemp,1
	mov ax,word[rtemp]
	dec bp
	jnz up
	jmp end

	exit: 
	RW 1,1,m1,l1
	add word[num1], 30H	
	RW 1,1,num1,2

	end:
	RW 60,0,0,0
