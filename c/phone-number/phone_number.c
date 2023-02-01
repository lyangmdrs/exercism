#include "phone_number.h"

char* remove_non_digit_characters(const char *phone);
void set_result_to_invalid_phone(char* result);

char *phone_number_clean(const char *input)
{
    char* result = remove_non_digit_characters(input);
    
    // A valid phone number must have more than 9 digits
    if (strlen(result) < PHONE_STRING_LEN)
    {
        set_result_to_invalid_phone(result);
        return result;
    }

    // A valid phone number with 11 digits must start with 1
    if (strlen(result) == PHONE_STRING_LEN + 1)
    {
        if (result[0] == '1')
        {
            memmove(result, result + 1, strlen(result));
        }
        else
        {
            set_result_to_invalid_phone(result);
            return result;
        }
    }
    else if (strlen(result) > PHONE_STRING_LEN + 1)
    {
        set_result_to_invalid_phone(result);
        return result;
    }

    // A valid phone cannot have an area code thar starts with 0 or 1
    if (result[0] == '0' || result[0] == '1')
    {
        set_result_to_invalid_phone(result);
        return result;
    }

    // A valid phone cannot have an excange code thar starts with 0 or 1
    if (result[3] == '0' || result[3] == '1')
    {
        set_result_to_invalid_phone(result);
        return result;
    }

    return result;
}

char* remove_non_digit_characters(const char *phone)
{
    size_t phone_len = strlen(phone);
    size_t result_len = 1;
    char *result = malloc(sizeof(char));

    for (size_t index = 0; index < phone_len; index++)
    {
        if (isdigit(phone[index]))
        {
            char *_result = realloc(result, (++result_len) * sizeof(char));

            if (!_result)
            {
                errno = ENOMEM;
                exit(EXIT_FAILURE);
            }

            result = _result;

            result[result_len - 2] = phone[index];
        }
    }

    // guarantees a null-terminated string
    result[result_len] = '\0';

    return result;
}

void set_result_to_invalid_phone(char* result)
{
    char *_result = realloc(result, sizeof(char) * PHONE_STRING_LEN + 1);

    if(!_result)
    {
        errno = ENOMEM;
        exit(EXIT_FAILURE);
    }

    sprintf(_result, "%s", INVALID_PHONE);

    result = _result;
}