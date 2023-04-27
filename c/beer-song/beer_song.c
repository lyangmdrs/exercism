#include "beer_song.h"
#include <stdio.h>

#define MAX_LINE_LENGTH (1024)
#define MAX_LINE_COUNT (299)

#define PLURAL_LINE1 "%d bottles of beer on the wall, %d bottles of beer."
#define PLURAL_LINE2 "Take one down and pass it around, %d bottles of beer on the wall."

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
    const char lines[][MAX_LINE_LENGTH] = {
        "%d bottles of beer on the wall, %d bottles of beer.",
        "Take one down and pass it around, %d bottles of beer on the wall."
    };

    for (int i = 0; i < take_down; i++)
    {
        sprintf(song[i], lines[0], start_bottles, start_bottles);
        sprintf(song[i + 1], lines[1], --start_bottles);
    }
}
