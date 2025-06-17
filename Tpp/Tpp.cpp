// Tpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

const int MIN_MUL = 1;
const int MAX_MUL = 11;
const char* SEP = "\t";

void print_headline()
{
    for (int i = MIN_MUL; i <= MAX_MUL; i++)
    {
        std::cout << SEP << i;
    }
    std::cout << "\n";
}

void print_mul_board()
{
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

int main()
{
    print_headline();
    print_mul_board();

}
