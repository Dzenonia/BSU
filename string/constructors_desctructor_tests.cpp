#include "string.h"
#include "string_view.h"
#include "gtest/gtest.h"

TEST(StringConstructor, DefaultConstructor) {
    String s;
    EXPECT_EQ(0, s.length());
    EXPECT_EQ('\0', s.c_str()[0]);
}

TEST(StringConstructor, CharConstructor) {
    String s1("abc");
    EXPECT_EQ(3, s1.length());
    EXPECT_EQ('a', s1.front());
    EXPECT_EQ('c', s1.back());
    EXPECT_STREQ("abc", s1.c_str());

    String s2("");
    EXPECT_EQ(0, s2.length());
    EXPECT_EQ('\0', s2.c_str()[0]);
}

TEST(StringConstructor, CountConstructor) {
    String s1(3, 'x');
    EXPECT_EQ(3, s1.length());
    EXPECT_EQ('x', s1.front());
    EXPECT_EQ('x', s1.back());
    EXPECT_STREQ("xxx", s1.c_str());

    String s2(0, 'x');
    EXPECT_EQ(0, s2.length());
    EXPECT_EQ('\0', s2.c_str()[0]);
}

TEST(StringConstructor, CopyConstructor) {
    String s1("abc");
    String s2(s1);
    EXPECT_EQ(3, s2.length());
    EXPECT_EQ('a', s2.front());
    EXPECT_EQ('c', s2.back());
    EXPECT_STREQ("abc", s2.c_str());

    String s3("");
    String s4(s3);
    EXPECT_EQ(0, s4.length());
    EXPECT_EQ('\0', s4.c_str()[0]);
}

TEST(StringConstructor, MoveConstructor) {
    String s1("abc");
    String s2(std::move(s1));
    EXPECT_EQ(0, s1.length());
    EXPECT_EQ('\0', s1.c_str()[0]);
    EXPECT_EQ(3, s2.length());
    EXPECT_EQ('a', s2.front());
    EXPECT_EQ('c', s2.back());
    EXPECT_STREQ("abc", s2.c_str());

    String s3("");
    String s4(std::move(s3));
    EXPECT_EQ(0, s3.length());
    EXPECT_EQ('\0', s3.c_str()[0]);
    EXPECT_EQ(0, s4.length());
    EXPECT_EQ('\0', s4.c_str()[0]);
}

TEST(StringDestructor, DefaultDestructor) {
    String* s1 = new String("abc");
    delete s1;

    String* s2 = new String("");
    delete s2;
}

TEST(StringViewTest, DefaultConstructor) {
    StringView s;
    EXPECT_EQ(s.length(), 0);
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(s.data(), nullptr);
}

TEST(StringViewTest, ConstructorWithString) {
    const char* str = "hello, world";
    std::cout << str << '\n';
    StringView s(str);
    EXPECT_EQ(s.length(), strlen(str));
    EXPECT_FALSE(s.empty());
    EXPECT_EQ(s.data(), str);

    StringView s2(str, 5);
    EXPECT_EQ(s2.length(), 5);
    EXPECT_FALSE(s2.empty());
    EXPECT_EQ(strncmp(s2.data(), str, 5), 0);

    StringView s3(str, 20);
    EXPECT_EQ(s3.length(), strlen(str));
    EXPECT_FALSE(s3.empty());
    EXPECT_EQ(s3.data(), str);
}

TEST(StringViewTest, Destructor) {
    const char* str = "hello, world";
    {
        StringView s(str);
        EXPECT_EQ(s.data(), str);
    }
    // the destructor should not delete the original string
    EXPECT_EQ(strncmp(str, "hello, world", strlen(str)), 0);
}

