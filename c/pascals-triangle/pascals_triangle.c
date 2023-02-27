#include "pascals_triangle.h"


uint8_t **create_triangle(size_t rows)
{
	if (rows == 0)
    {
		rows++;
		uint8_t **result = calloc(rows, sizeof(uint8_t *));
		
        for (size_t i = 0; i < rows; i++)
        {
			result[i] = calloc(rows, sizeof(uint8_t));
        }

		return result;
	}
	
    uint8_t **result = calloc(rows, sizeof(uint8_t *));
	
    for (size_t i = 0; i < rows; i++)
    {
        result[i] = calloc(rows, sizeof(uint8_t));
    }

	if (rows == 1)
    {
		result[0][0] = 1;
	}

	if (rows > 1)
    {
		for (size_t i = 0; i < rows; i++)
        {
			for (size_t j = 0; j < rows; j++)
            {
				if (i != 0 && j != 0)
                {
					result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
                }
				else if (j <= i)
                {
					result[i][j] = 1;
                }
			}
		}
	}
	return result;
}

void free_triangle(uint8_t **triangle, size_t rows)
{
	for (size_t i = 0; i < rows; i++)
    {
        free(triangle[i]);
    }
	free(triangle);
}