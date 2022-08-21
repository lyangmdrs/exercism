#include "square_root.h"

int square_root(int number)
{
    int root = 1;

    while ((root * root) != number)
    {
        root++;
    }
    return root;    
}