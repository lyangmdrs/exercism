#include "clock.h"

clock_t clock_create(int hour, int minute)
{
    clock_t new_clock;

    int hour_dozens = hour/10;
    int min_dozens = hour/10;

    sprintf(new_clock.text, "%s", RESETED_CLK);

    new_clock.text[0] += hour_dozens;
    new_clock.text[1] += (hour - hour_dozens);
    new_clock.text[3] += min_dozens;
    new_clock.text[4] += (minute - min_dozens);

    return new_clock;
}
