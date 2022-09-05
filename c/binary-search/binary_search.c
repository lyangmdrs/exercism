#include "binary_search.h"

int *binary_search(int value, const int *arr, size_t length)
{
    int start = length / 2;
    
    if (value == arr[start])
    {
        return (int*)(arr + start);
    }
    
    return NULL;
}