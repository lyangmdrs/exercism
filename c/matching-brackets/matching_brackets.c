#include "matching_brackets.h"
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

static void extract_characters(char *output, const char *input, const char *characters)
{
    size_t input_len = strlen(input); //TODO: Optimize this approach;
    size_t output_len = 0;
    
    for (size_t i = 0; i < input_len; i++)
    {
        if(strchr(characters, input[i]))
        {
            output[output_len++] = input[i];
        }
    }

    output[output_len] = '\0';

    if (output && input && characters) {}
}

static void get_opening_brackets(char *output, const char *input)
{
    extract_characters(output, input, "{[(");
}

static void get_closing_brackets(char *output, const char *input)
{
    extract_characters(output, input, ")]}");   
}

bool is_paired(const char *input)
{
    if (input[0] == '\0')
    {
        return true;
    }

    size_t input_length = strlen(input) + 1;
    char *opening_brackets = malloc(sizeof(char) * input_length);

    if (!opening_brackets)
    {
        return false;
    }
    
    char *closing_brackets = malloc(sizeof(char) * input_length);

    if (!closing_brackets)
    {
        free(opening_brackets);
        return false;
    }

    get_opening_brackets(opening_brackets, input);
    get_closing_brackets(closing_brackets, input);

    printf("opening_brackets string content: '%s'\n", opening_brackets);
    printf("closing_brackets string content: '%s'\n", closing_brackets);

    if (strlen(opening_brackets) != strlen(closing_brackets))
    {
        free(opening_brackets);
        free(closing_brackets);
        return false;
    }

    free(opening_brackets);
    free(closing_brackets);

    return true;
}