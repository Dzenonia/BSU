#include "gtest/gtest.h"
#include <algorithm>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "header.h"

TEST(Check, All) {
    int array[3] = {1, 2, 3};
    int str[1] = {2};
    int newStr[1] = {1};
    int newArray[3];
    Service::replaceSubStrings(array, 3, str, 1, newStr, 1, newArray);
   // EXPECT_EQ(service::replaceSubStrings(array, 3, str, 1, newStr, 1, newArray), 3);
    for (auto c: newArray) {
        std::cout << c;
    }
    std::cout << '\n';
}

