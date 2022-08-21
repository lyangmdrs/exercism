#include "hamming.h"

int compute(const char *lhs, const char *rhs)
{
    int position = 0;
    int errors = 0;

    do
    {
        if  (lhs[position] != rhs[position])
        {
            if ((lhs[position] == '\0') || (rhs[position] == '\0'))
            {
                return -1;
            }
            errors++;
        }
        position++;
    } while (lhs[position] != '\0');
    return errors;
}
