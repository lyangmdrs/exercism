#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define PHONE_STRING_LEN 10
#define LAST_DIGIT_INDEX(A) strlen(A) - 1;

char *phone_number_clean(const char *input);

#endif
