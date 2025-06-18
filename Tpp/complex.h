#pragma once

class Complex
{
public:

    // init to a + bi
    Complex(double a = 0, double b = 0) ;

    bool operator==(Complex num);

    Complex operator+(Complex num);

    Complex operator-(Complex num);

    Complex operator*(Complex num);

    double getReal();

    double getImaginary();

    void setReal(double a);

    void setImaginary(double b);

    // print the number
    void print();

private:
    double m_real;
    double m_imaginary;
    
};
