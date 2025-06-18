#pragma once
#include <iostream>
#include "string.h"

int main()
{
    String s1 = "hello";
    std::cout << s1 << " world!\n";
    std::cout << s1 + " world!\n";
    String s2 = " world!\n";
    std::cout << s1 + s2;
    std::cout << (s1 == s2) << "\n";
    s2 = "hello";
    std::cout << (s1 == s2) << "\n";

    return 0;
}
