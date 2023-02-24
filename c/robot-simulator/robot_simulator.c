#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t new_robot = {.direction = direction,
                                .position.x = x,
                                .position.y = y};
    
    return new_robot;
}
