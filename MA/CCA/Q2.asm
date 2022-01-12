%macro str32 4
        mov rax,%1
        mov rdi,%2
        mov rsi,%3
        mov rdx,%4
        syscall
%endmacro
section .data
    msg db 'The Sum : ', 10
    msglen equ $-msg
    msg1 db 'Carry Flag: 0 ',10
    msglen1 equ $-msg1
    msg2 db 'Carry Flag: 1 ',10
    msglen2 equ $-msg2
    newline db 10
    num1 db 2
    num2 db 8
section .bss
    sum resb 1
    temp resb 1
    temp1 resb 1
section .text
    global _start

_start:
    str32 1,1,msg,msglen
mov al,byte[num1]

add al,byte[num2]
jc print2
jmp k
print2:
    mov byte[temp1],al
    str32 1,1,msg2,msglen2
    mov al,byte[temp1]

k:
mov byte[sum],al
mov bp,2
up:rol al,4
        mov bl,al
        and al,0Fh
        cmp al,09
        jbe down
        add al,07h
down:
    Add al,30h
    Mov byte[temp],al
       str32 1,1,temp,1
       str32 1,1,newline,1
       mov al,bl
       dec bp
       jnz up
str32 1,1,newline,1
exit:
    mov rax, 60
    mov rdi, 0
    syscall

mov rax, 60
mov rdi, 0
syscall