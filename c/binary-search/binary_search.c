#include "binary_search.h"

int* binary_search(int value, const int* arr, size_t length)
{
    int start = length / 2;

    if (length == 0)
    {
        return NULL;
    }

    if (value == arr[start])
    {
        return (int*)(arr + start);
    }
    else if (value < arr[start])
    {
        return binary_search(value, arr, start);
    }
    else if (value > arr[start])
    {
        return binary_search(value, &arr[start + 1], start);
    }

    return NULL;
}