section .data
    msg db 'Even', 10
    msglen equ $-msg
    msg1 db 'Odd', 10
    msglen1 equ $-msg1
    num1 db 30

section .bss
    num resb 1
    temp resb 1
    
section .text
    global _start

_start:

mov ax,word[num1]
mov word[num],ax
check:
    mov dx,0000
    mov bl,02H
    div bx
    cmp dx,0
    je EVEN
    jne ODD

EVEN:
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, msglen
    syscall
    jmp go
ODD:
    mov rax, 1
    mov rdi, 1
    mov rsi, msg1
    mov rdx, msglen1
    syscall
    jmp go
go:
mov ax,word[num]
mov bp,2
up:rol al,4
        mov bl,al
        and al,0Fh
        cmp al,09
        jbe down
        add al,07h
    down:Add al,30h
        Mov byte[temp],al
       mov rax,1
       mov rdi,1
       mov rsi,temp
       mov rdx,1
       syscall
       mov al,bl
       dec bp
       jnz up
mov rax, 60
mov rdi, 0
syscall