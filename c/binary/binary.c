#include "binary.h"

#include <string.h>
#include <math.h>

int convert(const char *input)
{
    size_t input_len = strlen(input);
    
    int result = 0;

    for (size_t i = 0; i < input_len; i++)
    {
        if ((input[i] > '1') || (input[i] < '0'))
        {
            return INVALID;
        }

        if(input[i] == '1')
        {
            result += pow(2, input_len - i - 1);
        }
    }

    return result;
    
}
