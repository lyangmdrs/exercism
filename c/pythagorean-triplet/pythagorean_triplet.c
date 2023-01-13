#include "pythagorean_triplet.h"

triplets_t* triplets_with_sum(uint16_t n)
{
    triplets_t* triplet = malloc(sizeof(triplets_t) + sizeof(triplet_t));

    if (triplet == NULL)
    {
        return NULL;
    }

    triplet->count = 0;

    for (uint16_t i = 2; i < n; i++)
    {
        for (uint16_t j = i + 1; j < n; j++)
        {
            for (uint16_t k = j + 1; k < n; k++)
            {
                if ((pow(i, 2) + pow(j, 2)) == pow(k, 2))
                {
                    if ((i + j + k) == n)
                    {
                        triplet->count++;
                        triplets_t* _triplet = realloc(triplet, sizeof(triplets_t) + sizeof(triplet_t) * triplet->count);

                        if (!triplet)
                        {
                            return NULL;
                        }

                        triplet = _triplet;

                        triplet->triplets[triplet->count - 1].a = i;
                        triplet->triplets[triplet->count - 1].b = j;
                        triplet->triplets[triplet->count - 1].c = k;
                    }
                }
            }
        }
    }

    return triplet;
}

void free_triplets(triplets_t *triplets)
{
    free(triplets);
}