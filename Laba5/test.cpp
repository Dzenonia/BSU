#include "gtest/gtest.h"
#include <algorithm>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

auto console = spdlog::stderr_color_mt("console");

double getTask1(double x, double y) {
    console->info("Laba5-Task1-Begin values are ({}, {}) ", x, y);
    double result;
    double check1;
    __asm {
        finit
        fld x
        fmul st(0), st(0)
        fld x
        fdiv y
        fptan
        fstp result // just pop
        fmulp st(1), st(0)


        fld y
        fmul y
        fld x
        fdiv y
        fptan
        fstp result
        fdivp st(1), st(0)

        faddp st(1), st(0)
        fstp result
    }
    console->info("Laba5-Task1-End result on ({}, {}) is {}", x, y, result);
    return result;
}

double getTask2(double a, double b, double c) {
      double eps = 1e-6;
      double left = -10;
      double right = 10;
      double eleven = 11;
      double result;
      __asm {
          finit

      main_begin:
          // ax^2 + b / (x + 11) + c
          fld left
          fmul left
          fmul a
          fld b
          fld left
          fadd eleven
          fdivp st(1), st(0)
          faddp st(1), st(0)
          fadd c

          fld left
          fadd

      }
      console->info("Values is {}", result);
}

double piNumber(int cntIteration) {
    double result = 0;
    double zero = 0;
    double twelve = 12;
    double delEps;
    __asm {
        finit
        mov ecx, cntIteration
        fldz // result
        fld1 // k
        fld1 // sgn
        cmp ecx, 0
        je end_loop
        begin_loop:
            fld st(0)
            fld st(2)
            fmul st(0), st(0)
            fdivp st(1), st(0)
            faddp st(3), st(0)
            fld1
            faddp st(2), st(0)
            fchs
            loop begin_loop
        end_loop:
        fstp result
        fstp result
        mov eax, 12
        fld twelve
        fmulp st(1), st(0)
        fsqrt
        fldpi
        fsub st(0), st(1)
        fstp delEps
        fstp result
    }
    std::cout << delEps << '\n';
    return result;
}

double lnNumber(int cntIteration) {
    double result = 0;
    double two = 2;
    double four = 4;
    double delEps;
    __asm {
            finit
            mov ecx, cntIteration
            fldz // result
            fld1 // k
            cmp ecx, 0
            je end_loop
            begin_loop:
                fld1
                fld st(1)
                fmul st(0), st(0)
                fmul st(0), st(2)
                fmul four
                fsub st(0), st(2)
                // 4k^3 - k
                fdivp st(1), st(0)
                faddp st(2), st(0)
                // complete
                fld1
                faddp st(1), st(0)
                loop begin_loop
            end_loop:
            fstp result
            fld1
            faddp st(1), st(0)
            fdiv two
            fldln2
            fsub st(0), st(1)
            fstp delEps
            fst result
    }
    std::cout << delEps << '\n';
    return result;
}

double getTask5(double eps = 1e-6) {
    double result;
    double delEps;
    __asm {
        finit

        fldz
        fldz

        loop_begin:
            fld st(0)
            fmul st(0), st(0)
            fld st(1)
            fsin
            faddp st(1), st(0)
            faddp st(2), st(0)
            fadd eps

            fldpi
            fadd st(0), st(0)
            fcomi st(0), st(1)

            fstp result
            jbe end_loop

            jmp loop_begin
        end_loop:

        fstp result
        fmul eps
        fstp result
    }
    return result;
}

double getTsk6(double x) {
    double result;

    __asm {
            fldln2
            fld x
            fyl2x
            fld1
            faddp st(1), st(0)
            fxch
            f2xm1
            fld1
            faddp st(1), st(0)
            fscale
            fstp result
    }
    return result;
}



TEST(Laba5, Task1) {
    auto func = [](double x, double y) -> double {
        return x * x * tan(x / y) + y * y / tan(x / y);
    };
    EXPECT_DOUBLE_EQ(getTask1(2, 3), func(2, 3));
    EXPECT_DOUBLE_EQ(getTask1(1, 3), func(1, 3));
    EXPECT_DOUBLE_EQ(getTask1(-1, 4), func(-1, 4));
    EXPECT_DOUBLE_EQ(getTask1(0.1221, 0.9812), func(0.1221, 0.9812));
}

TEST(Laba5, Task3) {
    std::cout << std::fixed << std::setprecision(30) << piNumber(100000000) << '\n';
}

TEST(Laba5, Task4) {
    std::cout << std::fixed << std::setprecision(30) << lnNumber(100000000) << '\n';
}

TEST(Laba5, Task5) {
    std::cout << std::fixed << std::setprecision(30) << getTask5() << '\n';
}


