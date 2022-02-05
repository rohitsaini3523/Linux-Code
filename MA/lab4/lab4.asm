%macro str32 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro
section .data
	msg1 db "Error",10
	msgl1 equ $-msg1
	msg2 db "File copy successfully",10
	msgl2 equ $-msg2
Section .bss
	fname1 resb 15
	fd1 resq 1
	fname2 resb 15
	fd2 resq 1
	buff resb 512
	bufflen resq 1
section .text
global _start 
_start:
	pop r8
	cmp r8,3
	jne err
	pop r8
	pop r8
	mov rsi,fname1
	above:
	mov al,[r8]
	cmp al,00
	je next
	mov [rsi],al
	inc r8
	inc rsi
	jmp above 
	next:
	pop r8
	mov rsi,fname2
	above2:
	mov al,[r8]
	cmp al,00
	je next2
	mov [rsi],al
	inc r8
	inc rsi
	jmp above2
	next2:
	str32 2,fname1,000000q,0777q ;open first file 
	mov [fd1],rax
	str32 0,[fd1],buff,512
	mov [bufflen],rax
	str32 85,fname2,0777q,0 ;create second file
	str32 2,fname2,2,0777q ;open second file
	mov [fd2],rax
	str32 1,[fd2],buff,[bufflen] ;write in the second file
	str32 3,[fd2],0,0 ;close second file 
	str32 3,[fd1],0,0 ;close first file 
	str32 1,1,msg2,msgl2
	jmp end
	err:
	str32 1,1,msg1,msgl1
	end : 
	str32 60,0,0,0