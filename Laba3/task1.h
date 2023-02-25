#pragma once

double getTask1(int, int);

double getTask1(int lhs, int rhs) {
    if (lhs == 0) {
        throw std::invalid_argument("Division by zero");
    }
    double res;
    __asm {
            finit
            fild lhs
            fild rhs
            fchs
            fdiv st(0), st(1)
            fstp res
    }
    return res;
}