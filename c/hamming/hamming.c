#include "hamming.h"

int compute(const char *lhs, const char *rhs)
{
    int position = 0;
    int errors = 0;

    do
    {
        if  (lhs[position] != rhs[position])
        {
            errors++;
        }
        position++;
    } while (lhs[position] != '\0');
    return errors;
}
