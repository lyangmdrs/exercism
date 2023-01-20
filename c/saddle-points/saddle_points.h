#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>

// C array indexes start from 0, but the maht matix indexes start from 1.
// Therefore the following conversion function is necessary.
#define ARR_INDEX2MATH_INDEX(A) A+1

typedef struct
{
    uint8_t row;
    uint8_t column;
} saddle_point_t;

typedef struct s_saddle_points
{
    size_t count;
    saddle_point_t points[];
} saddle_points_t;

saddle_points_t* saddle_points(size_t num_rows, size_t num_columns, uint8_t matrix[num_rows][num_columns]);
void free_saddle_points(saddle_points_t* saddle_points);

#endif