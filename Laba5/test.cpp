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

//void getTask2(double a, double b, double c) {
//    __asm {
//
//    }
//}

double getTask2(double a, double b, double c) {
      double eps = 1e-6;
      double left = -10;
      double right = 10;
      double eleven = 11;
      double result;
      __asm {
          finit

      main_begin:
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
          //fpopfstp result //


      }
      console->info("Values is {}", result);
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

TEST(Laba5, Task2) {
    getTask2(1, 1, 1);
}



//TEST(Laba4, Task1) {
//    int array1[] = {1, 1, 1, 1, 5};
//    int sz1 = getTask1(array1, 5);
//    EXPECT_EQ(sz1, 2);
//    EXPECT_EQ(array1[0], 1);
//    EXPECT_EQ(array1[1], 5);
//
//    int array2[] = {1, 2, 1, 1, 5};
//    int sz2 = getTask1(array2, 5);
//    EXPECT_EQ(sz2, 3);
//    EXPECT_EQ(array2[0], 1);
//    EXPECT_EQ(array2[1], 2);
//    EXPECT_EQ(array2[2], 5);
//
//
//    int array3[] = {1, 1, 1, 1, 1};
//    int sz3 = getTask1(array3, 5);
//    EXPECT_EQ(sz3, 1);
//    EXPECT_EQ(array1[0], 1);
//}
//
//TEST(Laba4, Task2) {
//    int arr1[] = {1, 1, 1};
//    int arr2[] = {0, 0, 0};
//    int result[] = {0, 0, 0, 0, 0, 0};
//    getTask2(arr1, arr2, result, 3);
//    EXPECT_TRUE(std::is_sorted(result, result + 6));
//
//
//    int arr3[] = {2, 5, 7};
//    int arr4[] = {1, 6, 7};
//    getTask2(arr3, arr4, result, 3);
//    EXPECT_TRUE(std::is_sorted(result, result + 6));
//
//    int arr5[] = {1, 2, 4};
//    int arr6[] = {12, 12, 13};
//    getTask2(arr5, arr6, result, 3);
//    EXPECT_TRUE(std::is_sorted(result, result + 6));
//
//
//}
//
//TEST(Laba4, Task3Crossing) {
//    int arr1[] = {1, 2, 3};
//    int arr2[] = {4, 2, 1};
//    int res[] = {1, 2};
//    EXPECT_TRUE(getTask3Crossing(arr1, arr2, res, 3, 3, 2));
//    res[1] = 3;
//    EXPECT_FALSE(getTask3Crossing(arr1, arr2, res, 3, 3, 2));
//    arr1[0] = 0;
//    arr2[1] = 5;
//    EXPECT_FALSE(getTask3Crossing(arr1, arr2, res, 3, 3, 2));
//    arr2[0] = 3;
//    EXPECT_TRUE(getTask3Crossing(arr1, arr2, res, 3, 3, 2));
//}
//
//TEST(Laba4, Task3Sub) {
//    int arr1[] = {1, 2, 3};
//    int arr2[] = {4, 2, 1};
//    int res1[] = {3};
//    EXPECT_TRUE(getTask3Sub(arr1, arr2, res1, 3, 3, 1));
//
//    int arr3[] = {1, 2, 3};
//    int arr4[] = {0, 0, 0};
//    int res2[] = {1, 2, 3};
//    EXPECT_TRUE(getTask3Sub(arr3, arr4, res2, 3, 3, 3));
//
//    int arr5[] = {1, 2, 3};
//    int arr6[] = {1, 2, 3};
//    int res3[] = {2};
//    EXPECT_FALSE(getTask3Sub(arr5, arr6, res3, 3, 3, 1));
//}
