#include "resistor_color_trio.h"

#include <math.h>
#include <stdio.h>

resistor_value_t color_code(resistor_band_t colors[3])
{
    resistor_value_t result = { 0 };

    result.unit = ((colors[2] < RED) ? OHMS : KILOOHMS);

    result.value = ((colors[0] * 10 + colors[1]) * (int)pow(10, colors[2])) / result.unit;

    return result;
}