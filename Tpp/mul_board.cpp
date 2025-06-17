#include "mul_board.h"
#include <iostream>


void print_mul_board()
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
