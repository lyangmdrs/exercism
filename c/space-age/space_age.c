#include "space_age.h"

#define MERCURY_RATIO (0.2408467)
#define VENUS_RATIO (0.61519726)
#define EARTH_RATIO (1.0)
#define MARS_RATIO (1.8808158)
#define JUPITER_RATIO (11.862615)
#define SATURN_RATIO (29.447498)
#define URANUS_RATIO (84.016846)
#define NEPTUNE_RATIO (164.79132)
#define ERROR_RESULT (-1.0)

#define CONVERT_SECONDS_TO_YEAR(A) (A*3.17098e-8)

float age(planet_t planet, int64_t seconds)
{
    float result = (float)seconds;

    if ((planet < MERCURY) || (planet > NEPTUNE)) return ERROR_RESULT;

    if (planet == MERCURY) result = CONVERT_SECONDS_TO_YEAR(seconds / MERCURY_RATIO);
    if (planet == VENUS) result = CONVERT_SECONDS_TO_YEAR(seconds / VENUS_RATIO);
    if (planet == EARTH) result = CONVERT_SECONDS_TO_YEAR(seconds / EARTH_RATIO);
    if (planet == MARS) result = CONVERT_SECONDS_TO_YEAR(seconds / MARS_RATIO);
    if (planet == JUPITER) result = CONVERT_SECONDS_TO_YEAR(seconds / JUPITER_RATIO);
    if (planet == SATURN) result = CONVERT_SECONDS_TO_YEAR(seconds / SATURN_RATIO);
    if (planet == URANUS) result = CONVERT_SECONDS_TO_YEAR(seconds / URANUS_RATIO);
    if (planet == NEPTUNE) result = CONVERT_SECONDS_TO_YEAR(seconds / NEPTUNE_RATIO);

    return result;
}
