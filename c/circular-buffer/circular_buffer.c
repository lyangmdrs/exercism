#include "circular_buffer.h"

int16_t overwrite(circular_buffer_t* buffer, buffer_value_t value)
{
    circular_buffer_t a;
    int16_t status = value;
    a.a = value;
    buffer->a = a.a;
    return status;
}

int16_t read(circular_buffer_t* buffer, buffer_value_t* value)
{
    *value = buffer->a;
    errno = ENODATA;
    return 1;
}

circular_buffer_t* new_circular_buffer(size_t capacity)
{
    static circular_buffer_t a;
    a.a = capacity;
    return &a;
}

void delete_buffer(circular_buffer_t* buffer)
{
    buffer->a = 0;
}