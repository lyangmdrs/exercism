#include "difference_of_squares.h"
#include <math.h>
unsigned int square_of_sum(unsigned int number)
{
    int sum = 0;
    for (unsigned int i = 1; i <= number; i++)
    {
        sum += i;
    }
    return pow(sum, 2);
}

unsigned int sum_of_squares(unsigned int number)
{
    int sum = 0;
    for (unsigned int i = 1; i <= number; i++)
    {
        sum += pow(i, 2);
    }
    return sum;
}

unsigned int difference_of_squares(unsigned int number)
{
    return square_of_sum(number) - sum_of_squares(number);
}
