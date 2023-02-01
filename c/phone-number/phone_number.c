#include "phone_number.h"

#define PHONE_STRING_LEN 13
#define CLEANED_PHONE_STRING_LEN 10
#define INVALID_PHONE "0000000000"

static void remove_non_digit_characters(const char *phone, char* result);
static void set_result_to_invalid_phone(char* result);

char *phone_number_clean(const char *input)
{
    char* result = malloc(sizeof(char) * PHONE_STRING_LEN);

    if (!result)
    {
        errno = ENOMEM;
        exit(EXIT_FAILURE);
    }

    remove_non_digit_characters(input, result);
    
    // A valid phone number must have more than 9 digits
    if (strlen(result) < CLEANED_PHONE_STRING_LEN)
    {
        set_result_to_invalid_phone(result);
        return result;
    }

    // A valid phone number with 11 digits must start with 1
    if (strlen(result) == CLEANED_PHONE_STRING_LEN + 1)
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
    else if (strlen(result) > CLEANED_PHONE_STRING_LEN + 1)
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

static void remove_non_digit_characters(const char *phone, char* result)
{
    size_t phone_len = strlen(phone);
    size_t result_len = 0;

    for (size_t index = 0; index < phone_len; index++)
    {
        if (isdigit((unsigned char)(phone[index])))
        {
            result[result_len] = phone[index];
            result_len++;
        }
    }

    // guarantees a null-terminated string
    result[result_len] = '\0';
}

static void set_result_to_invalid_phone(char* result)
{
    sprintf(result, "%s", INVALID_PHONE);
}