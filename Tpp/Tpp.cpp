#pragma once
#include <iostream>
#include "string.h"

int main()
{
    String s1 = "hello";
    std::cout << s1 << " world!\n";
    std::cout << s1 + " world!\n";

    return 0;
}
