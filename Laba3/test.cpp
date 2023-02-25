#include "gtest/gtest.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"

TEST(Laba3, Task1) {
    EXPECT_DOUBLE_EQ(getTask1(1, 3), -3);
    EXPECT_DOUBLE_EQ(getTask1(2, 5), static_cast<double>(-5) / 2);
    EXPECT_DOUBLE_EQ(getTask1(2, 3), static_cast<double>(-3) / 2);
    EXPECT_DOUBLE_EQ(getTask1(-2, 5), static_cast<double>(-5) / -2);
    EXPECT_ANY_THROW(getTask1(0, 1));
}

TEST(Laba3, Task2) {
    EXPECT_EQ(1, getTask2(1));
    EXPECT_EQ(5, getTask2(2));
    EXPECT_EQ(6, getTask2(3));
    EXPECT_EQ(25, getTask2(4));
    EXPECT_EQ(9376, getTask2(8));
    EXPECT_ANY_THROW(getTask2(10));
    EXPECT_ANY_THROW(getTask2(9));
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
    EXPECT_EQ(getTask3(1000000), 1);
}

TEST(Laba3, Task4) {
    EXPECT_EQ(getTask4(1), 11);
    EXPECT_EQ(getTask4(121), 11211);
    EXPECT_EQ(getTask4(0), 0);
    EXPECT_EQ(getTask4(34123), 341123);
    EXPECT_EQ(getTask4(2345), 2345);
}

TEST(Laba3, Task5) {
    EXPECT_EQ(getTask5(1), 1);
    EXPECT_EQ(getTask5(121), 121);
    EXPECT_EQ(getTask5(0), 0);
    EXPECT_EQ(getTask5(12345), 54321);
    EXPECT_EQ(getTask5(1000), 1);
    EXPECT_ANY_THROW(getTask5(1234567899));
}

TEST(Laba3, Task6) {
    EXPECT_EQ(getTask6(1, 1), 1);
    EXPECT_EQ(getTask6(1, 2), 1);
    EXPECT_EQ(getTask6(10, 2), 2);
    EXPECT_EQ(getTask6(36, 8), 4);
    EXPECT_EQ(getTask6(2, 4), 2);
    EXPECT_EQ(getTask6(9, 17), 1);
    EXPECT_EQ(getTask6(48, 18), 6);
    EXPECT_EQ(getTask6(3423432, 423423422), 2);
}
