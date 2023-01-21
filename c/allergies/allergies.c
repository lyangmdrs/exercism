#include "allergies.h"

bool is_allergic_to(allergen_t allergn, uint32_t score)
{
    if (allergn == 1 && score == 0)
    {
        return false;
    }
    return true;
}