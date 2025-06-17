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

    double get_real();

    double get_imaginary();

    void set_real(double a);

    void set_imaginary(double b);

    // print the number
    void print();

private:
    double real;
    double imaginary;
    
};
