#include "allergies.h"

uint32_t count_bits (uint32_t n);

bool is_allergic_to(allergen_t allergn, uint32_t score)
{
    return allergn & score;
}

allergen_list_t get_allergens(uint32_t score)
{
    allergen_list_t list;
    
    score &= ALLERGENS_FILTER;
    count_bits(score);
    
    list.count = count_bits(score);
    
    for (uint32_t i = 0; i <= 8; i++)
    {   
        uint32_t power_of_two = pow(2, i);
        if (power_of_two & score)
        {
            list.allergens[power_of_two] = true;
        }
    }
    return list;
}

// Returns the number of bits true in a given number.
uint32_t count_bits (uint32_t n)
{
   uint32_t counter = 0;
   while (n) 
   {
      counter += n & 1;
      n >>= 1;
   }
   return counter;
}