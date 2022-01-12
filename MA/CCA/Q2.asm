; Name : Rohit Saini Roll no: 6 Panel: A1 Erp 1032200897
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
    msg1 db 'Auxillary Flag: 0 ',10
    msglen1 equ $-msg1
    msg2 db 'Auxillary Flag: 1 ',10
    msglen2 equ $-msg2
    newline db 10
    num1 db 55h
    num2 db 05h
section .bss
    sum resb 1
    temp resb 1
    temp1 resb 1
section .text
    global _start

_start:

mov al,byte[num1]
mov bl,byte[num2]
check:
    and al,0Fh
    and bl,0Fh
    add al,bl
    cmp al,09h
    jbe print1
    jmp print2

k:
    str32 1,1,msg,msglen
    mov al,byte[num1]
    add al,byte[num2]
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
        mov al,bl
        dec bp
        jnz up
exit:
    mov rax, 60
    mov rdi, 0
    syscall
print1:
    str32 1,1,msg1,msglen1
    jmp k
print2:
    str32 1,1,msg2,msglen2
    jmp k