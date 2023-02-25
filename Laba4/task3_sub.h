#pragma once

bool getTask3Sub(int *firstArray, int *secondArray, int *resultArray, int sizeFirst, int sizeSecond,
                 int sizeResult);

bool getTask3Sub(int *firstArray, int *secondArray, int *resultArray, int sizeFirst, int sizeSecond,
                 int sizeResult) {

    int flagFirst = 0;
    int flagSecond = 0;
    int ans = 1;
    __asm {
            xor ecx, ecx
            mov ebx, firstArray // firstArray position
            mov edx, secondArray // secondArray position
            mov esi, resultArray


            begin:

            cmp ecx, sizeFirst
            jge end_begin

            mov eax,[ebx + 4 * ecx]
            xor edi, edi
            begin_second_array:
            cmp edi, sizeSecond
            jge end_second_array
            cmp eax,[edx + 4 * edi]
            jne skip1

            mov flagFirst, 1
            jmp end_second_array

            skip1:
            inc edi
            jmp begin_second_array
            end_second_array:

            xor edi, edi
            begin_result_array:
            cmp edi, sizeResult
            jge end_result_array
            cmp eax,[esi + 4 * edi]
            jne skip2

            mov flagSecond, 1
            jmp end_result_array

            skip2:
            inc edi
            jmp begin_result_array
            end_result_array:

            mov eax, flagFirst
            xor eax, flagSecond
            jnz okay

            mov ans, 0
            jmp end_begin

            okay:

            inc ecx
            mov flagFirst, 0
            mov flagSecond, 0
            jmp begin
            end_begin:

    }
    return ans;
}