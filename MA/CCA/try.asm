%macro str32 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .data
    array db 0Ah,25h,06h,13h,00h 
section .bss
section .text

global _start

_start:
    
L1:
mov rsi,array
mov dl,5

    L2:
    mov bp, 2
    mov al,[rsi] 
        
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
        str32 1
        inc rsi
        dec bp
        jnz up
        mov byte[rsi],0Ah
        inc rsi
        dec dl
        jnz L2
    
    mov rax,60
    mov rdi,0
    syscall