#include "secret_handshake.h"
#include <stdlib.h>
#include <string.h>

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
    const char **result = malloc(NUM_SIGNALS * sizeof(char*));

    if (!result)
    {
        return NULL;
    }

    size_t result_index = 0;
    for (size_t i = 0; i < NUM_SIGNALS; i++)
    {
        if (number & 1)
        {
            result[result_index++] = signals[0];
            continue;
        }
        if (number & 2)
        {
            result[result_index++] = signals[1];
            continue;
        }
        if (number & 4)
        {
            result[result_index++] = signals[2];
            continue;
        }
        if (number & 8)
        {
            result[result_index++] = signals[3];
            continue;
        }
    }
    
    return result;
}