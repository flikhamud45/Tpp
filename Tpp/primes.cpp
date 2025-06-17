#include "primes.h"

#include <regex>

bool is_prime(int num)
{
    // return if the given number is prime
    if (num <= 1)
    {
        return false;
    }

    // we just go until sqrt(num) since if we didnt find any factor until the sqrt we will never find (because of
    // symetry)
    for (int i = 2; i <= std::sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void get_primes_arr(int arr[], int num_of_primes)
{
    if (arr == nullptr)
    {
        throw error_type::INVALID_POINTER;
    }
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
