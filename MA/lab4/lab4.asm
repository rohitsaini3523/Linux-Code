section .data
msg1 db "Error",10
msgl1 equ $-msg1
msg2 db "File copy successfully",10
msgl2 equ $-msg2

%macro operate 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

Section .bss
   fname1 resb 15
	fd1 resq 1
	fname2 resb 15
	fd2 resq 1
	buff resb 512
	bufflen resq 1
section .txt
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
		jmp  above2

next2:
	operate   2,fname1,000000q,0777q	     ;open first file
	mov [fd1],rax

	operate  0,  [fd1],  buff,  512	;read first file
	mov [bufflen],rax

     operate  85, fname2, 0777q, 0	;create second file
     operate 2, fname2, 2, 0777q	;open second file
	mov [fd2],rax
	operate 1, [fd2], buff, [bufflen]  ;write in the second file
    	
	operate 3,[fd2],0,0			;close second file
	operate 3,[fd1],0,0			;close  first file

	operate 1,1,msg2,msgl2
	jmp end
	err:
	operate 1,1,msg1,msgl1
	end : operate 60,0,0,0

	

