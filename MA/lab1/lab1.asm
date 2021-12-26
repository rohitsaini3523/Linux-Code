%macro str32 4
        mov rax,%1
        mov rdi,%2
        mov rsi,%3
        mov rdx,%4
        syscall
%endmacro

section .data        
        msg db "Enter String: "
        msg_len equ $-msg    
        msg1 db "String :"
        msg1_len equ $-msg1
        menu db "",10,"**String Operation***",10,"1.Length",10,"2.Reversed",10,"3.Palindrome",10,"4.Exit",10,"Choice:"
        menu_len equ $-menu
        msg2 db "Length is:"
        msg2_len equ $-msg2
        msg3 db "Reversed:"
        msg3_len equ $-msg3
        msg4 db "Palindrome"
        msg4_len equ $-msg4
        msg5 db "Not Palindrome"
        msg5_len equ $-msg5
        new db 10
section .bss
        str1 resb 50
        str2 resb 50
        count resb 2
        length resb 2
        temp resb 2
        choice resb 2
section .text

global _start

_start:
	str32 1,1,msg,msg_len
        str32 0,0,str1,100 
        dec rax
        mov byte[length],al
        mov byte[count],al
        str32 1,1,msg1,msg1_len
        str32 1,1,str1,100
        
	again:
        str32 1,1,menu,menu_len
        str32 0,0,choice,2
        cmp byte[choice],'1'
        JE A1
        cmp byte[choice],'2'
        JE A2
        cmp byte[choice],'3'
        JE A3
        cmp byte[choice],'4'
        JE A4
        
        A1:  
        str32 1,1,msg2,msg2_len
        mov al,[length]
        mov bp,2
        up:rol al,4
              mov bl,al
              and al,0Fh
              cmp al,09
              jbe down
             add al,07h
            down:Add al, 30h
              Mov byte[temp],al 
              str32 1,1,temp,1
              mov al,bl
             dec bp
             jnz up
        jmp again
             
        A2:
        mov rsi,str1
        mov rdi,str2
        
        mov rbx,00
        mov bl,byte[count]
        add rsi,rbx
        dec rsi
        
    	Next:
        mov al,[rsi]
        mov [rdi],al
        
        dec rsi
        inc rdi
        dec bl
        jnz Next
        
        str32 1,1,msg3,msg3_len
        str32 1,1,str2,50
	jmp again
A3:    
	  mov rsi,str1
	  mov rdi,str1
	  rep1:
	   inc rdi
	   dec byte[count]
	   jnz rep1
	   dec rdi
	  up3:
	   mov al,[rsi]
	   cmp al,[rdi]
	   jne npal 
	   inc rsi
	   dec rdi
	   dec byte[length]
	   jnz up3

	   str32 1,1,msg4,msg4_len
	   str32 1,1,new,1
	   jmp again

	   npal:
	    str32 1,1,msg5,msg5_len
	    str32 1,1,new,1
	    jmp again

A4: 
mov rax,60
mov rdi,0
syscall

        
        
    
        

