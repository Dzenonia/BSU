#pragma once

int getTask1(int *, int);

int getTask1(int *array, int n) {
    int sz = n - 1;
    int newSize;
    __asm {
            mov edi, array // edi -- address on the start of the array
            mov ecx, sz
            mov esi, 1 // esi is now position
            mov edx, 1 // edx is end of the new array
            xor eax, eax // variable for iterating in the new array


            cmp ecx, 0
            jle end_begin

            begin:

            mov eax,[edi + 4 * esi]
            mov ebx, eax
            mov[edi + 4 * edx], eax
            xor eax, eax
            mov eax,[edi][4 * eax]
            xor eax, eax
            begin2:

            cmp eax, edx
            je end_begin2

            cmp ebx,[edi][4 * eax]

            je end_begin2

            inc eax


            jmp begin2

            end_begin2:

            cmp eax, edx

            jne not_equal

            inc edx

            not_equal:

            inc esi

            loop begin

            end_begin:


            mov newSize, edx

    }
    return newSize;
}
