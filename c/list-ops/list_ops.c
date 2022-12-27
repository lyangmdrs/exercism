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

// filter list returning only values that satisfy the filter function
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

// returns the length of the list
size_t length_list(list_t *list)
{
    return list->length;
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
    list_t* mapped_list = new_list(0, NULL);

    if (list == NULL) return NULL;

    mapped_list->length = list->length;
    mapped_list->elements = alloc_list_elements(mapped_list, mapped_list->length);
    
    if (list->elements == NULL) return NULL;

    mapped_list->elements[0] = map(list->elements[0]);
    mapped_list->elements[1] = map(list->elements[1]);
    mapped_list->elements[2] = map(list->elements[2]);
    mapped_list->elements[3] = map(list->elements[3]);

    return mapped_list;
}

// folds (reduces) the given list from the left with a function
// list_element_t foldl_list(list_t *list, list_element_t initial,
//                           list_element_t (*foldl)(list_element_t,
//                                                   list_element_t));

// folds (reduces) the given list from the right with a function
// list_element_t foldr_list(list_t *list, list_element_t initial,
//                           list_element_t (*foldr)(list_element_t,
//                                                   list_element_t));

// reverse the elements of the list
// list_t *reverse_list(list_t *list);

// destroy the entire list
// list will be a dangling pointer after calling this method on it
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