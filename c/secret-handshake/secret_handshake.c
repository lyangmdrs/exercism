#include "secret_handshake.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_SIGNALS 4

/*
SIGNALS CODE
00001 = wink
00010 = double blink
00100 = close your eyes
01000 = jump
10000 = Reverse the order of the operations in the secret handshake.
*/

static const char *signals[] = {"wink", "double blink", "close your eyes", "jump"};

const char **commands(size_t number)
{
    const char **result = calloc(NUM_SIGNALS, sizeof(char*));

    if (!result)
    {
        return NULL;
    }

    size_t result_index = 0;
    size_t reverse = number & 16;
    int start = (reverse ? (NUM_SIGNALS - 1) : 0);
    int end = (reverse ? 0 : NUM_SIGNALS);

    for (int i = start; reverse ? (i >= end) : (i < end); reverse ? (i--) : (i++))
    {
        if (number & (int)pow(2, i))
        {
            result[result_index++] = signals[i];
        }
    }
    
    return result;
}