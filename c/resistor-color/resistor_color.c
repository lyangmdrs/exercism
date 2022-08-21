#include "resistor_color.h"

int color_code(int num)
{
    return num;
}

resistor_band_t* colors()
{
    static resistor_band_t col[]={BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};
    return col;
}