#include "rail_fence_cipher.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_STRING_LENGTH 50

char *encode(char *text, size_t rails)
{
    char **ciphers = malloc(sizeof(char*) * rails);

    if (!ciphers)
    {
        return NULL;
    }

    for (size_t i = 0; i < rails; i++)
    {
        ciphers[i] = malloc(sizeof(char) * MAX_STRING_LENGTH);

        if (!ciphers[i])
        {
            return NULL;
        }

        memset(ciphers[i], '\0', MAX_STRING_LENGTH);
    }
    
    char * result = malloc(sizeof(char) * MAX_STRING_LENGTH);
    
    if (!result)
    {
        return NULL;
    }

    memset(result, '\0', MAX_STRING_LENGTH);
    
    int signal = 1;
    size_t cipher_index = 0;
    for (size_t i = 0; text[i]; i++)
    {
        // printf("Signal %2d || Index: %ld || i: %ld\n", signal, cipher_index, i);
        strncat(ciphers[cipher_index], &text[i], 1);
        if ((cipher_index == (rails - 1)) || ((!cipher_index) && (signal < 0)))
        {
            signal *= -1;
        }

        cipher_index += signal;
    }

    
    for (int i = 0; i < (int)rails; i++)
    {
        // printf("C(%d): %s\n", i, ciphers[i]);
        strcat(result, ciphers[i]);
        free(ciphers[i]);
    }

    free(ciphers);

    return result;
}

char *decode(char *ciphertext, size_t rails)
{
    if (rails) {}
    return ciphertext;
}