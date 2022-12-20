#include "circular_buffer.h"

int16_t write(circular_buffer_t* buffer, buffer_value_t value)
{
    
    if (buffer->values[buffer->next_position] != 0)
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
    
    if (buffer->values[buffer->oldest_value] == 0)
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
    circular_buffer_t* buffer;
    buffer = (circular_buffer_t*)malloc(sizeof(circular_buffer_t));
    
    if (!buffer)
    {
        return NULL;
    }
    
    buffer->capacity = capacity;
    buffer->next_position = 0;
    buffer->oldest_value = 0;

    buffer_memmory_allocation(buffer);

    if (!buffer->values)
    {
        return NULL;
    }

    clear_buffer(buffer);

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
    for (size_t i = 0; i < buffer->capacity; i++)
    {
        buffer->values[i] = 0;
    }
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
