#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    // Check if positions are equal
    if ((queen_1.column == queen_2.column) && (queen_1.row == queen_2.row))
    {
        return INVALID_POSITION;
    }

    return INVALID_POSITION;
}
