#include <iostream>

extern "C" int __fastcall Remainder(int,int);

int main()
{
    std::cout <<"remainder="<<Remainder(17, 9) << std::endl;
    return 0;
}