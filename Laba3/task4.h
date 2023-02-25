#pragma once

#include "task5.h"


int getTask4(int);

int getTask4(int number) {
    int res = 0;
    __asm {
            mov eax, number
            xor ebx, ebx
            mov ecx, 10

            begin:
            cdq
            idiv ecx
            imul ebx, 10
            add ebx, edx

            cmp edx, 1
            jne skip
            imul ebx, 10
            add ebx, edx

            skip:
            cmp eax, 0
            jne begin

            mov res, ebx
    }
    return getTask5(res);
}