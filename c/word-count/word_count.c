#include "word_count.h"

#include <string.h>
#include <ctype.h>
#include <limits.h>

#include <stdio.h>

#define WORD_NOT_PRESENT (MAX_WORDS + 1)

static void remove_quotations(const char *word, char *output)
{
    char *first_quote_occurrence, *last_quote_occurrence;
   
    first_quote_occurrence = strchr(word, '\'');
    last_quote_occurrence = strrchr(word, '\'');

    if (first_quote_occurrence == last_quote_occurrence)
    {
        strcpy(output, word);
        return;
    }

    size_t length = (last_quote_occurrence - first_quote_occurrence) - 1;
    strncpy(output, word + 1, length);
    output[length] = '\0';
}

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
        if (strcmp(word, words[i].text) == 0)
        {
            return i;
        }
    }

    return WORD_NOT_PRESENT;
}

int count_words(const char *sentence, word_count_word_t *words)
{
    const char delimiters[13] = " ,\n:!&@$%^&.";
    char buffer[MAX_WORD_LENGTH];
    char *token;
    int num_words = 0;

    strcpy(buffer, sentence);

    token = strtok(buffer, delimiters);

    while (token != NULL)
    {
        char unquoted_word[MAX_WORD_LENGTH];
        char normalized_word[MAX_WORD_LENGTH];
        size_t position;
        
        remove_quotations(token, unquoted_word);
        normalize_case(unquoted_word, normalized_word);

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

    // printf("\nCHECK WORD COUNT\n\n");
    // for (int i = 0; i < num_words; i++)
    // {
    //     printf("Word %s with %d occurrences\n", words[i].text, words[i].count);
    // }

    return num_words;
}
