#include "calculator.h"

#include <iostream>

int main()
{
    double num1 = 3;
    double num2 = 7;
    Calculator c;

    try
    {
        char op = '+';
        std::cout << num1 << " " << op << " " << num2 << " = " << c.calculate(num1, op, num2) << "\n";
        op = '-';
        std::cout << num1 << " " << op << " " << num2 << " = " << c.calculate(num1, op, num2) << "\n";
        op = '*';
        std::cout << num1 << " " << op << " " << num2 << " = " << c.calculate(num1, op, num2) << "\n";
        op = '/';
        std::cout << num1 << " " << op << " " << num2 << " = " << c.calculate(num1, op, num2) << "\n";
    }
    catch (calculate_error error)
    {
        switch (error)
        {
        case calculate_error::INVALID_OPERATOR:
            std::cout << "invalid operator!\n";
            break;
        case calculate_error::DIVISION_BY_ZERO:
            std::cout << "division by zero!\n";
            break;
        default:
            std::cout << "unknown error!\n";
            break;
        }
    }

}
