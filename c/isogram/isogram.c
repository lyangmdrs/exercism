#include "isogram.h"
#include <stddef.h>
#include <ctype.h>

bool is_isogram(const char phrase[])
{
    if (phrase == NULL)
    {
        return false;
    }

    char c;
    int i = 0;
    
    do
    {
        c = phrase[i];

        if (check_char_repetition(phrase, c))
        {
            return false;
        }

        i++;

    } while (c != '\0');
    
    return true;
}

bool check_char_repetition(const char phrase[], char c)
{
    char a;
    int i = 0;
    int match = 0;
    do
    {
        a = tolower(phrase[i]);
        
        if (a == tolower(c))
        {
            if (a != '-')
            {
                match++;
            }
            if (match > 1)
            {
                return true;
            }
        }

        i++;
    } while (a != '\0');

    return false;
}