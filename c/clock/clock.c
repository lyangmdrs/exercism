#include "clock.h"

void roll_over_minutes(int* hour, int* minute);
void roll_over_hours(int* hour);
void convert_negative2positive_hour(int* hour);

clock_t clock_create(int hour, int minute)
{
    clock_t new_clock;
    
    if (hour < 0)
    {
        convert_negative2positive_hour(&hour);
    }

    roll_over_minutes(&hour, &minute);
    roll_over_hours(&hour);

    int hour_dozens = hour/10;
    int min_dozens = minute/10;

    sprintf(new_clock.text, "%s", RESETED_CLK);

    // printf("hours: %d - minutes %d\n", hour, minute);
    // printf("CLOCK: %s\n", new_clock.text);
    // printf("H_DOZENS: %d\n", hour_dozens);
    // printf("M_DOZENS: %d\n", min_dozens);

    new_clock.text[0] += hour_dozens;
    // printf("CLOCK: %s\n", new_clock.text);
    new_clock.text[1] += (hour - hour_dozens * 10);
    // printf("CLOCK: %s\n", new_clock.text);
    new_clock.text[3] += min_dozens;
    // printf("CLOCK: %s\n", new_clock.text);
    new_clock.text[4] += (minute - min_dozens * 10);
    // printf("CLOCK: %s\n", new_clock.text);

    return new_clock;
}

/** from this line functions were written without any functionality
 *  just to declare the functions and let the compiler happy. **/
clock_t clock_add(clock_t clock, int minute_add)
{
    if (minute_add)
    {
        return clock;
    }
    return clock;
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    if (minute_subtract)
    {
        return clock;
    }
    return clock;
}

bool clock_is_equal(clock_t a, clock_t b)
{
    if (strcmp(a.text, b.text))
    {
        return false;
    }

    return true;
}

void roll_over_minutes(int* hour, int* minute)
{
    if (*minute >= 60)
    {
        *hour += (*minute/60);
        while (*minute >= 60)
        {
            *minute -= 60;
        }
    }
}

void roll_over_hours(int* hour)
{
    while (*hour >= 24)
    {
        *hour -= 24;
    }
}

void convert_negative2positive_hour(int* hour)
{
    *hour = (*hour * -1) + 22;
}