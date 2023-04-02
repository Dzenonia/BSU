#include "gtest/gtest.h"
#include <algorithm>
#include "task1.h"
#include "task2.h"
#include "task3_crossing.h"
#include "task3_sub.h"

void task1(int *start, int32_t siz) {
    std::cout << 1 << std::endl;
    int x;
    __asm{
            mov ebx, start
            mov ecx, 0

            beg:
            cmp ecx, siz
            jge fin
            mov esi, ecx
            mov eax, [ebx + esi*4]
            dec esi

            comparison:
            cmp esi, 0
            jl comparisonIsOver
            cmp eax, [ebx + esi*4]
            je remove1
            dec esi
            jmp comparison
            comparisonIsOver:
            inc ecx
            jmp beg

            remove1:
            dec siz
            inc ecx
            cmp ecx, siz
            jge fin
            dec ecx
            mov esi, ecx
            inc esi

            loop1:
            cmp esi, siz
            jge beg
            mov eax, [ebx + esi*4]
            dec esi
            mov [ebx + esi*4], eax
            add esi, 2
            jmp loop1


            fin:
            mov esi, siz

            loop2:
            dec esi
            mov eax, [ebx + esi*4]
            inc esi
            mov [ebx + esi*4], eax
            dec esi
            cmp esi, 0
            jg loop2
            inc siz
            mov eax, siz
            inc eax
            mov [ebx], eax
    }
}

TEST(Laba4, Task1) {
    int array1[] = {1, 1, 1, 1, 5};
    int sz1 = getTask1(array1, 5);
    EXPECT_EQ(sz1, 2);
    EXPECT_EQ(array1[0], 1);
    EXPECT_EQ(array1[1], 5);

    int array2[] = {1, 2, 1, 1, 5};
    int sz2 = getTask1(array2, 5);
    EXPECT_EQ(sz2, 3);
    EXPECT_EQ(array2[0], 1);
    EXPECT_EQ(array2[1], 2);
    EXPECT_EQ(array2[2], 5);


    int array3[] = {1, 1, 1, 1, 1};
    int sz3 = getTask1(array3, 5);
    EXPECT_EQ(sz3, 1);
    EXPECT_EQ(array1[0], 1);
}

TEST(Laba4, Task2) {
    int arr1[] = {1, 1, 1};
    int arr2[] = {0, 0, 0};
    int result[] = {0, 0, 0, 0, 0, 0};
    getTask2(arr1, arr2, result, 3);
    EXPECT_TRUE(std::is_sorted(result, result + 6));


    int arr3[] = {2, 5, 7};
    int arr4[] = {1, 6, 7};
    getTask2(arr3, arr4, result, 3);
    EXPECT_TRUE(std::is_sorted(result, result + 6));

    int arr5[] = {1, 2, 4};
    int arr6[] = {12, 12, 13};
    getTask2(arr5, arr6, result, 3);
    EXPECT_TRUE(std::is_sorted(result, result + 6));


}

TEST(Laba4, Task3Crossing) {
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

TEST(Laba4, Task3Sub) {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 2, 1};
    int res1[] = {3};
    EXPECT_TRUE(getTask3Sub(arr1, arr2, res1, 3, 3, 1));

    int arr3[] = {1, 2, 3};
    int arr4[] = {0, 0, 0};
    int res2[] = {1, 2, 3};
    EXPECT_TRUE(getTask3Sub(arr3, arr4, res2, 3, 3, 3));

    int arr5[] = {1, 2, 3};
    int arr6[] = {1, 2, 3};
    int res3[] = {2};
    EXPECT_FALSE(getTask3Sub(arr5, arr6, res3, 3, 3, 1));
}

TEST(a23, s) {
    int arr1[] = {2, 2, 2, 7, 7, 4};
    std::cout << 1 << std::endl;
    task1(arr1, 6);
    EXPECT_EQ(arr1[0], 4);
    EXPECT_EQ(arr1[1], 2);
    EXPECT_EQ(arr1[2], 7);
    EXPECT_EQ(arr1[3], 4);
}
