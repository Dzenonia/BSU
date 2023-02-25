#pragma once

#include "stdexcept"

int getTask5(int);

int getTask5(int number) {
    int res = 0;
    int ov = 0;
    __asm {
            mov eax, number
            xor ebx, ebx
            mov ecx, 10

            begin:
            cdq
            idiv ecx
            imul ebx, 10
            jno skip

            overflow:
            mov ov, 1
            jmp end_begin

            skip:
            add ebx, edx
            jo overflow
            cmp eax, 0
            jne begin

            end_begin:

            mov res, ebx
    }


    if (ov == 1) {
        throw std::overflow_error("Reverse number more than 32-bit number");
    }
    return res;
}