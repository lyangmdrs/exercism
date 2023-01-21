#include "saddle_points.h"

void free_transpose(size_t num_rows, uint8_t** transpose);
bool check_saddle_in_row(size_t num_rows, size_t num_columns, uint8_t matrix[num_rows][num_columns], size_t row, size_t test_column);
bool check_saddle_in_column(size_t num_rows, size_t num_columns, uint8_t matrix[num_rows][num_columns], size_t row, size_t test_column);

saddle_points_t* saddle_points(size_t num_rows, size_t num_columns, uint8_t matrix[num_rows][num_columns])
{
    saddle_points_t* points = malloc(sizeof(saddle_points_t));

    if (!points)
    {
        errno = ENOMEM;
        exit(EXIT_FAILURE);
    }

    points->count = 0;

    for (size_t row = 0; row < num_rows; row++)
    {
        for (size_t column = 0; column < num_columns; column++)
        {
            bool is_row_saddle = check_saddle_in_row(num_rows, num_columns, matrix, row, column);
            bool is_colmun_saddel = check_saddle_in_column(num_rows, num_columns, matrix, row, column);

            if (is_row_saddle && is_colmun_saddel)
            {
                points->count++;
                saddle_points_t* _points = realloc(points, sizeof(saddle_points_t) + points->count * sizeof(saddle_point_t));

                if (!_points)
                {
                    free_saddle_points(points);
                    errno = ENOMEM;
                    exit(EXIT_FAILURE);
                }

                points = _points;
                points->points[points->count - 1].row = ARR_INDEX2MATH_INDEX(row);
                points->points[points->count - 1].column = ARR_INDEX2MATH_INDEX(column);
            }
        }
    }

    return points;
}

void free_saddle_points(saddle_points_t* points)
{
    free(points);
}

void free_transpose(size_t num_rows, uint8_t** transpose)
{
    for (size_t row = 0; row < num_rows; row++)
    {
        free(transpose[row]);
    }

    free(transpose);
}

bool check_saddle_in_row(size_t num_rows, size_t num_columns, uint8_t matrix[num_rows][num_columns], size_t row, size_t test_column)
{
    for (size_t column = 0; column < num_columns; column++)
    {
        if (matrix[row][test_column] < matrix[row][column])
        {
            return false;
        }
    }

    return true;
}

bool check_saddle_in_column(size_t num_rows, size_t num_columns, uint8_t matrix[num_rows][num_columns], size_t test_row, size_t column)
{
    for (size_t row = 0; row < num_rows; row++)
    {
        if (matrix[test_row][column] > matrix[row][column])
        {
            return false;
        }
    }

    return true;
}
