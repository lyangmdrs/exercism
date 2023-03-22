#include "rail_fence_cipher.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define MAX_STRING_LENGTH 50

char *encode(char *text, size_t rails)
{
    char **ciphers = malloc(sizeof(char*) * rails);

    if (!ciphers)
    {
        return NULL;
    }

    for (size_t i = 0; i < rails; i++)
    {
        ciphers[i] = malloc(sizeof(char) * MAX_STRING_LENGTH);

        if (!ciphers[i])
        {
            return NULL;
        }

        memset(ciphers[i], '\0', MAX_STRING_LENGTH);
    }
    
    char * result = malloc(sizeof(char) * MAX_STRING_LENGTH);
    
    if (!result)
    {
        return NULL;
    }

    memset(result, '\0', MAX_STRING_LENGTH);
    
    int signal = 1;
    size_t cipher_index = 0;
    
    for (size_t i = 0; text[i]; i++)
    {
        strncat(ciphers[cipher_index], &text[i], 1);
        if ((cipher_index == (rails - 1)) || ((!cipher_index) && (signal < 0)))
        {
            signal *= -1;
        }

        cipher_index += signal;
    }

    
    for (int i = 0; i < (int)rails; i++)
    {
        strcat(result, ciphers[i]);
        free(ciphers[i]);
    }

    free(ciphers);

    return result;
}

char *decode(char *ciphertext, size_t rails)
{
    if (!ciphertext)
    {
        return NULL;
    }
	
    if (rails == 0)
    {
        return NULL;
    }

	const size_t ciphertext_len = strlen(ciphertext);
	char *text = calloc(ciphertext_len + 1, sizeof(char));
	
    if (ciphertext_len == 0 || rails == 1)
    {
		strncpy(text, ciphertext, ciphertext_len);
		return text;
	}

	
	size_t rail_len[rails];
	
    for (size_t current_rail = 0; current_rail < rails; current_rail++)
    {
		rail_len[current_rail] = 0;
	}

	for (size_t i = 0; i < ciphertext_len;)
    {
		for (size_t current_rail = 0; current_rail < rails && i < ciphertext_len; current_rail++, i++) 
        {
			rail_len[current_rail]++;
		}
		
        for (size_t current_rail = rails - 2; current_rail > 0 && i < ciphertext_len; current_rail--, i++)
        {
			rail_len[current_rail]++;
		}
	}
	

	size_t rail_start[rails];
	rail_start[0] = 0;

	for (size_t i = 1; i < rails; i++)
    {
		rail_start[i] = rail_start[i - 1] + rail_len[i - 1];
	}

	size_t rail_idx[rails];

	for (size_t i = 0; i < rails; i++)
    {
		rail_idx[i] = 0;
	}

	size_t i = 0;
	
    while (i < ciphertext_len)
    {
		for (size_t current_rail = 0; current_rail < rails && i < ciphertext_len; current_rail++, i++)
        {
			size_t src_idx = rail_start[current_rail] + rail_idx[current_rail]++;
			text[i] = ciphertext[src_idx];
		}

		for (size_t current_rail = rails - 2; current_rail > 0 && i < ciphertext_len; current_rail--, i++)
        {
			size_t src_idx = rail_start[current_rail] + rail_idx[current_rail]++;
			text[i] = ciphertext[src_idx];
		}
	}
    
	text[i++] = '\0';
	return text;
}