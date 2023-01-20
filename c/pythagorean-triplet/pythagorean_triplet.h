#ifndef PYTHAGOREAN_TRIPLET_H
#define PYTHAGOREAN_TRIPLET_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>

// The is no possibility of a number smaller than 12 to have a triplet.
#define MIN_VALID_INPUT 12

// The smaller number in the triplet of the smaller possible input is 3.
#define MIN_TRIPLET_COMPONENT 3

typedef struct {
   uint16_t a;
   uint16_t b;
   uint16_t c;
} triplet_t;

typedef struct {
   uint16_t count;
   triplet_t triplets[];
} triplets_t;

triplets_t* triplets_with_sum(uint16_t n);
void free_triplets(triplets_t *triplets);
#endif
