#include "calculator.h"

#include <iostream>

int main()
{
    double num1 = 3;
    double num2 = 7;
    Calculator c;

    char op = '+';
    std::cout << num1 << " " << op << " " << num2 << " = " << c.calculate(num1, op, num2) << "\n";
    op = '-';
    std::cout << num1 << " " << op << " " << num2 << " = " << c.calculate(num1, op, num2) << "\n";
    op = '*';
    std::cout << num1 << " " << op << " " << num2 << " = " << c.calculate(num1, op, num2) << "\n";
    op = '/';
    std::cout << num1 << " " << op << " " << num2 << " = " << c.calculate(num1, op, num2) << "\n";


}
