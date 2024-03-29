#include "robot_simulator.h"
#include <string.h>

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t new_robot = {.direction = direction,
                                .position.x = x,
                                .position.y = y};
    
    return new_robot;
}

void robot_move(robot_status_t *robot, const char *commands)
{
    size_t cmd_len = strlen(commands);

    for (size_t i = 0; i < cmd_len; i++)
    {
        if (commands[i] == 'R')
        {
            robot->direction = (robot->direction + 1) % DIRECTION_MAX;
            continue;
        }

        if (commands[i] == 'L')
        {
            if (robot->direction == 0)
            {
                robot->direction = DIRECTION_WEST;
            } else 
            {
                robot->direction--;
            }
            continue;
        }

        if (commands[i] == 'A')
        {
            if (robot->direction == DIRECTION_NORTH)
            {
                robot->position.y++;
                continue;
            }

            if (robot->direction == DIRECTION_SOUTH)
            {
                robot->position.y--;
                continue;
            }

            if (robot->direction == DIRECTION_EAST)
            {
                robot->position.x++;
                continue;
            }

            if (robot->direction == DIRECTION_WEST)
            {
                robot->position.x--;
                continue;
            }
        }
    }
}