#include "rational_numbers.h"

int greatest_common_divisor(rational_t r)
{
    for (int i = MAX_GCD_VALUE; i > 0; i--)
    {
        if (((r.numerator % i) == 0) && ((r.denominator % i) == 0))
        {
            return i;
        }
    }

    return 20;
}

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

rational_t multiply(rational_t r1, rational_t r2)
{
    rational_t product;
    
    product.numerator = (r1.numerator * r2.numerator);
    product.denominator = r1.denominator * r2.denominator;

    int gcd = greatest_common_divisor(product);
    product.numerator /= gcd;
    product.denominator /= gcd;
    
    return product;
}

rational_t divide(rational_t r1, rational_t r2)
{
    rational_t result;
    
    if (r2.numerator == 0)
    {
        result.numerator = 0;
        result.denominator = 0;
        return result;
    }

    result.numerator = r1.numerator * r2.denominator;
    result.denominator = r2.numerator * r1.denominator;
    
    int gcd = greatest_common_divisor(result);
    result.numerator /= gcd;
    result.denominator /= gcd;

    if ((result.denominator < 0))
    {
        result.denominator *= -1;
        if (result.numerator > 0)
        {
            result.numerator *= -1;
        }
    }

    if ((r1.numerator < 0) && (r2.numerator < 0) && (result.numerator < 0))
    {
        result.numerator *= -1;
    }

    return result;
}

rational_t absolute(rational_t r)
{
    rational_t result = r;

    int gcd = greatest_common_divisor(result);

    result.numerator /= gcd;
    result.denominator /= gcd;
    
    if (result.numerator < 0)
    {
        result.numerator *= -1;
    }

    if (result.denominator < 0)
    {
        result.denominator *= -1;
    }
    
    return result;
}
