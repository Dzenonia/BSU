#pragma once

void getTask2(int *firstArray, int *secondArray, int *result, int n);

void getTask2(int *firstArray, int *secondArray, int *result, int n) {
    int sz = n;
    int resSize = 2 * n;
    int ptrFirst = 0;
    int ptrSecond = 0;
    __asm {
            xor ecx, ecx
            mov ebx, firstArray // firstArray position
            mov edx, secondArray // secondArray position
            mov esi, result

            begin:

            mov eax, sz
            cmp ptrFirst, eax
            jl skip1
            mov eax, ptrSecond
            mov eax,[edx + 4 * eax]
            mov[esi + 4 * ecx], eax
            inc ptrSecond
            jmp loop1

            skip1:

            mov eax, sz
            cmp ptrSecond, eax
            jl skip2
            mov eax, ptrFirst
            mov eax,[ebx + 4 * eax]
            mov[esi + 4 * ecx], eax
            inc ptrFirst
            jmp loop1
            skip2:

            mov eax, ptrFirst
            mov eax,[ebx][4 * eax]
            mov edi, ptrSecond
            cmp eax,[edx][4 * edi]
            jl less
            mov eax, ptrSecond
            mov eax,[edx + 4 * eax]
            mov[esi + 4 * ecx], eax
            inc ptrSecond
            jmp loop1
            less:
            mov[esi + 4 * ecx], eax
            inc ptrFirst

            loop1:
            inc ecx
            cmp ecx, resSize
            jne begin
    }
}