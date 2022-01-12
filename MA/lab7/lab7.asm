; JBE : jump if below/equal
;Jg: jump if Greater
;CMP: used to compare 2 provided byte/word
;XCHG: used to exchange the data from two location
%macro str32 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .data
    array db 0Ah,25h,06h,13h,00h 
    newline db 10
    msg db "Ascending Order : "
    msglen equ $-msg
    msg1 db "Descending Order : "
    msglen1 equ $-msg1
section .bss
    counter resb 1
    counter1 resb 1
    temp resb 1
    array1 resb 15
    array2 resb 15
section .text

global _start

_start:
    mov byte[counter],5
    L1:
        mov byte[counter1],4
        mov rsi,array 

asc:
    mov al, byte[rsi]
    cmp al,byte[rsi+1]
    jbe  incre
    xchg al,byte[rsi+1]
    mov byte[rsi],al
incre:
    inc rsi
    dec byte[counter1]
    jnz asc
    dec byte[counter]
    jnz L1

mov rdi,array
mov rsi,array1
mov dl,10

    L2:
    mov bp, 2
    mov al,[rdi] 
        
    up:
        rol al, 4
        mov bl, al
        and al, 0fh
        cmp al, 09h
        jbe down
        add al, 07h

    down: 
        add al, 30h
        mov byte[rsi], al
        mov al, bl
        inc rsi
        dec bp
        jnz up
        mov byte[rsi]," "
        inc rsi
        inc rdi
        dec dl
        jnz L2
str32 1,1,msg,msglen
str32 1,1,array1,15
; Descending
str32 1,1,newline,1
 L11:
        mov byte[counter1],4
        mov rsi,array 

asc1:
    mov al, byte[rsi]
    cmp al,byte[rsi+1]
    jg  incre1
    xchg al,byte[rsi+1]
    mov byte[rsi],al
incre1:
    inc rsi
    dec byte[counter1]
    jnz asc1
    dec byte[counter]
    jnz L11

mov rdi,array
mov rsi,array2
mov dl,10

    L21:
    mov bp, 2
    mov al,[rdi] 
        
    up1:
        rol al, 4
        mov bl, al
        and al, 0fh
        cmp al, 09h
        jbe down1
        add al, 07h

    down1: 
        add al, 30h
        mov byte[rsi], al
        mov al, bl
        inc rsi
        dec bp
        jnz up1
        mov byte[rsi]," "
        inc rsi
        inc rdi
        dec dl
        jnz L21
str32 1,1,msg1,msglen1
str32 1,1,array2,15
str32 1,1,newline,1
exit: 
    mov rax,60
    mov rdi,0
    syscall
