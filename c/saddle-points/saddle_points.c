#include "saddle_points.h"

uint8_t** get_transpose(size_t num_rows, size_t num_columns, uint8_t matrix[num_rows][num_columns]);
void free_transpose(size_t num_rows, uint8_t** transpose);
bool check_saddle_in_row(uint8_t* row, size_t column, size_t length);
bool check_saddle_in_column(uint8_t* column, size_t row, size_t length);

saddle_points_t* saddle_points(size_t num_rows, size_t num_columns, uint8_t matrix[num_rows][num_columns])
{
    saddle_points_t* points = malloc(sizeof(saddle_points_t));

    if (!points)
    {
        return NULL;
    }

    uint8_t** transpose = get_transpose(num_rows, num_columns, matrix);

    points->count = 0;

    for (size_t row = 0; row < num_rows; row++)
    {
        for (size_t column = 0; column < num_columns; column++)
        {
            bool is_row_saddle = check_saddle_in_row(matrix[row], column, num_columns);
            bool is_colmun_saddel = check_saddle_in_column(transpose[column], row, num_rows);
            
            if (is_row_saddle && is_colmun_saddel)
            {
                points->count++;
                saddle_points_t* _points = realloc(points, sizeof(saddle_points_t) + points->count * sizeof(saddle_point_t));

                if (!points)
                {
                    free_saddle_points(points);
                    free_transpose(num_rows, transpose);
                    return NULL;
                }

                points = _points;
                points->points[points->count - 1].row = row;
                points->points[points->count - 1].column = column;
            }
        }
    }

    free_transpose(num_rows, transpose);
    return points;
}

void free_saddle_points(saddle_points_t* points)
{
    free(points->points);
    free(points);
}

uint8_t** get_transpose(size_t num_rows, size_t num_columns, uint8_t matrix[num_rows][num_columns])
{
    uint8_t** transpose = malloc(num_rows * sizeof(uint8_t*));
    
    for (size_t row = 0; row < num_rows; row++)
    {
        transpose[row] = malloc(num_columns * sizeof(uint8_t));
    }

    for (size_t row = 0; row < num_rows; row++)
    {
        for (size_t column = 0; column < num_columns; column++)
        {
            transpose[column][row] = matrix[row][column];
        }
    }

    return transpose;
}

void free_transpose(size_t num_rows, uint8_t** transpose)
{
    for (size_t row = 0; row < num_rows; row++)
    {
        free(transpose[row]);
    }

    free(transpose);
}

bool check_saddle_in_row(uint8_t* row, size_t column, size_t length)
{   
    for (size_t test_position = 0; test_position < length; test_position++)
    {
        if (row[column] < row[test_position])
        {
            return false;
        }
    }

    return true;
}

bool check_saddle_in_column(uint8_t* column, size_t row, size_t length)
{
    for (size_t test_position = 0; test_position < length; test_position++)
    {
        if (column[row] > column[test_position])
        {
            return false;
        }
    }

    return true;
}