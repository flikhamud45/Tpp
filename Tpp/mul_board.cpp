#include "mul_board.h"
#include <iostream>


void print_mul_board()
{
    // print the mul board

    // print the header
    for (int i = MIN_MUL; i <= MAX_MUL; i++)
    {
        std::cout << SEP << i;
    }
    std::cout << "\n";

    // print the actual board
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
