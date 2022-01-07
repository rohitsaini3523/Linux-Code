%macro write 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro
section .bss
input resb 1
section .data
num db 8
result db 0
msg1 db "ENTER NUMBER:",10
msglen1 equ $-msg1
msg2 db 10d,"FACTORIAL:",10
msglen2 equ $-msg2
section .text
global _start
_start:
write 1,1,msg1,msglen1
write 0,0,input,1
write 1,1,msg2,msglen2
mov rsi, input
call ascii2hex
mov [num], rax
mov ax, 1
mov bx, [num]
call factorial
mov esi,result
mov cl,8
call hex2ascii
write 1,1,result, 4
mov rax,60
mov rdi,0
syscall
; returns the factorial in rax
factorial:
cmp bx, 1
je stop
mul bx
dec bx
jmp factorial
stop:
ret
hex2ascii:
rol ax, 4
mov dx, ax
and ax, 0fh
cmp al, 09
jbe skip
add al, 07h
skip:
add al, 30h
mov [esi], al
inc esi
mov ax,dx
dec cl
jnz hex2ascii
ret
; converts an ascii byte in rsi to its numeric value in rax
ascii2hex:
mov al, byte[rsi]
sub al, 30h
ret
