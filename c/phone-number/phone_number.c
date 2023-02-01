#include "phone_number.h"

#define PHONE_STRING_LEN 10
#define LAST_DIGIT_INDEX(A) strlen(A) - 1;
#define INVALID_PHONE "0000000000"

static char* remove_non_digit_characters(const char *phone);
static char* set_result_to_invalid_phone();

char *phone_number_clean(const char *input)
{
    char* result = remove_non_digit_characters(input);
    
    // A valid phone number must have more than 9 digits
    if (strlen(result) < PHONE_STRING_LEN)
    {
        return set_result_to_invalid_phone(result);
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
            return set_result_to_invalid_phone(result);
        }
    }
    else if (strlen(result) > PHONE_STRING_LEN + 1)
    {
        return set_result_to_invalid_phone(result);
    }

    // A valid phone cannot have an area code thar starts with 0 or 1
    if (result[0] == '0' || result[0] == '1')
    {
        return set_result_to_invalid_phone(result);
    }

    // A valid phone cannot have an excange code thar starts with 0 or 1
    if (result[3] == '0' || result[3] == '1')
    {
        return set_result_to_invalid_phone(result);
    }

    return result;
}

static char* remove_non_digit_characters(const char *phone)
{
    size_t phone_len = strlen(phone);
    size_t result_len = 1;
    char *result = malloc(sizeof(char));

    for (size_t index = 0; index < phone_len; index++)
    {
        if (isdigit((unsigned char)(phone[index])))
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

static char* set_result_to_invalid_phone()
{
    char* result = malloc(sizeof(char) * PHONE_STRING_LEN + 1);

    if (!result)
    {
        errno = ENOMEM;
        exit(EXIT_FAILURE);
    }

    sprintf(result, "%s", INVALID_PHONE);

    return result;
}