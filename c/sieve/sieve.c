#include "sieve.h"

void remove_zero_items(uint32_t arr[], int n);

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{   
    uint32_t count = 0;
    // memset(primes, 0, limit + 2);

    printf("Start: \n");
    
    for (uint32_t i = 0; i < limit + 2; i++)
    {
        printf("primes[%d] = %d\n", i, primes[i]);
    }

    if (limit < 2)
    {
       return count;
    }

    if (limit > max_primes)
    {
        return count;
    }
    
    primes[0] = 0;
    primes[1] = 0;

    for (size_t i = 2; i <= limit; ++i)
    {
        primes[i] = i;
    }

    remove_zero_items(primes, limit +  2);

    printf("End: \n");
    
    for (uint32_t i = 0; i < limit + 2; i++)
    {
        printf("primes[%d] = %d\n", i, primes[i]);
    }

    printf("\n");

    for (size_t i = 0; i < limit; ++i)
    {
        
        if (primes[i] > 0)
        {
            count++;
        }
    }
    printf("count: %d\n", count);
    return count; 
}

void remove_zero_items(uint32_t arr[], int n)
{ 
    int i, j; 
    for (i=0; i<n; i++) 
    { 
        if (arr[i] == 0) 
        { 
            for (j=i; j<n-1; j++) 
                arr[j] = arr[j+1]; 
            n--; 
            i--; 
        } 
    } 
}