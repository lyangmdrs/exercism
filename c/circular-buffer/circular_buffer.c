#include "circular_buffer.h"

int16_t write(circular_buffer_t* buffer, buffer_value_t value)
{
    if (!is_next_position_writable(buffer))
    {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    buffer->values[buffer->next_position] = value;
    
    if (is_next_position_incrementable(buffer))
        buffer->next_position++;
    else
        buffer->next_position = 0;
    
    errno = EXIT_SUCCESS;
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t* buffer, buffer_value_t value)
{
    buffer->values[buffer->next_position] = value;
    
    if (next_position_reached_oldest_value(buffer))
    {
        if (is_oldest_value_incrementable(buffer))
            buffer->oldest_value++;
        else
            buffer->oldest_value = 0;
    }
    
    if (is_next_position_incrementable(buffer))
        buffer->next_position++;
    else
        buffer->next_position = 0;
    
    errno = EXIT_SUCCESS;
    return EXIT_SUCCESS;
}

int16_t read(circular_buffer_t* buffer, buffer_value_t* value)
{
    *value = buffer->values[buffer->oldest_value];
    
    if (!is_there_data_to_be_read(buffer))
    {
        errno = ENODATA;
        return EXIT_FAILURE;
    }
    
    buffer->values[buffer->oldest_value] = 0;
    
    if (is_oldest_value_incrementable(buffer))
        buffer->oldest_value++;
    else
        buffer->oldest_value = 0;

    errno = EXIT_SUCCESS;
    return EXIT_SUCCESS;
}

circular_buffer_t* new_circular_buffer(size_t capacity)
{
    static circular_buffer_t new_buffer = {0};
    new_buffer.capacity = capacity;
    buffer_memmory_allocation(&new_buffer);
    new_buffer.oldest_value = 0;
    new_buffer.next_position = 0;
    return &new_buffer;
}

void delete_buffer(circular_buffer_t* buffer)
{
    buffer->values = 0;
}

void clear_buffer(circular_buffer_t* buffer)
{
    memset(buffer->values, 0, buffer->capacity);
}

void buffer_memmory_allocation(circular_buffer_t* buffer)
{
    buffer->values = (buffer_value_t*) malloc(buffer->capacity * sizeof(buffer_value_t));
}

bool is_next_position_writable(circular_buffer_t* buffer)
{
    if (buffer->values[buffer->next_position] == 0)
        return true;

    return false;
}

bool is_next_position_incrementable(circular_buffer_t* buffer)
{
    if (buffer->capacity > (buffer->next_position + 1))
        return true;

    return false;
}

bool is_there_data_to_be_read(circular_buffer_t* buffer)
{
    if (buffer->values[buffer->oldest_value] != 0)
        return true;
    
    return false;
}

bool is_oldest_value_incrementable(circular_buffer_t* buffer)
{
    if (buffer->capacity > (buffer->oldest_value + 1))
        return true;
    
    return false;
}

bool next_position_reached_oldest_value(circular_buffer_t* buffer)
{
    if (buffer->next_position == buffer->oldest_value)
        return true;
    
    return false;
}
