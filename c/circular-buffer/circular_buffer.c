#include "circular_buffer.h"

int16_t write(circular_buffer_t* buffer, buffer_value_t value)
{
    buffer->values[0] = value;
    errno = EXIT_SUCCESS;
    return 0;
}

int16_t overwrite(circular_buffer_t* buffer, buffer_value_t value)
{
    circular_buffer_t aux_buffer = {0};
    int16_t status = value;

    buffer_memmory_allocation(buffer, 1);

    *aux_buffer.values = value;
    
    buffer->values = aux_buffer.values;
    return status;
}

int16_t read(circular_buffer_t* buffer, buffer_value_t* value)
{
    *value = buffer->values[0];
    
    if (buffer->values[0] == 0)
    {
        errno = ENODATA;
        return EXIT_FAILURE;
    }
    
    errno = EXIT_SUCCESS;
    return EXIT_SUCCESS;
}

circular_buffer_t* new_circular_buffer(size_t capacity)
{
    static circular_buffer_t new_buffer = {0};
    buffer_memmory_allocation(&new_buffer, capacity);
    return &new_buffer;
}

void delete_buffer(circular_buffer_t* buffer)
{
    buffer->values = 0;
}

void buffer_memmory_allocation(circular_buffer_t* buffer, size_t capacity)
{
    buffer->values = (buffer_value_t*) malloc(capacity * sizeof(buffer_value_t));
}