#include "rna_transcription.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 256
#define INITIAL_RESULT "A:0 C:0 G:0 T:0"
#define RESULT_STR "A:%ld C:%ld G:%ld T:%ld"

char *to_rna(const char *dna)
{
    char *result = malloc(MAX_STR_LEN * sizeof(char));

    if (!result)
    {
        return NULL;
    }

    result[0] = '\0';

    if (dna[0] == '\0')
    {
        return result;
    }

    for (size_t i = 0; i < strlen(dna); i++)
    {
        switch (dna[i])
        {
        case 'A':
            strcat(result, "U");
            break;
        case 'C':
            strcat(result, "G");
            break;
        case 'G':
            strcat(result, "C");
            break;
        case 'T':
            strcat(result, "A");
            break;
        default:
            result[0] = '\0';
            return result;
        }
    }

    return result;
}