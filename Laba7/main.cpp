#include <iostream>

extern "C" int __fastcall Remainder(int,int);

int main()
{
    std::cout <<"remainder="<<Remainder(-12,5) << std::endl;
    return 0;
}