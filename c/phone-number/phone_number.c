#include "phone_number.h"

void prepend(char* string,  char sufix);

char *phone_number_clean(const char *input)
{
    char* result = malloc(sizeof(char));

    sprintf(result, "%c", '\0');

    size_t index = LAST_DIGIT_INDEX(input);

    while (strlen(result) < PHONE_STRING_LEN)
    {   
        if (isdigit(input[index]))
        {
            prepend(result, input[index]);
        }
        
        index--;
    }

    return result;
}

void prepend(char* string,  char sufix)
{
    memmove(string + 1, string, strlen(string) + 1);
    string[0] = sufix;
}