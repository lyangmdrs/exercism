#include "pythagorean_triplet.h"

void garant_sequence(uint16_t* a, uint16_t* b, uint16_t* c);

triplets_t* triplets_with_sum(uint16_t sum)
{
    triplets_t* triplet = malloc(sizeof(triplets_t));

    if (triplet == NULL)
    {
        return NULL;
    }

    triplet->count = 0;

    for (uint16_t m = 2; m < sum; m++)
    {
        uint16_t n = (sum/(2 * m)) - m;
        uint16_t a = (m * m) - (n * n);
        uint16_t b = 2 * m * n;
        uint16_t c = (m * m) + (n * n);


        if ((a + b + c) == sum)
        {
            triplet->count++;

            triplets_t* _triplet = realloc(triplet, sizeof(triplets_t) + sizeof(triplet_t) * triplet->count);

            if (!_triplet)
            {
                return NULL;
            }

            garant_sequence(&a, &b, &c);

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

void garant_sequence(uint16_t* a, uint16_t* b, uint16_t* c)
{
    if (*b > *c)
    {
        uint16_t _b = *b;
        *b = *c;
        *c = _b;
    }

    if (*a > *b)
    {
        uint16_t _b = *b;
        *b = *a;
        *a = _b;
    }
}