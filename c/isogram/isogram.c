#include "isogram.h"

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
        i++;
    } while (c != '\0');
    
    return true;
}