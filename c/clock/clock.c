#include "clock.h"

// Internal macros
#define RESET_CLK "00:00"
#define MASK_CLK "%d%d:%d%d"
#define GET_INT_DOZEN(A) (A / 10)
#define INT_TO_DOZEN(A) (A * 10)
#define INT_POS_TO_NEG(A) (A * (-1))
#define HOUR_IN_MINUTES 60
#define DAY_IN_HOURS 24
#define HOUR_DOZEN_INDEX 0
#define HOUR_UNITY_INDEX 1
#define MINUTE_DOZEN_INDEX 3
#define MINUTE_UNITY_INDEX 4

// Helper functions
static void roll_over_minutes(int* hour, int* minute);
static void roll_over_hours(int* hour);
static void convert_negative2positive_hour(int* hour);
static void convert_negative2positive_minute(int* hour, int* minute);
static void convert_text2int(clock_t clock, int* hour, int* minute);

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

    int hour_dozens = GET_INT_DOZEN(hour);
    int min_dozens = GET_INT_DOZEN(minute);

    sprintf(new_clock.text, MASK_CLK, hour_dozens, (hour - INT_TO_DOZEN(hour_dozens)),
            min_dozens, (minute - INT_TO_DOZEN(min_dozens)));

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

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    return clock_add(clock, INT_POS_TO_NEG(minute_subtract));
}

bool clock_is_equal(clock_t a, clock_t b)
{
    if (strcmp(a.text, b.text))
    {
        return false;
    }

    return true;
}

static void roll_over_minutes(int* hour, int* minute)
{
    if (*minute >= HOUR_IN_MINUTES)
    {
        *hour += (*minute/HOUR_IN_MINUTES);
        while (*minute >= HOUR_IN_MINUTES)
        {
            *minute -= HOUR_IN_MINUTES;
        }
    }
}

static void roll_over_hours(int* hour)
{
    while (*hour >= DAY_IN_HOURS)
    {
        *hour -= DAY_IN_HOURS;
    }
}

static void convert_negative2positive_hour(int* hour)
{
    while (*hour < 0)
    {
        *hour += DAY_IN_HOURS;
    }
}

static void convert_negative2positive_minute(int* hour, int* minute)
{
    int roll_hour = 0;

    while (*minute < 0)
    {
        roll_hour--;
        *minute += HOUR_IN_MINUTES;
    }

    convert_negative2positive_hour(&roll_hour);
    *hour += roll_hour;
}

static void convert_text2int(clock_t clock, int* hour, int* minute)
{
    *hour = INT_TO_DOZEN((clock.text[HOUR_DOZEN_INDEX] - '0')) + \
            (clock.text[HOUR_UNITY_INDEX] - '0');

    *minute = INT_TO_DOZEN((clock.text[MINUTE_DOZEN_INDEX] - '0')) + \
              (clock.text[MINUTE_UNITY_INDEX] - '0');
}
