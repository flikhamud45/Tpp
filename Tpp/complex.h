#include <string>

class Complex
{
public:

    // init to 0
    Complex();

    // init to a + bi
    Complex(double a, double b);

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
