#pragma once
#include "primes.h"
#include <iostream>

const int NUMBER_OF_PRIMES = 10;

int main()
{
    int arr[NUMBER_OF_PRIMES];
    get_primes_arr(arr, NUMBER_OF_PRIMES);
    for (int i = 0; i < NUMBER_OF_PRIMES; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "\n";
}
