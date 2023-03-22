#include <bitset>
#include "gtest/gtest.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

auto console = spdlog::stderr_color_mt("console");

void getTask1(int array[]) {
    __asm {
        lea ebx, array
        mov ecx, LENGTH array
        jecx end
        begin:


        end:
    }
}

TEST(Laba4, Task1) {
    
}

TEST(Laba4, Task2) {
    
}

TEST(Laba4, Task3) {
    
}


TEST(Laba4, Task4) {
    
}
