#include "pythagorean_triplet.h"

bool triplet_is_valid(uint16_t a, uint16_t b, uint16_t c);

triplets_t* triplets_with_sum(uint16_t sum)
{
    triplets_t* triplet = malloc(sizeof(triplets_t));

    if (triplet == NULL)
    {
        return NULL;
    }

    triplet->count = 0;

    /** PROBLEM COMPLEXITY REDUCTION
     * Two equations are given initially: (Let sum = s, to simplify writing.)
     * > a^2 + b^2 = c^2;   (I)
     * > a + b + c = s;     (II)
     * 
     * Equation (II) can be rewritten as to isolate the variable "c":
     * > c = s - a - b;     (III)
     * 
     * Replacing equation (III) in equation (I):
     * > a^2 + b^2 = (s - a - b)^2;
     * > a^2 + b^2 = s^2 - 2*s*a - 2*s*b + a^2 + 2*a*b + b^2;
     * > s^2 - 2*s*a - 2*s*b + 2*a*b = 0;   (IV)
     * 
     * Solving (IV) to "b":
     * > b = (s^2 - 2*s*a) / (2*s - 2*a);
     * > b = (s^2 - 2*s*a) / (2(s - a));
     * 
     * With that, only one for loop is necessary, because, by iterating the 
     * variable "a", we can calculate the others.
     * 
    */

    for (uint16_t a = 1; a < sum/2; a++)
    {
        uint16_t b = (sum * sum - 2 * sum * a) / (2 * (sum - a));

        uint16_t c = sum - a - b;

        if (triplet_is_valid(a, b, c))
        {
            triplet->count++;

            triplets_t* _triplet = realloc(triplet, sizeof(triplets_t) + sizeof(triplet_t) * triplet->count);

            if (!_triplet)
            {
                return NULL;
            }
            
            triplet = _triplet;
            triplet->triplets[triplet->count - 1].a = a;
            triplet->triplets[triplet->count - 1].b = b;
            triplet->triplets[triplet->count - 1].c = c;
        }
    }

    return triplet;
}

void free_triplets(triplets_t *triplets)
{
    free(triplets);
}

bool triplet_is_valid(uint16_t a, uint16_t b, uint16_t c)
{
    // Checks that the variables obey the Pythagorean relation for the right triangle.
    bool pythagorean_relation = (a * a + b * b) == (c * c);
    // Checks if the variables are correctly ordered (a < b < c).
    bool right_sequence = (a < b) && (b < c);
    
    return pythagorean_relation && right_sequence;
}