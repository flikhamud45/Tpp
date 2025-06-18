#include <iostream>
#include "complex.h"

int main()
{
    Complex n1 = Complex();
    Complex n2 = Complex(1, 2);

    (n1 + n2).print();

    n1 = Complex(3, 4);

    (n1 + n2).print();
    (n1 - n2).print();
    (n1 * n2).print();
    

    return 0;
}
