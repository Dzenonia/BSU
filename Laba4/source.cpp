#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include "gtest/gtest.h"
#include <bitset>

auto console = spdlog::stderr_color_mt("console");

void getTask1(int *array, int n) {
    int sz = n - 1;
    int e1 = 10012, e2 = 0, e3 = 0, e4 = -1, e5 = 0, e6 = -1, e7 = -1;

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
            mov e2, eax
            mov e1, edx
            xor eax, eax
            begin2:

            cmp eax, edx
            je end_begin2

            cmp ebx,[edi][4 * eax]

            je end_begin2

            inc eax


            jmp begin2

            end_begin2:

            mov e2, eax

            cmp eax, edx

            jne not_equal

            inc edx

            not_equal:

            inc esi

            loop begin

            end_begin:


            mov e1, edx


    }
    std::cout << e1 << " " << e2 << " !!!! " << '\n';
}

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
        //mov eax, [ebx + dword ptr 4 * ptrFirst]

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

bool getTask3Crossing(int *firstArray, int *secondArray, int *resultArray, int sizeFirst, int sizeSecond,
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

            mov eax, [ebx + 4 * ecx]
            xor edi, edi
            begin_second_array:
            cmp edi, sizeSecond
            jge end_second_array
            cmp eax, [edx + 4 * edi]
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
            cmp eax, [esi + 4 * edi]
            jne skip2

            mov flagSecond, 1
            jmp end_result_array

            skip2:
            inc edi
            jmp begin_result_array
            end_result_array:

            mov eax, flagFirst
            xor eax, flagSecond
            jz okay

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

TEST(Laba4, Task1) {
    int array[] = {1, 1, 1, 1, 5};
    getTask1(array, 5);
    for (auto var: array) {
        std::cout << var << '\n';
    }
}

TEST(Laba4, Task2) {
    int arr1[] = {1, 1, 1};
    int arr2[] = {0, 0, 0};
    int result[] = {0, 0, 0, 0, 0, 0};
    //EXPECT_EQ(result, {1});
    getTask2(arr1, arr2, result, 3);
    for (int var: result) {
        std::cout << var << " ";
    }
    std::cout << '\n';
}

TEST(Laba4, Task3) {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 2, 1};
    int res[] = {1, 2};
    EXPECT_TRUE(getTask3Crossing(arr1, arr2, res, 3, 3, 2));
    res[1] = 3;
    EXPECT_FALSE(getTask3Crossing(arr1, arr2, res, 3, 3, 2));
    arr1[0] = 0;
    arr2[1] = 5;
    EXPECT_FALSE(getTask3Crossing(arr1, arr2, res, 3, 3, 2));
    arr2[0] = 3;
    EXPECT_TRUE(getTask3Crossing(arr1, arr2, res, 3, 3, 2));
}
