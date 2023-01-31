#include "clock.h"

void roll_over_minutes(int* hour, int* minute);
void roll_over_hours(int* hour);
void convert_negative2positive_hour(int* hour);
void convert_negative2positive_minute(int* hour, int* minute);
void convert_text2int(clock_t clock, int* hour, int* minute);

clock_t clock_create(int hour, int minute)
{
    clock_t new_clock;
    
    if (hour < 0)
    {
        convert_negative2positive_hour(&hour);
    }

    if (minute < 0)
    {
        convert_negative2positive_minute(&hour, &minute);
    }

    roll_over_minutes(&hour, &minute);
    roll_over_hours(&hour);

    int hour_dozens = hour/10;
    int min_dozens = minute/10;

    sprintf(new_clock.text, "%s", RESETED_CLK);

    new_clock.text[0] += hour_dozens;
    new_clock.text[1] += (hour - hour_dozens * 10);
    new_clock.text[3] += min_dozens;
    new_clock.text[4] += (minute - min_dozens * 10);

    return new_clock;
}


clock_t clock_add(clock_t clock, int minute_add)
{
    int hour;
    int minute;

    convert_text2int(clock, &hour, &minute);

    minute += minute_add;

    clock_t new_clock = clock_create(hour, minute);
    
    return new_clock;
}

/** from this line functions were written without any functionality
 *  just to declare the functions and let the compiler happy. **/
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
    while (*hour < 0)
    {
        *hour += 24;
    }
}

void convert_negative2positive_minute(int* hour, int* minute)
{
    int roll_hour = 0;

    while (*minute < 0)
    {
        roll_hour--;
        *minute += 60;
    }

    convert_negative2positive_hour(&roll_hour);
    *hour += roll_hour;
}

void convert_text2int(clock_t clock, int* hour, int* minute)
{
    *hour = (clock.text[0] - '0') * 10 + (clock.text[1] - '0');
    *minute = (clock.text[3] - '0') * 10 + (clock.text[4] - '0');
}
