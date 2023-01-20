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

    for (uint16_t a = 1; a < sum/2; a++)
    {
        uint16_t b = (sum * sum - 2 * sum * a) / (2 * sum - 2 * a);

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
    bool pythagorean_relation = (a * a + b * b) == (c * c);
    bool right_sequence = (a < b);
    return pythagorean_relation && right_sequence;
}