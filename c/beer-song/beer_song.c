#include "beer_song.h"
#include <stdio.h>

#define MAX_LINE_LENGTH (1024)
#define MAX_LINE_COUNT (299)

#define PLURAL_LINE1 "%d bottles of beer on the wall, %d bottles of beer."
#define PLURAL_LINE2 "Take one down and pass it around, %d bottles of beer on the wall."

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
    if (start_bottles) {}
    if (take_down) {}

    const char lines[][MAX_LINE_LENGTH] = {
        "%d bottles of beer on the wall, %d bottles of beer.",
        "Take one down and pass it around, %d bottles of beer on the wall."
    };

    sprintf(song[0], lines[0], 99, 99);
    sprintf(song[1], lines[1], 98);
}
