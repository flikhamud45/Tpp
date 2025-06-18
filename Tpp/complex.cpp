#include <iostream>
#include "complex.h"


Complex::Complex(double a, double b) : m_real(a), m_imaginary(b)
{
    // left blank intentionally   
}

bool Complex::operator==(Complex num)
{
    return m_real == num.m_real && m_imaginary == num.m_imaginary;
}

double Complex::getImaginary()
{
    return m_imaginary;
}

double Complex::getReal()
{
    return m_real;
}

void Complex::setReal(double a)
{
    m_real = a;
}

void Complex::setImaginary(double b)
{
    m_imaginary = b;
}

Complex Complex::operator+(Complex num)
{
    return Complex(m_real + num.m_real, m_imaginary + num.m_imaginary);
}

Complex Complex::operator-(Complex num)
{
    return Complex(m_real - num.m_real, m_imaginary - num.m_imaginary);
}

Complex Complex::operator*(Complex num)
{
    return Complex((m_real * num.m_real) - (m_imaginary * num.m_imaginary), (m_real * num.m_imaginary + m_imaginary * num.m_real));
}

void Complex::print()
{
    std::cout << m_real << " + " << m_imaginary << "i\n";
}
