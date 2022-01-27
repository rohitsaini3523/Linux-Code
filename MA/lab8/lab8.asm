%macro str32 4
        mov rax,%1
        mov rdi,%2
        mov rsi,%3
        mov rdx,%4
        syscall
%endmacro

section .data
    string db "The Vendor id string is: ",10
    slen equ $-string
section .bss
    answer resb 12
section .text
global _start
_start:
    xor eax,eax
    cpuid
    mov edi,answer
    mov[edi],ebx
    mov [edi+4],edx
    mov[edi+8],ecx
    str32 1,1,string,slen
    str32 1,1,answer,12
mov rax,60
mov rdi,0
syscall