#include "pangram.h"

#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define ALPHABET_STR_LEN 27
#define REQUIRED_SCORE 26

static int calculate_sentence_score(const char *sentence)
{
    unsigned int score = 0;
    // size_t length = strlen(sentence);
    char alphabet[ALPHABET_STR_LEN] = "abcdefghijklmnopqrstuvwxyz";

    for (size_t i = 0; i < ALPHABET_STR_LEN; i++)
    {
        if (!isalpha(alphabet[i])) continue;
        
        // printf("Test %c in %s: ", alphabet[i], sentence);
        
        if (strchr(sentence, alphabet[i]))
        {
            // printf("true");
            score++;
        } else
        {
            // printf("false");
        }
        
        // printf("\n");
        
    }

    return score;
}

bool is_pangram(const char *sentence)
{
    if (!sentence)
    {
        return false;
    }

    if (strcmp(sentence, "") == 0)
    {
        return false;
    }

    if (calculate_sentence_score(sentence) >= REQUIRED_SCORE)
    {
        return true;
    }

    return false;
}
