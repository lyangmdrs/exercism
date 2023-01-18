#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct s_saddle_point saddle_point_t;
typedef struct s_saddle_points saddle_points_t;

struct s_saddle_point
{
    uint8_t row;
    uint8_t column;
};

struct s_saddle_points
{
    size_t count;
    saddle_point_t points[];
};

saddle_points_t* saddle_points(size_t num_rows, size_t num_columns, uint8_t matrix[num_rows][num_columns]);
void free_saddle_points(saddle_points_t* saddle_points);

#endif