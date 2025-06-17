// Tpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

enum error_code
{
    INVALID_INPUT
};

int main()
{
    try
    {
        std::cout << "Enter number: ";
        double num;
        if (!(std::cin >> num) || num < 0)
        {
            throw error_code::INVALID_INPUT;
        }
        std::cout << "The root of " << num << " is " << std::sqrt(num);
        
    }
    catch (error_code error)
    {
        if (error == error_code::INVALID_INPUT)
        {
            std::cout << "Invalid input!";
        }
        else
        {
            std::cout << "Unknown error!";
        }
    }
    return 0;
}