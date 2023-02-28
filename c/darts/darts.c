#include "darts.h"

/**
 * The outer circle has a radius of 10 units, this circle gives 1 point;
 * The middle circle has a radius of 5 units, this circle gives 5 points;
 * The inner circle has a radius of 1 unit, this circle gives 10 points;
 * 
 * All the circles are concentric at the coordinates (0,0);
 */

#define OUTER_CIRCLE_RADIUS (10.0F)
#define MIDDLE_CIRCLE_RADIUS (5.0F)
#define INNER_CIRCLE_RADIUS (1.0F)

enum {MISS, OUTER_CIRCLE, MIDDLE_CIRCLE, INNER_CIRCLE};

uint8_t score(coordinate_t coordinate)
{
    if (fabs(coordinate.x) > 8 && fabs(coordinate.y) >= 8)
    {
        return MISS;
    }

    if ((fabs(coordinate.x) > MIDDLE_CIRCLE_RADIUS) ^
        (fabs(coordinate.y) > MIDDLE_CIRCLE_RADIUS))
    {
        return OUTER_CIRCLE;
    }

    return MISS;
}
