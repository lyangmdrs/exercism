#include "circular_buffer.h"

struct circular_buffer
{
    size_t capacity;
    size_t usage;
    size_t read_position;
    size_t write_position;
    buffer_value_t values[];
    
};

static bool write_position_reached_read_position(circular_buffer_t* buffer);

int16_t write(circular_buffer_t* buffer, buffer_value_t value)
{
    
    if (buffer->usage >= buffer->capacity)
    {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    buffer->values[buffer->write_position] = value;
    
    buffer->usage++;

    buffer->write_position = (buffer->write_position + 1) % buffer->capacity;
    
    errno = EXIT_SUCCESS;
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t* buffer, buffer_value_t value)
{
    if (write_position_reached_read_position(buffer))
    {
        buffer_value_t garbage;
        read(buffer, &garbage);
    }
    
    return write(buffer, value);
}

int16_t read(circular_buffer_t* buffer, buffer_value_t* value)
{
    if (buffer->usage <= 0)
    {
        errno = ENODATA;
        return EXIT_FAILURE;
    }

    *value = buffer->values[buffer->read_position];

    buffer->usage--;
    
    buffer->read_position = (buffer->read_position + 1) % buffer->capacity;

    errno = EXIT_SUCCESS;
    return EXIT_SUCCESS;
}

circular_buffer_t* new_circular_buffer(size_t capacity)
{
    circular_buffer_t* buffer = malloc(sizeof(circular_buffer_t) + capacity * sizeof(buffer_value_t));
    
    if (!buffer)
    {
        return NULL;
    }
    
    buffer->capacity = capacity;
    buffer->usage = 0;
    buffer->write_position = 0;
    buffer->read_position = 0;

    return buffer;
}

void delete_buffer(circular_buffer_t* buffer)
{
    if (buffer != NULL)
    {
        free(buffer);
    }
}

void clear_buffer(circular_buffer_t* buffer)
{
    buffer->usage = 0;
    buffer->write_position = 0;
    buffer->read_position = 0;
}

static bool write_position_reached_read_position(circular_buffer_t* buffer)
{
    return buffer->write_position == buffer->read_position;
}
