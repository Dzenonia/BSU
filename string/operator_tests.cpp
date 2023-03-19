#include "string.h"
#include "gtest/gtest.h"

TEST(Operator, OpaeratorPlus) {
    String s1 = "abc";
    String s2 = "def";
    String s3 = "";
    s1 += s2;
    EXPECT_EQ(s1.length(), 6);
    EXPECT_EQ(s1, "abcdef");

    s1 += s3;
    EXPECT_EQ(s1, "abcdef");
}