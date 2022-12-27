#include "list_ops.h"

static list_t* alloc_list(list_t* list);
static list_element_t* alloc_list_elements(list_t* list, size_t length);

list_t *new_list(size_t length, list_element_t elements[])
{
    list_t* list = NULL;
    list = alloc_list(list);

    if (list == NULL) return NULL;

    list->length = length;
    
    list->elements = alloc_list_elements(list, list->length);

    if (list->elements == NULL) return NULL;

    memcpy(list->elements, elements, sizeof(list_element_t) * length);

    return list;
}

list_t* append_list(list_t* list1, list_t* list2)
{
    list_t* list = new_list(0, NULL);

    if (list == NULL) return NULL;
    
    size_t output_list_length = list1->length + list2->length;
    list->length = output_list_length;
    list->elements = alloc_list_elements(list, list->length);
    
    if (list->elements == NULL) return NULL;

    memcpy(list->elements, list1->elements, list1->length * sizeof(*list->elements));
    memcpy(&list->elements[list1->length], list2->elements, list2->length * sizeof(*list->elements));

    return list;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t))
{
    list_t* filtered_list = new_list(0, NULL);
    
    if (list == NULL) return NULL;

    for (size_t i = 0; i < list->length; i++)
    {
        if(filter(list->elements[i]))
        {
            filtered_list->length++;
            filtered_list->elements = realloc(list->elements,
                                              sizeof(list_element_t) * list->length);
            
            if (filtered_list->elements == NULL)
            {
                delete_list(filtered_list);
                return NULL;
            }

            filtered_list->elements[filtered_list->length - 1] = list->elements[i];
        }
    }

    return filtered_list;
}

size_t length_list(list_t *list)
{
    return list->length;
}

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
    list_t* mapped_list = new_list(0, NULL);

    if (list == NULL) return NULL;

    mapped_list->length = list->length;
    mapped_list->elements = alloc_list_elements(mapped_list, mapped_list->length);
    
    if (list->elements == NULL) return NULL;

    for (size_t i = 0; i < list->length; i++)
    {
        mapped_list->elements[i] = map(list->elements[i]);
    }

    return mapped_list;
}

list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t))
{
    if (list->length == 0)
    {
        return initial;
    }

    list_element_t result = initial;

    for (size_t i = 0; i < list->length; i++)
    {
        result = foldl(list->elements[i], result);
    }

    return result;
}

list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t))
{
    if (list->length == 0)
    {
        return initial;
    }

    list_element_t result = initial;

    for (size_t i = list->length; i > 0; i--)
    {
        result = foldr(list->elements[i - 1], result);
    }

    return result;
}

list_t *reverse_list(list_t *list)
{
    list_t* reversed = new_list(0, NULL);

    if (list == NULL) return NULL;

    reversed->length = list->length;
    reversed->elements = alloc_list_elements(reversed, reversed->length);
    
    if (list->elements == NULL) return NULL;

    size_t maximum_index = list->length - 1;

    for (size_t i = 0; i < list->length; i++)
    {
        reversed->elements[maximum_index - i] = list->elements[i];
    }

    return reversed;
}

void delete_list(list_t *list)
{
    if (list != NULL)
    {
        free(list);
    }
}

static list_t* alloc_list(list_t* list)
{
    list = malloc(sizeof(list_t));

    if (list == NULL)
    {
        return NULL;
    }

    return list;
}

static list_element_t* alloc_list_elements(list_t* list, size_t length)
{
    list->elements = malloc(sizeof(list_element_t) * length);

    if (list->elements == NULL)
    {
        delete_list(list);
        return NULL;
    }

    return list->elements;    
}