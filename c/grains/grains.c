#include "grains.h"
#include <math.h>

uint64_t square(uint8_t index)
{
    if (index <= 0) return 0;
    if (index >= 65) return 0;
    return pow(2, index - 1);
}

uint64_t total(void)
{
    uint64_t sum = 0;

    for (int i = 0; i < 65; i++)
    {
        sum += square(i);
    }
    return sum;
}