#include <iostream>
#include "complex.h"

Complex::Complex() : Complex(0, 0)
{
    // left blank intentionally
}

Complex::Complex(double a, double b) : real(a), imaginary(b)
{
    // left blank intentionally   
}

bool Complex::operator==(Complex num)
{
    return real == num.real && imaginary == num.imaginary;
}

double Complex::getImaginary()
{
    return imaginary;
}

double Complex::getReal()
{
    return real;
}

void Complex::setReal(double a)
{
    real = a;
}

void Complex::setImaginary(double b)
{
    imaginary = b;
}

Complex Complex::operator+(Complex num)
{
    return Complex(real + num.real, imaginary + num.imaginary);
}

Complex Complex::operator-(Complex num)
{
    return Complex(real - num.real, imaginary - num.imaginary);
}

Complex Complex::operator*(Complex num)
{
    return Complex((real * num.real) - (imaginary * num.imaginary), (real * num.imaginary + imaginary * num.real));
}

void Complex::print()
{
    std::cout << real << " + " << imaginary << "i\n";
}
