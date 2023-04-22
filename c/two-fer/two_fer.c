#include "two_fer.h"
#include <stdio.h>

void two_fer(char *buffer, const char *name)
{
    char *response = "One for %s, one for me.";
    
    if (!name)
    {
        sprintf(buffer, response, "you");
    } else
    {
        sprintf(buffer, response, name);
    }
}