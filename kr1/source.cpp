#include "header.h"

int Service::replaceSubStrings(int *array, int arrayN, int *str, int strN, int *strNew, int newN, int *newArray) {
    int resLength = 0;
    int lastPosition;
    __asm {
            mov ecx, 0

            while_true:
            mov ebx, array
            mov edi, str
            mov esi, strNew

            xor edx, edx
            mov lastPosition, ecx
            check_str:
            cmp edx, strN
            jge succesful_substr
            cmp ecx, arrayN
            jge end_check_str
            mov eax,[edi + 1 * edx]
            cmp eax,[ebx + 1 * ecx]
            jne end_check_str
            inc edx
            inc ecx
            jmp check_str
            end_check_str:
        // its not substr

            mov ecx, lastPosition
            mov eax,[ebx + 1 * ecx]
            mov edi, resLength
            mov esi, newArray
            mov[esi + 1 * edi], eax
            inc resLength
            jmp new_ind



            succesful_substr:
            xor edx, edx
            mov edi, newArray
            mov ebx, resLength
            remove_substr:
            mov eax,[esi + 1 * edx] // strNew[edx]
            mov[edi + 1 * ebx], eax // newArray
            inc edx
            inc ebx
            inc resLength
            cmp edx, newN
            jge end_remove_substr
            jmp remove_substr
            end_remove_substr:
            jmp check_while_true





            new_ind:
            inc ecx


            check_while_true:
            cmp ecx, arrayN
            jl while_true


            end_while_true:


    }
    return resLength;
}