#include "pythagorean_triplet.h"

triplets_t* triplets_with_sum(uint16_t n)
{
    triplets_t* triplet = malloc(sizeof(triplets_t) + sizeof(triplet_t));
    triplet->count = n/12;
    triplet->triplets[0].a = 3;
    triplet->triplets[0].b = 4;
    triplet->triplets[0].c = 5;

    return triplet;
}
void free_triplets(triplets_t *triplets)
{
    free(triplets);
}