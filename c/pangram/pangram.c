#include "pangram.h"

#include <string.h>
bool is_pangram(const char *sentence)
{
    if (!sentence)
    {
        return false;
    }

    if (strcmp(sentence, "") == 0)
    {
        return false;
    }

    return true;
}
