%macro str32 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .data
    array db 1,2,3,4,5
    msg1 db "Sum: ",10
    msg1len equ $-msg1
    counter db 5

section .bss
    sum resb 2
    num resb 2
    temp resb 2 

section .text

global _start

_start:
    mov rsi, array
    mov ax, 00h
    mov bx, 00h
    mov cx, [counter]

add:
    mov bl, byte[rsi]
    add ax, bx
    jnc skip
    inc ah
    
skip:
    inc rsi
    dec cx
    jnz add
    mov word[sum], ax
    str32 1, 1, msg1, msg1len             

    mov bp, 4
    mov ax, word[sum]
    
up:
    rol ax, 4
    mov bx, ax
    and ax, 0fh
    cmp al, 09
    jbe down
    add al, 07

down: 
    add al, 30h
    mov [temp], al
    str32 1, 1, temp, 1
    mov ax, bx
    dec bp
    jnz up

exit: 
    mov rax,60
    mov rdi,0
    syscall
