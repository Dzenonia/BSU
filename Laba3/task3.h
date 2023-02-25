#pragma once

#include <iostream>

int getTask3(int);

int getTask3(int number) {
    int32_t res = 0;
    __asm {
            mov eax, number
            mov ecx, 10
            beg:
            cmp eax, 0
            jz end
            cdq
            idiv ecx
            add res, edx
            jmp beg
            end:
            cmp res, 0
            jg greatzero
            neg res
            greatzero:
    }
    return res;
}