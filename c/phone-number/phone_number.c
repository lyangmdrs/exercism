#include "phone_number.h"

void prepend(char* string,  char sufix);
char* set_result_to_invalid_phone(char* result);

char *phone_number_clean(const char *input)
{
    char* result = malloc(sizeof(char));
    
    // A valid phone number must have more than 9 digits
    if (strlen(input) < PHONE_STRING_LEN)
    {
        result = set_result_to_invalid_phone(result);
        return result;
    }

    // A valid phone number with 11 digits must start with 1
    if ((strlen(input) == PHONE_STRING_LEN + 1) && input[0] != '1')
    {
        result = set_result_to_invalid_phone(result);
        return result;
    }
    
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

char* set_result_to_invalid_phone(char* result)
{
    char* _result = realloc(result, sizeof(char) * PHONE_STRING_LEN + 1);

    if(!_result)
    {
        errno = ENOMEM;
        exit(EXIT_FAILURE);
    }

    sprintf(_result, "%s", INVALID_PHONE);

    return _result;
}