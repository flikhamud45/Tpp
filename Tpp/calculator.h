class Calculator
{
public:
    // return the sum of num1 and num2
    double add(double num1, double num2);

    // return the subtract of num1 and num2
    double subtract(double num1, double num2);

    // return the product of num1 and num2
    double multiply(double num1, double num2);

    // return the division of num1 and num2
    double divide(double num1, double num2);

    // return num1 opp num2 for opp = "*", "/", "+", "-"
    double calculate(double num1, char op, double num2);
};


enum calculate_error
{
    divission_by_zero,
    invalid_operator
};