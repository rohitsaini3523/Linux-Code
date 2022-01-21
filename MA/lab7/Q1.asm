%macro str32 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .data
    newline db 10
    msg1 db "Enter Elements: "
    msglen1 equ $-msg1
    msg2 db "Elements of Array: "
    msglen2 equ $-msg2
    
section .bss
    counter resb 1
    temp resb 1
    array1 resb 15
section .text

global _start

_start:
str32 1,1,msg1,msglen1
str32 0,0,array1,15
str32 1,1,msg2,msglen2
str32 1,1,array1,15
exit: 
    mov rax,60
    mov rdi,0
    syscall
