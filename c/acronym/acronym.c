#include "acronym.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ABBR_LEN 10

char *abbreviate(const char *phrase)
{
    if (!phrase || (strcmp(phrase, "") == 0))
    {
        return NULL;
    }
    
    char *result = malloc(ABBR_LEN * sizeof(char));
    size_t res_len = 0;

    for (size_t i = 0; phrase[i]; i++)
    {
        if(i == 0)
        {
            result[res_len++] = phrase[i];
        } else if (strrchr("- ", phrase[i - 1]))
        {
            result[res_len++] = toupper(phrase[i]);
        }
    }

    result[res_len] = '\0';
    

    return result;
}