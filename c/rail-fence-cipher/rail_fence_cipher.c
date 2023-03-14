#include "rail_fence_cipher.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_STRING_LENGTH 50

char *encode(char *text, size_t rails)
{
    char *cipher1 = malloc(sizeof(char) * MAX_STRING_LENGTH);

    if (!cipher1)
    {
        return NULL;
    }

    char *cipher2 = malloc(sizeof(char) * MAX_STRING_LENGTH);

    if (!cipher2)
    {
        return NULL;
    }
    
    char * result = malloc(sizeof(char) * MAX_STRING_LENGTH);
    
    if (!result)
    {
        return NULL;
    }

    memset(cipher1, '\0', MAX_STRING_LENGTH);
    memset(cipher2, '\0', MAX_STRING_LENGTH);
    
    for (size_t i = 0; text[i]; i++)
    {
        if (i%rails)
        {
            strncat(cipher2, &text[i], 1);
        }
        else 
        {
            strncat(cipher1, &text[i], 1);
        }
    }

    strcpy(result, cipher1);
    strcat(result, cipher2);

    free(cipher1);
    free(cipher2);

    return result;
}

char *decode(char *ciphertext, size_t rails)
{
    if (rails) {}
    return ciphertext;
}