%macro rw 4
    mov rax,%1
    mov rdi,%2
    mov rsi,%3
    mov rdx,%4
    syscall
%endmacro

section .data
    arr times 64 db 0               
    msg db "Enter the elements :", 10
    msglen equ $-msg
    msg1 db "Sum of array:",10
    msg1len equ $-msg1
    cnt db 5              ;counter              
    temp1 db 0     ;to display one by one                    

section .bss
    sum resb 2
    num resb 3
    temp resb 2                     

section .text
global _start
_start:

    mov rbp, arr
    nextnum:
    rw 1,1, msg,msglen             
    rw 0,0, num,3                    
    mov rcx,0
    mov rax,0
    mov rsi,num

    up:mov cl,byte[rsi]      
    cmp cl,0aH
    je packed
    cmp cl,39h
    jbe down
    sub cl,07h

    down:sub cl,30H           
    rol al,4
    add al,cl
    inc rsi
    jmp up

    packed:mov byte[rbp],al
    inc rbp
    dec byte[cnt]
    jnz nextnum

    mov rsi,arr
    mov ax,00h
    mov bx,00h
    mov cx,5                 ;counter

    up2:mov bl,byte[rsi]
    add ax,bx                
    jnc skip
    inc ah                   ;ah=used to store carry;al=used to store the sum

    skip:inc rsi;
    dec cx
    jnz up2

    mov word[sum],ax
    rw 1,1,msg1,msg1len      ;sum of array
    call disp
    exit:mov rax,60
    mov rdi,0
    syscall

    disp:                    ;to display numbers
    mov bp,4
    mov ax,word[sum]
    up1:rol ax,4
    mov [temp],ax             ;hex to ascii conversion
    and ax,0fh
    cmp al,09
    jbe down1
    add al,07
    down1:add al,30h
    mov [temp1],al
    rw 1,1,temp1,1

    mov ax,word[temp]
    dec bp
    jnz up1
    ret
