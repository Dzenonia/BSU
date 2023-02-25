#include <bitset>
#include "gtest/gtest.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

auto console = spdlog::stderr_color_mt("console");

auto funcTo48Bits = [](const std::tuple<uint16_t, uint16_t, int16_t> &value) -> int64_t {
    std::bitset<48> answer;
    for (int i = 0; i < 16; ++i) {
        answer[47 - i] = (std::get<2>(value) >> (15 - i)) & 1;
    }
    for (int i = 0; i < 16; ++i) {
        answer[31 - i] = (std::get<1>(value) >> (15 - i)) & 1;
    }
    for (int i = 0; i < 16; ++i) {
        answer[15 - i] = (std::get<0>(value) >> (15 - i)) & 1;
    }
    if (answer[47]) {
        answer = ~answer;
        int j = 0;
        while (answer[j]) {
            answer[j++] = 0;
        }
        answer[j] = 1;
        return -1ll * (answer.to_ullong());
    }
    return answer.to_ullong();
};

int64_t getTask1(int value) {
    int64_t res = 0;
    __asm {
            mov eax, value
            mov dword ptr res, eax
            imul value
            imul value
            add dword ptr res, eax
            add dword ptr res+4, edx
            imul value
            imul value
            add dword ptr res, eax
            add dword ptr res+4, edx
    }
    return res;
}

int getTask2(int value) {
    int res;
    __asm {
            mov eax, value
            mov res, eax
            sub res, 8
            imul value
            add res, eax
            add res, eax
            imul value
            imul value
            imul value
            add res, eax

            mov ecx, value
            imul ecx, value
            imul ecx, value

            mov eax, res
            cdq
            idiv ecx
            mov res, eax
    }
    return res;
}

int getTask3(int value) {
    int res = 0;
    __asm {
            xor edx, edx
            mov eax, 1
            beg:
            imul value
            jo end
            inc res
            jmp beg
            end:
    }
    return res;
}

std::tuple<uint16_t, uint16_t, int16_t> getTask4(const std::tuple<uint16_t, uint16_t, int16_t> &lhs,
                                                 const std::tuple<uint16_t, uint16_t, int16_t> &rhs) {

    uint16_t a1 = std::get<0>(lhs);
    uint16_t a2 = std::get<1>(lhs);
    int16_t a3 = std::get<2>(lhs);

    uint16_t b1 = std::get<0>(rhs);
    uint16_t b2 = std::get<1>(rhs);
    int16_t b3 = std::get<2>(rhs);

    uint16_t c1 = 0;
    uint16_t c2 = 0;
    int16_t c3 = 0;
    __asm {
            mov ax, a1
            add ax, b1
            mov c1, ax

            mov ax, a2
            adc ax, b2
            mov c2, ax

            mov ax, a3
            adc ax, b3
            mov c3, ax
    }
    std::cout << std::dec << funcTo48Bits(lhs) << " + " << funcTo48Bits(rhs) << " = " << funcTo48Bits({c1, c2, c3})
              << '\n';
    std::cout << std::hex << funcTo48Bits(lhs) << " + " << funcTo48Bits(rhs) << " = " << funcTo48Bits({c1, c2, c3})
              << '\n';
    return {c1, c2, c3};
}


TEST(Laba2, Task1) {
    auto func = [&](int64_t n) -> int64_t {
        return n * n * n * n * n + n * n * n + n;
    };
    EXPECT_EQ(getTask1(1), func(1));
    EXPECT_EQ(getTask1(10), func(10));
    EXPECT_EQ(getTask1(0), func(0));
    EXPECT_EQ(getTask1(100), func(100));
}

TEST(Laba2, Task2) {
    auto func = [&](int64_t a) -> int64_t {
        return (a * a * a * a * a + 2 * (a * a - 4) + a) / (a * a * a);
    };
    EXPECT_EQ(getTask2(1), func(1));
    EXPECT_EQ(getTask2(2), func(2));
    EXPECT_EQ(getTask2(-1), func(-1));
    EXPECT_EQ(getTask2(10), func(10));
    EXPECT_EQ(getTask2(-10), func(-10));
}

TEST(Laba2, Task3) {
    EXPECT_EQ(getTask3(2), 30);
    EXPECT_EQ(getTask3(-2), 31);
    EXPECT_EQ(getTask3(3), 19);
    EXPECT_EQ(getTask3(-3), 19);
    EXPECT_EQ(getTask3(6), 11);
}


TEST(Laba2, Task4) {
    EXPECT_EQ(funcTo48Bits(getTask4({0, 0, 1}, {0, 0, 1})), funcTo48Bits({0, 0, 1}) + funcTo48Bits({0, 0, 1}));
    EXPECT_EQ(funcTo48Bits(getTask4({0, 0, 0}, {0, 0, 0})), funcTo48Bits({0, 0, 0}) + funcTo48Bits({0, 0, 0}));
    EXPECT_EQ(funcTo48Bits(getTask4({0, 1, 1}, {0, 1, 1})), funcTo48Bits({0, 1, 1}) + funcTo48Bits({0, 1, 1}));
    EXPECT_EQ(funcTo48Bits(getTask4({0, 12, 21}, {0, 0, 123})), funcTo48Bits({0, 12, 21}) + funcTo48Bits({0, 0, 123}));
    EXPECT_EQ(funcTo48Bits(getTask4({(1 << 16) - 1, 0, 0}, {(1 << 16) - 1, 0, 0})),
              funcTo48Bits({(1 << 16) - 1, 0, 0}) + funcTo48Bits({(1 << 16) - 1, 0, 0}));
    EXPECT_EQ(funcTo48Bits(getTask4({-1, -1, -1}, {-1, -1, -1})),
              funcTo48Bits({-1, -1, -1}) + funcTo48Bits({-1, -1, -1}));
    EXPECT_EQ(funcTo48Bits(getTask4({-1, -1, -1}, {1, 0, 0})),
              funcTo48Bits({-1, -1, -1}) + funcTo48Bits({1, 0, 0}));
}
