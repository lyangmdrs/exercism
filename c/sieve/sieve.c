#include "sieve.h"

void remove_zero_items(uint32_t arr[], int n);

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{   
    uint32_t count = 0;

    if (limit < 2)
    {
       return count;
    }

    uint32_t non_primes[200] = { 0 };
    uint32_t index = 2;
    
    for (uint32_t multiplier_1 = 2; multiplier_1 <= limit; multiplier_1++)
    {
        for (uint32_t multiplier_2 = 2; multiplier_2 <= limit; multiplier_2++)
        {
            // printf("index=%d, multipliers(%d, %d), result=%d\n", index, multiplier_1, multiplier_2, multiplier_1*multiplier_2);
            non_primes[index++] = multiplier_1 * multiplier_2;
        }
    }

    // printf("\nView non-primes\n");
    for (index = 2; non_primes[index]; index++)
    {
        // printf("non_primes[%d] = %d\n", index, non_primes[index]);
        
        if (non_primes[index] == 0)
        {
            break;
        }
    }

    bool found_prime = true;
    for (uint32_t number = 2; number <= limit; number++)
    {
        found_prime = true;
        for (index = 2; index < 200; index++)
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
        
        // printf("test %d\n", found_prime);
        if (found_prime)
        {
            // printf("Found prime %d \n", number);
            primes[count++] = number;
        }
    }

    // printf("\nView primes\n");
    for (uint32_t number = 0; number <= limit * 2; number++)
    {
        // printf("primes[%d] = %d\n", number, primes[number]);
    }

    if (count > max_primes)
    {
        return max_primes;
    }


    return count; 
}
