#include "pangram.h"

#include <string.h>
#include <ctype.h>

#define ALPHABET_STR "abcdefghijklmnopqrstuvwxyz"
#define ALPHABET_STR_LEN 27
#define REQUIRED_SCORE 26

static int calculate_sentence_score(const char *sentence)
{
    unsigned int score = 0;
    char alphabet[ALPHABET_STR_LEN] = ALPHABET_STR;

    for (size_t i = 0; i < ALPHABET_STR_LEN; i++)
    {
        if (!isalpha(alphabet[i])) continue;
        
        if (strchr(sentence, alphabet[i]))
        {
            score++;
        } else if (strchr(sentence, toupper(alphabet[i])))
        {
            score++;
        }
        
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
