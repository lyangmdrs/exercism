#include "pythagorean_triplet.h"

bool is_a_triplet(uint16_t a, uint16_t b, uint16_t c, uint16_t sum);

triplets_t* triplets_with_sum(uint16_t n)
{
    triplets_t* triplet = malloc(sizeof(triplets_t) + sizeof(triplet_t));

    if (triplet == NULL)
    {
        return NULL;
    }

    uint16_t start_counting = 3;
    uint16_t end_counting = n/2;

    triplet->count = 0;

    for (uint16_t a = start_counting; a < end_counting; a++)
    {
        for (uint16_t b = a + 1; b < end_counting; b++)
        {
            uint16_t c = sqrt(pow(a, 2) + pow(b, 2));

            if (is_a_triplet(a, b, c, n))
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
    }

    return triplet;
}

void free_triplets(triplets_t *triplets)
{
    free(triplets);
}

bool is_a_triplet(uint16_t a, uint16_t b, uint16_t c, uint16_t sum)
{
    bool right_sequence = (a < b) && (b < c);
    bool right_sum = (a + b + c) == sum;
    bool pytagorean_relation = (pow(a, 2) + pow(b, 2)) == pow(c, 2);
    return right_sequence && right_sum && pytagorean_relation;
}