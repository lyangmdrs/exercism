#include "acronym.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ABBR_LEN 10
#define STR_TOKENS ("- _")

static void expand_string(char *str, size_t len)
{
    str = realloc(str, (len + ABBR_LEN) * sizeof(char));
}

char *abbreviate(const char *phrase)
{
    if (!phrase || (strcmp(phrase, "") == 0))
    {
        return NULL;
    }
    
    char *result = malloc(ABBR_LEN * sizeof(char));
    size_t res_len = 0;
    size_t tam = ABBR_LEN;

    for (size_t i = 0; phrase[i]; i++)
    {
        if(i == 0)
        {
            result[res_len++] = phrase[i];
        } else if ((strrchr(STR_TOKENS, phrase[i - 1])) && isalpha(phrase[i]))
        {
            result[res_len++] = toupper(phrase[i]);
        }

        if ((res_len + 1) == tam)
        {
            result[res_len] = '\0';
            expand_string(result, res_len);
            tam += res_len;
        }
    }

    result[res_len] = '\0';
    
    return result;
}