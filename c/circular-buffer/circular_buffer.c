#include "circular_buffer.h"

static void buffer_memmory_allocation(circular_buffer_t* buffer);
static bool next_position_reached_oldest_value(circular_buffer_t* buffer);

int16_t write(circular_buffer_t* buffer, buffer_value_t value)
{
    
    if (buffer->usage >= buffer->capacity)
    {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    buffer->values[buffer->next_position] = value;
    
    if (buffer->usage < buffer->capacity)
    {
        buffer->usage++;
    }

    buffer->next_position = (buffer->next_position + 1) % buffer->capacity;
    
    errno = EXIT_SUCCESS;
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t* buffer, buffer_value_t value)
{
    if (next_position_reached_oldest_value(buffer))
    {
        buffer_value_t garbage;
        read(buffer, &garbage);
    }
    
    write(buffer, value);

    errno = EXIT_SUCCESS;
    return EXIT_SUCCESS;
}

int16_t read(circular_buffer_t* buffer, buffer_value_t* value)
{
    if (buffer->usage <= 0)
    {
        errno = ENODATA;
        return EXIT_FAILURE;
    }

    *value = buffer->values[buffer->oldest_value];

    if (buffer->usage > 0)
    {
        buffer->usage--;
    }
    
    buffer->oldest_value = (buffer->oldest_value + 1) % buffer->capacity;

    errno = EXIT_SUCCESS;
    return EXIT_SUCCESS;
}

circular_buffer_t* new_circular_buffer(size_t capacity)
{
    circular_buffer_t* buffer = NULL;
    buffer = malloc(sizeof(circular_buffer_t));
    
    if (!buffer)
    {
        return NULL;
    }
    
    buffer->capacity = capacity;
    buffer->usage = 0;
    buffer->next_position = 0;
    buffer->oldest_value = 0;

    buffer_memmory_allocation(buffer);

    if (!buffer->values)
    {
        delete_buffer(buffer);
        return NULL;
    }

    return buffer;
}

void delete_buffer(circular_buffer_t* buffer)
{
    if (buffer->values != NULL)
    {
        free(buffer->values);
    }

    if (buffer != NULL)
    {
        free(buffer);
    }
    
}

void clear_buffer(circular_buffer_t* buffer)
{
    memset(buffer->values, 0, buffer->capacity * sizeof(*buffer->values));

    buffer->usage = 0;
    buffer->next_position = 0;
    buffer->oldest_value = 0;
}

static void buffer_memmory_allocation(circular_buffer_t* buffer)
{
    buffer->values = malloc(buffer->capacity * sizeof(buffer_value_t));
}

static bool next_position_reached_oldest_value(circular_buffer_t* buffer)
{
    return buffer->next_position == buffer->oldest_value;
}
