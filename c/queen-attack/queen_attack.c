#include "queen_attack.h"

#include <stdbool.h>
#include <stdio.h>

bool position_is_valid(position_t queen);

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    if ((queen_1.column == queen_2.column) && (queen_1.row == queen_2.row))
    {
        return INVALID_POSITION;
    }

    if (!position_is_valid(queen_1) || !position_is_valid(queen_2))
    {
        return INVALID_POSITION;
    }

    if ((queen_1.column == queen_2.column) ^ (queen_1.row == queen_2.row))
    {
        return CAN_ATTACK;
    }

    // Look for queens on 1st diagonal
    for (int i = queen_1.column, j = queen_1.row; (i < 8) && (j >= 0); i++, j--)
    {
        if ((queen_2.column == i) && (queen_2.row == j))
        {
            return CAN_ATTACK;
        }
    }

    printf("decrescent!\n");
    for (int i = queen_1.column, j = queen_1.row; (i >= 0) && (j < 8); i--, j++)
    {   
        if ((queen_2.column == i) && (queen_2.row == j))
        {
            return CAN_ATTACK;
        }
    }

    

    return CAN_NOT_ATTACK;
}

bool position_is_valid(position_t queen)
{
    if ((queen.column >= 8) || (queen.row >= 8))
    {
        return false;
    }

    return true;
}
