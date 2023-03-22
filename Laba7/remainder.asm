.386
public @Remainder@8
.model flat
.code
@Remainder@8 proc
    mov eax,ecx ;первый параметр
    mov ecx,edx ;второй параметр
    cdq
    idiv ecx
    mov eax,edx
    ret
@Remainder@8 endp
end