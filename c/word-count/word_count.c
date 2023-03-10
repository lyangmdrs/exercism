#include "word_count.h"

#include <string.h>
#include <ctype.h>
#include <limits.h>

#include <stdio.h>

#define WORD_NOT_PRESENT (MAX_WORDS + 1)

static void normalize_case(const char *word, char *output)
{
    for (size_t i = 0; i < MAX_WORD_LENGTH; i++)
    {
        if (isupper(word[i]))
        {
            output[i] = tolower(word[i]);
            continue;
        }

        output[i] = word[i];
    }
}

static size_t its_repeated_word(const char *word, word_count_word_t *words, size_t num_words)
{
    if (num_words == 0) 
    {
        return WORD_NOT_PRESENT;
    }
    
    for (size_t i = 0; i < num_words; i++)
    {
        // printf("Compare: %s == %s? ", word, words[i].text);
        // printf("%s\n", strcmp(word, words[i].text)==0?"yes":"no");
        
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
        char normalized_word[MAX_WORD_LENGTH];
        size_t position;
        
        normalize_case(token, normalized_word);

        position = its_repeated_word(normalized_word, words, num_words);

        if (position < WORD_NOT_PRESENT) 
        {
            words[position].count++;
        }
        else
        {
            words[num_words].count = 1;
            strcpy(words[num_words++].text, normalized_word);
        }
        
        token = strtok(NULL, delimiters);
    }

    // for (int i = 0; i < num_words; i++)
    // {
    //     printf("Word: %s\n", words[i].text);
    // }

    return num_words;
}
