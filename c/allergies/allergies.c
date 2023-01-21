#include "allergies.h"

bool is_allergic_to(allergen_t allergn, uint32_t score)
{
    return allergn & score;
}