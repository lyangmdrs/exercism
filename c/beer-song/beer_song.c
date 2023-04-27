#include "beer_song.h"
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH (1024)
#define MAX_LINE_COUNT (299)

#define PLURAL_LINE1 "%d bottles of beer on the wall, %d bottles of beer."
#define PLURAL_LINE2 "Take one down and pass it around, %d bottles of beer on the wall."

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
    const char lines[][MAX_LINE_LENGTH] = {
        "%d bottles of beer on the wall, %d bottles of beer.",
        "Take one down and pass it around, %d bottles of beer on the wall.",
        "Take one down and pass it around, %d bottle of beer on the wall.",
        "%d bottle of beer on the wall, %d bottle of beer.",
        "Take it down and pass it around, no more bottles of beer on the wall.",
        "No more bottles of beer on the wall, no more bottles of beer.",
        "Go to the store and buy some more, 99 bottles of beer on the wall."
    };

    for (int i = 0; i < take_down; i++)
    {
        if (start_bottles == 1)
        {
            sprintf(song[i], lines[3], start_bottles, start_bottles);
        } else if (start_bottles == 0)
        {
            strcpy(song[i], lines[5]);
        }else
        {
            sprintf(song[i], lines[0], start_bottles, start_bottles);
        }
        
        if (start_bottles == 0)
        {
            strcpy(song[i + 1], lines[6]);
            start_bottles = 99;
            continue;
        } 
        else if (start_bottles - 1 == 1)
        {
            sprintf(song[i + 1], lines[2], start_bottles - 1);
        } else if (start_bottles - 1 == 0)
        {
            strcpy(song[i + 1], lines[4]);
        } else
        {
            sprintf(song[i + 1], lines[1], start_bottles - 1);
        }
        start_bottles--;

        // printf("%s\n", song[i]);
        // printf("%s\n", song[i + 1]);
    }
}
