#include "word_count.h"

#include <string.h>
#include <ctype.h>

#include <stdio.h>

int count_words(const char *sentence, word_count_word_t *words)
{
    const char delimiters[2] = " ";
    char buffer[123];
    char *token;
    int num_words = 0;

    strcpy(buffer, sentence);

    token = strtok(buffer, delimiters);

    while (token != NULL)
    {
        // printf("%s\n", token);
        words[num_words].count = 1;
        strcpy(words[num_words++].text, token);
        token = strtok(NULL, delimiters);
    }

    return num_words;
}
