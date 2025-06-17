#include "calculator.h"

double Calculator::add(double num1, double num2)
{
    return num1 + num2;
}

double Calculator::subtract(double num1, double num2)
{
    return num1 - num2;
}

double Calculator::divide(double num1, double num2)
{
    if (num2 == 0)
    {
        throw calculate_error::DIVISION_BY_ZERO;
    }
    return num1 / num2;
}

double Calculator::multiply(double num1, double num2)
{
    return num1 * num2;
}

double Calculator::calculate(double num1, char op, double num2)
{
    switch (op)
    {
    case '+':
        return add(num1, num2);
        break;
    case '-':
        return subtract(num1, num2);
        break;
    case '*':
        return multiply(num1, num2);
        break;
    case '/':
        return divide(num1, num2);
        break;
    default:
        throw calculate_error::INVALID_OPERATOR;
    }
}

