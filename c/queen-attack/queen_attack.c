#include "queen_attack.h"

#include <stdbool.h>

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

    

    return CAN_NOT_ATTACK;
}

bool position_is_valid(position_t queen)
{
    if ((queen.column == 0) || (queen.row == 0))
    {
        return false;
    }

    return true;
}
