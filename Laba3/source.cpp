#include "gtest/gtest.h"
#include "spdlog/spdlog.h"
#include <iostream>

int getTask5(int);

double getTask1(int lhs, int rhs) {
    if (lhs == 0) {
        throw std::invalid_argument("Division by zero");
    }
    double res;
    __asm {
            finit
            fild lhs
            fild rhs
            fchs
            fdiv st(0), st(1)
            fstp res
    }
    return res;
}

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
//std::set<double> getTask2(int a, int b, int c) {
//    std::set<double> res;
//    int four = -4;
//    double d;
//    __asm {
//        finit
//        fild b
//        fild b
//        fmul st(0), st(1)
//        fild a
//        fild c
//        fmul st(0), st(1)
//        fild four
//        fmul st(0), st(1)
//        fadd st(0), st(3)
//        fsqrt
//
//
//    }
//    std::cout << d << '\n';
//    return {};
//}

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

int getTask5(int number) {
    int res = 0;
    try {
        __asm {
                mov eax, number
                xor ebx, ebx
                mov ecx, 10

                begin:
                cdq
                idiv ecx
                imul ebx, 10
                add ebx, edx
                cmp eax, 0
                jne begin

                mov res, ebx
        }
    } catch (...) {
        throw std::overflow_error("Reverse number more than 32-bit number");
    }
    return res;
}

int getTask6(int rhs, int lhs) {
    int gcd;
    __asm {
            mov eax, rhs
            mov ecx, lhs
            beg:
            cmp ecx, 0
            je end
            cdq
            idiv ecx
            mov eax, ecx
            mov ecx, edx
            jmp beg
            end:
            mov gcd, eax
    }
    return gcd;
}

TEST(Laba3, Task3) {
    EXPECT_EQ(getTask3(1), 1);
    EXPECT_EQ(getTask3(0), 0);
    EXPECT_EQ(getTask3(-1), 1);
    EXPECT_EQ(getTask3(12304), 10);
    EXPECT_EQ(getTask3(-12304), 10);
    EXPECT_EQ(getTask3((1 << 31) - 1), 46);
    EXPECT_EQ(getTask3(-(1 << 31)), 47);
    EXPECT_EQ(getTask3(190190), 20);
}

TEST(Laba3, Task6) {
    EXPECT_EQ(getTask6(1, 1), 1);
    EXPECT_EQ(getTask6(1, 2), 1);
    EXPECT_EQ(getTask6(10, 2), 2);
    EXPECT_EQ(getTask6(36, 8), 4);
    EXPECT_EQ(getTask6(2, 4), 2);
    EXPECT_EQ(getTask6(9, 17), 1);
    double start = clock();
    EXPECT_EQ(getTask6(3423432, 423423422), 2);
    double end = clock();
}

TEST(Time, Score) {
    const int ITERATION = 1e9;
    int value = 0;
    auto start = std::chrono::steady_clock::now();
    __asm {
            mov ecx, ITERATION
            xor eax, eax

            pzda:


            begin:
            inc value
            jo pzda
            loope begin


            mov eax, value
    }

    assert(value == ITERATION);
    auto end = std::chrono::steady_clock::now();
    std::cout << "Asm " << std::fixed << std::setprecision(18)
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << '\n';
    start = std::chrono::steady_clock::now();
    std::cout << ITERATION << '\n';
    for (int i = 0; i < 2 * ITERATION; ++i) {

    }
    end = std::chrono::steady_clock::now();
    std::cout << "C++ " << std::fixed << std::setprecision(18)
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << '\n';
}

TEST(Laba3, Task1) {
    EXPECT_DOUBLE_EQ(getTask1(1, 3), -3);
    EXPECT_DOUBLE_EQ(getTask1(2, 5), static_cast<double>(static_cast<double>(-5) / 2));
    EXPECT_DOUBLE_EQ(getTask1(2, 3), static_cast<double>(static_cast<double>(-3) / 2));
    EXPECT_DOUBLE_EQ(getTask1(-2, 5), static_cast<double>(static_cast<double>(-5) / -2));
}

TEST(Laba3, Task2) {
    EXPECT_EQ(1, getTask2(1));
    EXPECT_EQ(5, getTask2(2));
    EXPECT_EQ(6, getTask2(3));
    EXPECT_EQ(25, getTask2(4));
    EXPECT_ANY_THROW(getTask2(10));
    EXPECT_ANY_THROW(getTask2(9));
    EXPECT_EQ(9376, getTask2(8));
//    EXPECT_DOUBLE_EQ(getTask1(1, 3), -3);
//    EXPECT_DOUBLE_EQ(getTask1(2, 5), static_cast<double>(static_cast<double>(-5) / 2));
//    EXPECT_DOUBLE_EQ(getTask1(2, 3), static_cast<double>(static_cast<double>(-3) / 2));
//    EXPECT_DOUBLE_EQ(getTask1(-2, 5), static_cast<double>(static_cast<double>(-5) / -2));
}

TEST(Laba3, Task4) {
    EXPECT_EQ(getTask4(1), 11);
    EXPECT_EQ(getTask4(121), 11211);
    EXPECT_EQ(getTask4(0), 0);
    EXPECT_EQ(getTask4(34123), 341123);
    //EXPECT_ANY_THROW(getTask5(1234567899));
}

TEST(Laba3, Task5) {
    EXPECT_EQ(getTask5(1), 1);
    EXPECT_EQ(getTask5(121), 121);
    EXPECT_EQ(getTask5(0), 0);
    EXPECT_EQ(getTask5(12345), 54321);
    EXPECT_EQ(getTask5(1000), 1);
    //EXPECT_ANY_THROW(getTask5(1234567899));
}