#include "rational_numbers.h"

rational_t add(rational_t r1, rational_t r2)
{
    rational_t sum;
    sum.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    sum.denominator = r1.denominator * r2.denominator;
    return sum;
}
