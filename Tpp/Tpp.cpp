// Tpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define MIN_MUL 1
#define MAX_MUL 11
#define SEP "\t"

int main()
{
    for (int i = MIN_MUL; i <= MAX_MUL; i++)
    {
        std::cout << SEP << i;
    }
    std::cout << "\n";

    for (int i = MIN_MUL; i <= MAX_MUL; i++)
    {
        std::cout << i << SEP;
        for (int j = MIN_MUL; j <= MAX_MUL; j++)
        {
            std::cout << i * j << SEP;
        }
        std::cout << "\n";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files
//   to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
