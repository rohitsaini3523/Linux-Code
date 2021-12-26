%macro str12 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .data        
        msg db "Enter Number: "
        msg_len equ $-msg    
        msg1 db "Factorial :"
        msg1_len equ $-msg1
        newline db 10
section .bss
        Num1 resb 1
        temp resb 1
        binary resb 1
        
section .text
global _start
_start:
	str12 1,1,msg,msg_len
	str12 0,0,Num1,1
	mov eax,[Num1]
	sub eax,0x30
	mov byte[binary],al
	str12 1,1,msg1,msg1_len
	mov eax,1

fact:
	mul word[binary]
	dec word[binary]
	cmp word[binary],1
	jne fact
	
mov word[binary],ax
mov bp,4
mov ax,word[binary]

up : 
	rol ax,4
	mov bx,ax
	and al,0Fh
	cmp al,09h
	jbe down
	add al,07h

down : 
	add al,30h
	mov byte[temp],al
  	str12 1,1,temp,1
	mov ax,bx
	dec bp
	jnz up
	str12 1,1,newline,1
	mov rax,60
	mov rdi,0
	syscall
