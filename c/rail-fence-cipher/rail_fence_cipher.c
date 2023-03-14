#include "rail_fence_cipher.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
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
        printf("C(%d): %s || Length: %ld\n", i, ciphers[i], strlen(ciphers[i]));
        strcat(result, ciphers[i]);
        free(ciphers[i]);
    }

    free(ciphers);

    return result;
}

char *decode(char *ciphertext, size_t rails)
{
    if (rails) {}
    // size_t cipher_len = strlen(ciphertext);
    size_t cipher_len = 25;
    size_t top_rail_len = (size_t)ceil(((float)cipher_len)/4);
    size_t middle_rail_len = cipher_len/2;
    size_t bottom_rail_len = cipher_len/4;
    printf("DIVISIONS\n");
    printf("\tTop rail length: %ld\n", top_rail_len);
    printf("\tMiddle rail length: %ld\n", middle_rail_len);
    printf("\tBottom rail length: %ld\n", bottom_rail_len);
    printf("==========\n");
    size_t length1 = 6;
    size_t top = (size_t)ceil(((float)length1)/4);
    size_t middle1 = length1/2;
    size_t middle2 = length1/2;
    size_t bottom = length1/4;
    printf("\tTop rail length: %ld\n", top);
    printf("\tMiddle rail 1 length: %ld\n", middle1);
    printf("\tMiddle rail 2 length: %ld\n", middle2);
    printf("\tBottom rail length: %ld\n", bottom);

    return ciphertext;
}