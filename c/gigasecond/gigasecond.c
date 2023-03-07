#include "gigasecond.h"

#include <stdio.h>
#include <math.h>

#define GIGASECOND (1e9)

time_t gigasecond_after(time_t input)
{
    return (long int)(input + GIGASECOND);
}
