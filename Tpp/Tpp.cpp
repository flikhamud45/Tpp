// Tpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool is_prime(int num)
{
    for (int i = 2; i <= std::sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void get_primes(int arr[], int num_of_primes)
{
    int i = 0;
    int current_num = 1;
    while (i < num_of_primes)
    {
        if (is_prime(current_num))
        {
            arr[i] = current_num;
            i++;
        }
        current_num++;
    }
}


int main()
{
    int arr[10];
    get_primes(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
