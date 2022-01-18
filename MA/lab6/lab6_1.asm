%macro str32 4
        mov rax,%1
        mov rdi,%2
        mov rsi,%3
        mov rdx,%4
        syscall
%endmacro

section .data
    password db "Rohits"
    msg db "Enter the Password(len-6): "
    msglen equ $-msg
    msg2 db "Password Correct!"
    msg2len equ $-msg2
    msg3 db "Password Not Correct!"
    msg3len equ $-msg3
    new db 10
section .bss
    string resb 15

section .text
global _start
_start:

    str32 1,1,msg,msglen
    str32 0,0,string,15
    mov cl,6
    mov rsi, string
    mov rdi, password
check:    
    mov al,byte[rsi]
    cmp al,byte[rdi]
    jne wrong
    inc rsi
    inc rdi
    dec cl
    jnz check
    
str32 1,1,msg2,msg2len
str32 1,1,new,1
jmp exit

wrong:
    str32 1,1,msg3,msg3len
    str32 1,1,new,1
exit:
    mov rax,60
    mov rdi,0
    syscall

    