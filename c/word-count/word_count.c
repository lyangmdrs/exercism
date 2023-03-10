#include "word_count.h"

#include <string.h>
#include <ctype.h>
#include <limits.h>

#include <stdio.h>

#define WORD_NOT_PRESENT (MAX_WORDS + 1)

static size_t its_repeated_word(const char *word, word_count_word_t *words, size_t num_words)
{
    
    if (num_words == 0) 
    {
        return WORD_NOT_PRESENT;
    }
    
    for (size_t i = 0; i < num_words; i++)
    {
        // printf("Compare: %s = %s\n", word, words[i].text);
        
        if (strcmp(word, words[i].text) == 0)
        {
            return i;
        }

    }

    return WORD_NOT_PRESENT;
}

int count_words(const char *sentence, word_count_word_t *words)
{
    const char delimiters[12] = " ,\n:!&@$%^&";
    char buffer[123];
    char *token;
    int num_words = 0;

    strcpy(buffer, sentence);

    token = strtok(buffer, delimiters);

    while (token != NULL)
    {
        // printf("%s\n", token);
        size_t position = its_repeated_word(token, words, num_words);
        
        if (position < WORD_NOT_PRESENT) 
        {
            // printf("Word already saved on %ld.\n", position);
            words[position].count++;
        }
        else
        {
            words[num_words].count = 1;
            strcpy(words[num_words++].text, token);
        }
        
        token = strtok(NULL, delimiters);
    }

    // for (int i = 0; i < num_words; i++)
    // {
    //     printf("Word: %s\n", words[i].text);
    // }

    return num_words;
}
