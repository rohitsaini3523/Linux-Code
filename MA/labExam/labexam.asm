; Name: Rohit Saini 
;Roll no: 06
;Panel: A1
;Erp: 1032200897
;Write an ALP to display the contents of GDTR.
%macro str32 4
    mov rax,%1
    mov rdi,%2
    mov rsi,%3
    mov rdx,%4
    syscall
%endmacro
section .data
    msg1 db "Protected Mode",10
    msg1len equ $-msg1
    msg db "Content of GDTR: "
    msglen equ $-msg
    newline db 10
section .bss
    value_gdt resb 6
    ;value_msw resb 4
    value resb 4
section .text
global _start
_start:
   ; SMSW [value_msw]
   ; mov eax,[value_msw]
   ; BT eax,0
  ;  jc Protected
   ; jmp exit

    Protected:
        ;str32 1,1,msg1,msg1len
        ;str32 1,1,newline,1
        SGDT [value_gdt]
        str32 1,1,msg,msglen
        mov bx,word[value_gdt]
        call printer
        mov bx,word[value_gdt+2]
        call printer 
        mov bx,word[value_gdt+4]
        call printer
    exit:
        str32 1,1,newline,1
        mov rax,60
        mov rdi,0
        syscall
    printer:
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
            add cl,30H
            mov [rdi],cl
            inc rdi
            dec bp
            jnz up
            str32 1,1,value,4
            ret
