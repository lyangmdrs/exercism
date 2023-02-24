#include "sieve.h"

#define INITIAL_INDEX 2
#define MAX_NON_PRIMES 29003

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{   
    uint32_t count = 0;

    if (limit < INITIAL_INDEX)
    {
       return count;
    }

    uint32_t non_primes[MAX_NON_PRIMES] = { 0 };
    uint32_t index = INITIAL_INDEX;
    
    for (uint32_t multiplier_1 = INITIAL_INDEX; multiplier_1 <= limit; multiplier_1++)
    {
        for (uint32_t multiplier_2 = INITIAL_INDEX; multiplier_2 <= limit; multiplier_2++)
        {
            non_primes[index++] = multiplier_1 * multiplier_2;
            
            if (index == MAX_NON_PRIMES)
            {
                break;
            }
        }
        
        if (index == MAX_NON_PRIMES)
        {
            break;
        }
    }

    bool found_prime = true;
    for (uint32_t number = INITIAL_INDEX; number <= limit; number++)
    {
        found_prime = true;
        for (index = INITIAL_INDEX; index < MAX_NON_PRIMES; index++)
        {
            if (non_primes[index] == number)
            {
                found_prime = false;
                break;
            }

            if (non_primes[index] == 0)
            {
                break;
            }
        }
        
        if (found_prime)
        {
            primes[count++] = number;
        }
    }

    if (count > max_primes)
    {
        return max_primes;
    }

    return count; 
}
