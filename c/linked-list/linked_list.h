#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef int ll_data_t;
typedef struct list list_t;

// constructs a new (empty) list
list_t *list_create(void);

// counts the items on a list
size_t list_count(const list_t *list);

// inserts item at back of a list
void list_push(list_t *list, ll_data_t item_data);

// removes item from back of a list
ll_data_t list_pop(list_t *list);

// inserts item at front of a list
void list_unshift(list_t *list, ll_data_t item_data);

// removes item from front of a list
ll_data_t list_shift(list_t *list);

// deletes a node that holds the matching data
void list_delete(list_t *list, ll_data_t data);

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(list_t *list);

#endif
