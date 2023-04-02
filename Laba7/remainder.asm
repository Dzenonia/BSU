.386
public @checkPalindrom@8
.model flat
.code
@checkPalindrom@8 proc
    mov esi, edx
    dec ecx
    mov ebx, esi
    add ebx, ecx
    begin:
        mov eax, [esi]
        cmp eax, [ebx]
        je good
            mov eax, 0
            ret
        good:
        inc esi
        dec ebx
        dec ecx
        cmp ecx, 0
        jge begin
    mov eax, 1
    ret
@checkPalindrom@8 endp

end