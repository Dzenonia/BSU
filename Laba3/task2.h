#pragma once

#include <iostream>

uint32_t getTask2(int16_t);

uint32_t getTask2(int16_t n) {
    int32_t res = 0;
    int32_t ten = 10;
    __asm {
            mov eax, 1
            mov ecx, 10

            Begin:

            mov ebx, eax

            imul eax
            jo Exit

            cdq
            idiv ecx


            cmp ebx, edx
            jne skip
            dec n
            mov res, ebx
            jz Exit
            skip:



            mov eax, ebx
            inc eax
            cdq
            idiv ecx

            mov eax, ebx
            inc eax

            cmp edx, 0
            jne Begin
            imul ecx, ten
            jmp Begin
            Exit:
    }
    if (n > 0) {
        throw std::overflow_error("Cannot find this number!");
    }
    return res;
}