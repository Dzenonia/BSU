#include <iostream>

extern "C" int __fastcall checkPalindrom(int,const char*);

/// 10101000
// 101010111
//     11000
int main()
{
    const char* ans = "aba";
    std::cout << checkPalindrom(3, ans) << std::endl;
    return 0;
}