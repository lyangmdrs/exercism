#include "phone_number.h"

#define MAX_PHONE_STRING_LEN 13
#define CLEANED_PHONE_STRING_LEN 10
#define INVALID_PHONE "0000000000"

static bool phone_validation(const char* phone);
static void remove_non_digit_characters(const char *phone, char* result);
static void remove_area_code(char* phone);
static void set_result_to_invalid_phone(char* result);

char *phone_number_clean(const char *input)
{
    char* result = malloc(sizeof(char) * MAX_PHONE_STRING_LEN);

    if (!result)
    {
        return NULL;
    }

    remove_non_digit_characters(input, result);
    remove_area_code(result);
    
    if (!phone_validation(result))
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

    result[result_len] = '\0';
}

static void remove_area_code(char* phone)
{
    size_t phone_len = strlen(phone);
    
    if ((phone_len == CLEANED_PHONE_STRING_LEN + 1) && (phone[0] == '1'))
    {
        memmove(phone, phone + 1, phone_len);
    }
}

static void set_result_to_invalid_phone(char* result)
{
    strcpy(result, INVALID_PHONE);
}

static bool phone_validation(const char* phone)
{
    int area_code_index = 0;
    int exchange_code_index = 3;
    size_t phone_len = strlen(phone);

    // A valid phone number must have more than 9 digits
    if (phone_len < CLEANED_PHONE_STRING_LEN)
    {
        return false;
    }
    // A valid phone number with 11 digits must start with 1
    else if ((phone_len == CLEANED_PHONE_STRING_LEN + 1) && (phone[0] != '1'))
    {
        return false;
    }
    // A valid phone number must have less than 11 digits
    else if (phone_len > CLEANED_PHONE_STRING_LEN + 1)
    {
        return false;
    }
    
    // A valid phone cannot have 0 or 1 as area code
    if (phone[area_code_index] <= '1')
    {
        return false;
    }

    // A valid phone cannot have 0 or 1 as exchange code
    if (phone[exchange_code_index] <= '1')
    {
        return false;
    }

    return true;
}
