#include "nucleotide_count.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 256
#define INITIAL_RESULT "A:0 C:0 G:0 T:0"
#define RESULT_STR "A:%ld C:%ld G:%ld T:%ld"

char *count(const char *dna_strand)
{
    char *result = malloc(MAX_STR_LEN * sizeof(char));
    size_t a_nucleotide = 0, c_nucleotide = 0, g_nucleotide = 0, t_nucleotide = 0;

    if (!result)
    {
        return NULL;
    }

    strcpy(result, INITIAL_RESULT);

    if (dna_strand[0] == '\0')
    {
        return result;
    }

    for (size_t i = 0; i < strlen(dna_strand); i++)
    {
        switch (dna_strand[i])
        {
        case 'A':
            a_nucleotide++;
            break;
        case 'C':
            c_nucleotide++;
            break;
        case 'G':
            g_nucleotide++;
            break;
        case 'T':
            t_nucleotide++;
            break;
        default:
            result[0] = '\0';
            return result;
        }
    }

    
    sprintf(result, RESULT_STR, a_nucleotide, c_nucleotide, g_nucleotide, t_nucleotide);


    return result;

}