#include "string_view.h"
#include <gtest/gtest.h>

TEST(StringViewTest, DefaultConstructor) {
    StringView s;
    EXPECT_EQ(s.length(), 0);
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(s.data(), nullptr);
}

TEST(StringViewTest, StartsWith) {
    StringView str("Hello, world!");

    EXPECT_TRUE(str.startsWith(StringView("Hello")));
    EXPECT_TRUE(str.startsWith(StringView("Hello,")));
    EXPECT_FALSE(str.startsWith(StringView("hello")));
    EXPECT_TRUE(str.startsWith(StringView("H")));
}

TEST(StringViewTest, EndsWith) {
    StringView str("Hello, world!");

    EXPECT_TRUE(str.endsWith(StringView("world!")));
    EXPECT_TRUE(str.endsWith(StringView(", world!")));
    EXPECT_FALSE(str.endsWith(StringView("World!")));
    EXPECT_TRUE(str.endsWith(StringView("!")));
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

TEST(StringViewTest, CompareOperators) {
    StringView emptyView;
    StringView abcView("abc");
    StringView xyzView("xyz");
    StringView abcdeView("abcde");

    // ==
    EXPECT_TRUE(emptyView == emptyView);
    EXPECT_TRUE(abcView == abcView);
    EXPECT_TRUE(xyzView == xyzView);
    EXPECT_TRUE(abcdeView == abcdeView);
    EXPECT_TRUE(abcView == StringView("abc"));
    EXPECT_TRUE(StringView("abc") == abcView);
    EXPECT_TRUE(emptyView != abcView);
    EXPECT_TRUE(abcView != xyzView);
    EXPECT_TRUE(abcView != abcdeView);

    // <
    EXPECT_FALSE(emptyView < emptyView);
    EXPECT_FALSE(abcView < abcView);
    EXPECT_FALSE(xyzView < xyzView);
    EXPECT_FALSE(abcdeView < abcdeView);
    EXPECT_TRUE(emptyView < abcView);
    EXPECT_TRUE(abcView < xyzView);
    EXPECT_TRUE(emptyView < abcdeView);
    EXPECT_TRUE(abcView < abcdeView);
    EXPECT_FALSE(xyzView < abcView);
    EXPECT_FALSE(abcdeView < abcView);

    // >
    EXPECT_FALSE(emptyView > emptyView);
    EXPECT_FALSE(abcView > abcView);
    EXPECT_FALSE(xyzView > xyzView);
    EXPECT_FALSE(abcdeView > abcdeView);
    EXPECT_FALSE(emptyView > abcView);
    EXPECT_FALSE(abcView > xyzView);
    EXPECT_TRUE(xyzView > abcView);
    EXPECT_FALSE(emptyView > abcdeView);
    EXPECT_FALSE(abcView > abcdeView);
    EXPECT_TRUE(abcdeView > abcView);
}

TEST(Others, check) {
    StringView view("hello world");
    int pos = view.find("world");
    EXPECT_EQ(pos, 6);
}

TEST(StringViewTest, RemovePrefixTest) {
    StringView view("hello");
    view.removePrefix(2);
    EXPECT_EQ(view, "llo");

    view.removePrefix(3);
    EXPECT_EQ(view, "");
}

TEST(StringViewTest, RemoveSuffixTest) {
    StringView view("world");
    view.removeSuffix(2);
    EXPECT_EQ(view, "wor");

    view.removeSuffix(3);
    EXPECT_EQ(view, "");
}

TEST(StringViewTest, SubstrTest) {
    StringView view("hello world");
    auto substr1 = view.substr(6);
    EXPECT_EQ(substr1, "world");

    auto substr2 = view.substr(0, 5);
    EXPECT_EQ(substr2, "hello");
}

TEST(StringViewTest, FindTest) {
    StringView view("hello world");
    EXPECT_EQ(view.find('h'), 0);
    EXPECT_EQ(view.find('l', 3), 3);

    int pos = view.find("world");
    EXPECT_EQ(pos, 6);

    int notFound = view.find("python");
    EXPECT_EQ(notFound, StringView::N_POS);
}

TEST(StringViewTest, AllMethodsCombined) {
    // Create a StringView to test
    StringView sv("Hello, world!");

    // Test operator[], at, front, and back
    EXPECT_EQ(sv[0], 'H');
    EXPECT_EQ(sv.at(2), 'l');

    // Test size, length, and empty
    EXPECT_EQ(sv.length(), 13);
    EXPECT_FALSE(sv.empty());

    // Test removePrefix and removeSuffix
    sv.removePrefix(1);
    sv.removeSuffix(1);

    // Test substr
    StringView substr = sv.substr(1, 3);
    EXPECT_EQ(substr, StringView("llo"));

    // Test find
    int pos = sv.find('r');
    EXPECT_EQ(pos, 8);
    pos = sv.find("rl");
    EXPECT_EQ(pos, 8);

    // Test startsWith and endsWith
    EXPECT_FALSE(sv.startsWith("wor"));
    EXPECT_TRUE(sv.endsWith("ld"));

}
