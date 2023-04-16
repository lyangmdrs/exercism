#include "matching_brackets.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>


static char get_bracket_pair(char bracket)
{
    switch (bracket)
    {
    case '(':
        return ')';
    case '[':
        return ']';
    case '{':
        return '}';
    default:
        return '\0';
    }
}

static void look_for_closing_brackets(const char *input, size_t input_len, char required_bracket, char *matching_indexes)
{
    printf("received: input_len: %ld - required_bracket: %c\n", input_len, required_bracket);
    for (size_t i = 0; i < input_len; i++)
    {
        if (input[i] != required_bracket) continue;

        char index_char = '0' + i;

        if (strchr(matching_indexes, index_char)) continue;

        printf("found a closing bracket '%c' on position %ld\n", input[i], i);
        strncat(matching_indexes, &index_char, 1);
        break;
    }
}

static void look_for_matching_brackets(const char *input, size_t input_len, char *opening_indexes, char *matching_indexes)
{
    char *opening_brackets = "([{";
    
    for (size_t i = 0; i < input_len; i++)
    {
        if (strchr(opening_brackets, input[i]))
        {
            char index_char = '0' + i;
            printf("found! %c in %ld\n", input[i], i);
            strncat(opening_indexes, &index_char, 1);

            // Look for bracket match
            look_for_closing_brackets(input, input_len, get_bracket_pair(input[i]), matching_indexes);
        }
    }


}

static size_t count_brackets(const char *input, size_t input_len)
{
    size_t num_brackets = 0;
    char *brackets = "([{}])";
    
    for (size_t i = 0; i < input_len; i++)
        if (strchr(brackets, input[i])) num_brackets++;

    return num_brackets;
}

bool is_paired(const char *input)
{
    printf("Input: '%s'\n", input);
    
    if (input[0] == '\0')
    {
        return true;
    }

    size_t input_len = strlen(input);
    char *opening_indexes = malloc(sizeof(char) * 50);

    if (!opening_indexes)
    {
        return false;
    }

    char *matching_indexes = malloc(sizeof(char) * 50);
    
    if (!matching_indexes)
    {
        free(opening_indexes);
        return false;
    }

    opening_indexes[0] = '\0';
    matching_indexes[0] = '\0';

    look_for_matching_brackets(input, input_len, opening_indexes, matching_indexes);

    printf("Opening Indexes: '%s'\n", opening_indexes);
    printf("Matching Indexes: '%s'\n", matching_indexes);    
    
    size_t opening_indexes_len = strlen(opening_indexes);
    size_t matching_indexes_len = strlen(matching_indexes);
    
    if (count_brackets(input, input_len) != (opening_indexes_len + matching_indexes_len))
    {
        free(opening_indexes);
        free(matching_indexes);
        return false;
    }

    if (opening_indexes_len != matching_indexes_len)
    {
        free(opening_indexes);
        free(matching_indexes);
        return false;
    }

    for (size_t i = 0; i < opening_indexes_len; i++)
    {
        if (opening_indexes[i] > matching_indexes[i])
        {
            free(opening_indexes);
            free(matching_indexes);
            return false;
        }
    }

    free(opening_indexes);
    free(matching_indexes);

    return true;
}