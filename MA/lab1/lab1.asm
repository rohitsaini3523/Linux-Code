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
        msg2 db "Length is:",10
        msg2_len equ $-msg2
        msg3 db "Reversed:"
        msg3_len equ $-msg3
section .bss
        str1 resb 10H
        str2 resb 10H
        count resb 2
        length resb 2
        temp resb 10H
        
section .text

global _start

_start:
        str32 1,1,msg,msg_len
        str32 0,0,str1,100
        mov [length],rax 
        str32 1,1,msg1,msg1_len
        str32 1,1,str1,100
        str32 1,1,msg2,msg2_len  
        mov al,[length]
        dec al
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
        mov [length],rax
        mov al,[length]
        mov [length],al
        mov rsi,str1
        add rsi,[length]
        mov rdi,str2
        mov bp,[length]
        inc bp
        
      
        
     Next:
        mov al,[rsi]
        mov [rdi],al
        dec rsi
        inc rdi
        dec bp
        jnz Next
        str32 1,1,msg3,msg3_len
        str32 1,1,str2,100
        
mov rax,60
mov rdi,0
syscall

        
        
    
        

