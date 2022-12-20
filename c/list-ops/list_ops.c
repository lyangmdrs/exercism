#include "list_ops.h"

list_t *new_list(size_t length, list_element_t elements[])
{
    list_t* list;
    
    list = (list_t*)malloc(sizeof(list_t) + sizeof(list_element_t) * length);

    if(!list)
    {
        return NULL;
    }

    list->length = length;
    
    memcpy(list->elements, elements, length);
    
    for (size_t i = 0; i < list->length; i++)
    {
        list->elements[i] = elements[i];
    }

    return list;
}

list_t* append_list(list_t* list1, list_t* list2)
{
    list_t* list;
    size_t output_list_length = list1->length + list2->length;
    list = (list_t*)malloc(sizeof(list_t) + output_list_length * sizeof(list_element_t));

    if (!list)
    {
        return NULL;
    }
    
    list->length = output_list_length;

    return list;
}

// filter list returning only values that satisfy the filter function
// list_t *filter_list(list_t *list, bool (*filter)(list_element_t));

// returns the length of the list
// size_t length_list(list_t *list);

// return a list of elements whose values equal the list value transformed by
// the mapping function
// list_t *map_list(list_t *list, list_element_t (*map)(list_element_t));

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
    free(list);
}