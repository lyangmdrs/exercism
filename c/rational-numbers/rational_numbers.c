#include "rational_numbers.h"

rational_t add(rational_t r1, rational_t r2)
{
    rational_t sum;
    sum.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;

    if (sum.numerator == 0)
    {
        sum.denominator = 1;
    }
    else
    {
        sum.denominator = r1.denominator * r2.denominator;
    }

    return sum;
}

rational_t subtract(rational_t r1, rational_t r2)
{
    rational_t sub;
    sub.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    
    if (sub.numerator == 0)
    {
        sub.denominator = 1;
    }
    else
    {
        sub.denominator = r1.denominator * r2.denominator;
    }

    return sub;
}
