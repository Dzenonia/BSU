#pragma once

int getTask6(int, int);

int getTask6(int rhs, int lhs) {
    int gcd;
    __asm {
            mov eax, rhs
            mov ecx, lhs
            beg:
            cmp ecx, 0
            je end
            cdq
            idiv ecx
            mov eax, ecx
            mov ecx, edx
            jmp beg
            end:
            mov gcd, eax
    }
    return gcd;
}