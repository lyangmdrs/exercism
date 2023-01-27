#include "phone_number.h"

void prepend(char* string,  char sufix);

char *phone_number_clean(const char *input)
{
    if (strlen(input) <= PHONE_STRING_LEN)
    {
        char* invalid_input_result = malloc(sizeof(char) * PHONE_STRING_LEN);
        sprintf(invalid_input_result, "%s", "0000000000");
        return invalid_input_result;
    }

    if ((strlen(input) == PHONE_STRING_LEN + 1) && input[0] != '1')
    {
        char* invalid_input_result = malloc(sizeof(char) * PHONE_STRING_LEN);
        sprintf(invalid_input_result, "%s", "0000000000");
        return invalid_input_result;
    }
    
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