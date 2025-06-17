#include "primes.h"

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
