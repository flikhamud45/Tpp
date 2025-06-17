enum calculate_error
{
    DIVISION_BY_ZERO,
    INVALID_OPERATOR
};

class Calculator
{
private:
    // return the sum of num1 and num2
    double add(double num1, double num2);

    // return the subtract of num1 and num2
    double subtract(double num1, double num2);

    // return the product of num1 and num2
    double multiply(double num1, double num2);

    // return the division of num1 and num2
    double divide(double num1, double num2);

public:
    // return num1 opp num2 for opp = "*", "/", "+", "-"
    double calculate(double num1, char op, double num2);
};


