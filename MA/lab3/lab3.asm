%macro string 4
	mov rax,%1;
	mov rdi,%2;
	mov rsi,%3;
	mov rdx,%4;
	syscall
%endmacro
section .data
	msg db "PROTECTED MODE", 10
	msgLen equ $-msg

	msg1 db "Content of GDTR : ", 10
	msg1Len equ $-msg1
	msg2 db "Content of LDTR: ",10
	msg2Len equ $-msg2
	
	msg3 db "Content of IDTR: ",10
	msg3Len equ $-msg3
	
	msg4 db "Content of TR: ",10
	msg4Len equ $-msg4
	
	msg5 db "Content of MSW: ",10
	msg5Len equ $-msg5
	
	newline db "", 10
	cnt2 db 4
section .bss
	v_gdt resb 6
	v_msw resb 4
	value resb 4
	v_idt resb 6
	v_ldt resw 4
	v_tr resb 4
section .text

global _start
_start:
	SMSW [v_msw]
	mov eax,[v_msw]
	BT eax,0
	jc protected
	jmp exit

protected:
string 1,1,msg,msgLen
string 1,1,newline,1
string 1,1,msg5,msg5Len
mov bx,[v_msw]
call printing
SGDT [v_gdt]
string 1,1,newline,1
string 1,1,msg1,msg1Len
mov bx, word[v_gdt]
call printing
mov bx, word[v_gdt+2]
call printing
mov bx, word[v_gdt+4]
call printing

string 1,1,newline,1
string 1,1,msg4,msg4Len
str[v_tr]
mov bx,[v_tr]
call printing
string 1,1,newline,1
string 1,1,msg2,msg2Len
sldt[v_ldt]
mov bx,[v_ldt]
call printing
string 1,1,newline,1
string 1,1,msg3,msg3Len
sidt[v_idt]
mov bx,[v_idt]
call printing

mov bx,[v_idt+2]
call printing
mov bx,[v_idt+4]
call printing
string 1,1,newline,1
exit:
string 1,1,newline,1
mov rax,60
mov rdi,0
syscall

printing:
mov rdi,value
mov bp,4
up:
rol bx,04
mov cl,bl
and cl,0FH
cmp cl,09H
jbe next
add cl,07H
next:
add cl, 30H
mov [rdi], cl
inc rdi
dec bp
jnz up
string 1,1,value,4
ret
