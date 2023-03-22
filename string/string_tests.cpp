#include "string.h"
#include "string_view.h"
#include "gtest/gtest.h"

TEST(StringConstructor, DefaultConstructor) {
    String s;
    EXPECT_EQ(0, s.length());
    EXPECT_EQ('\0', s.cStr()[0]);
}

TEST(StringConstructor, CharConstructor) {
    String s1("abc");
    EXPECT_EQ(3, s1.length());
    EXPECT_EQ('a', s1.front());
    EXPECT_EQ('c', s1.back());
    EXPECT_STREQ("abc", s1.cStr());

    String s2("");
    EXPECT_EQ(0, s2.length());
    EXPECT_EQ('\0', s2.cStr()[0]);
}

TEST(StringConstructor, CountConstructor) {
    String s1(3, 'x');
    EXPECT_EQ(3, s1.length());
    EXPECT_EQ('x', s1.front());
    EXPECT_EQ('x', s1.back());
    EXPECT_STREQ("xxx", s1.cStr());

    String s2(0, 'x');
    EXPECT_EQ(0, s2.length());
    EXPECT_EQ('\0', s2.cStr()[0]);
}

TEST(StringConstructor, CopyConstructor) {
    String s1("abc");
    String s2(s1);
    EXPECT_EQ(3, s2.length());
    EXPECT_EQ('a', s2.front());
    EXPECT_EQ('c', s2.back());
    EXPECT_STREQ("abc", s2.cStr());

    String s3("");
    String s4(s3);
    EXPECT_EQ(0, s4.length());
    EXPECT_EQ('\0', s4.cStr()[0]);
}

TEST(StringConstructor, MoveConstructor) {
    String s1("abc");
    String s2(std::move(s1));
    EXPECT_EQ(0, s1.length());
    EXPECT_EQ('\0', s1.cStr()[0]);
    EXPECT_EQ(3, s2.length());
    EXPECT_EQ('a', s2.front());
    EXPECT_EQ('c', s2.back());
    EXPECT_STREQ("abc", s2.cStr());

    String s3("");
    String s4(std::move(s3));
    EXPECT_EQ(0, s3.length());
    EXPECT_EQ('\0', s3.cStr()[0]);
    EXPECT_EQ(0, s4.length());
    EXPECT_EQ('\0', s4.cStr()[0]);
}

TEST(StringDestructor, DefaultDestructor) {
    String *s1 = new String("abc");
    delete s1;

    String *s2 = new String("");
    delete s2;
}

TEST(StringTest, CompareOperators) {
    String first = "abc";
    String second = "abce";

    EXPECT_TRUE(first <= second);
    EXPECT_TRUE(first != second);
    EXPECT_EQ(first, "abc");

    first += "df";

    EXPECT_TRUE(first == "abcdf");
    EXPECT_TRUE(second > first);
}

TEST(StringTest, InsertErase) {
    String first = "abef";
    String second = "cd";

    first.insert(2, second);
    EXPECT_EQ(first, "abcdef");

    first.insert(0, second);
    EXPECT_EQ(first, "cdabcdef");

    first.insert(first.length(), second);
    EXPECT_EQ(first, "cdabcdefcd");

    first.erase(4, 2);
    EXPECT_EQ(first, "cdabefcd");

    first.erase(0, 2);
    EXPECT_EQ(first, "abefcd");

    first.pop_back();
    first.erase(4, 1);
    EXPECT_EQ(first, "abef");

    first.push_back('!');
    EXPECT_EQ(first, "abef!");
}