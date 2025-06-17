#include "complex.h"
#include <iostream>

Complex::Complex() : Complex(0, 0)
{
    
}



Complex::Complex(double a, double b) : real(a), imaginary(b)
{
    
}

bool Complex::operator==(Complex num)
{
    return real == num.real && imaginary == num.imaginary;
}

double Complex::get_imaginary()
{
    return imaginary;
}

double Complex::get_real()
{
    return real;
}

void Complex::set_real(double a)
{
    real = a;
}

void Complex::set_imaginary(double b)
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
