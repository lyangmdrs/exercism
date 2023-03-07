#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INSERT_NODE_FAIL 0
#define INSERT_NODE_SUCCESS 1

typedef struct list_node
{
   struct list_node *prev, *next;
   ll_data_t data;
} list_node_t;

struct list
{
   list_node_t dummy;
   size_t count;
};

static ll_data_t unlink_node(list_node_t *node, list_t *list)
{
   ll_data_t data = node->data;
   node->next->prev = node->prev;
   node->prev->next = node->next;
   list->count--;

   /* 
    * Excluding unlinked node pointers to ensure there are no
    * elements outside the list point to elements within the list.
   */
   node->next = NULL;
   node->prev = NULL;
   
   free(node);

   return data;
}

static bool insert_node(list_node_t *preceding, list_t *list, ll_data_t item_data)
{
   list_node_t *new_node = malloc(sizeof(list_node_t));

   if (!new_node) return INSERT_NODE_FAIL;
   
   new_node->data = item_data;
   new_node->next = preceding;
   new_node->prev = preceding->prev;
   preceding->prev->next = new_node;
   preceding->prev = new_node;
   list->count++;

   return INSERT_NODE_SUCCESS;
}

list_t *list_create(void)
{
   list_t *new_list = malloc(sizeof(list_t));
   if (!new_list) return NULL;

   new_list->dummy.next = &new_list->dummy;
   new_list->dummy.prev = &new_list->dummy;
   new_list->count = 0;

   return new_list;
}

size_t list_count(const list_t *list)
{
   return list->count;
}

void list_push(list_t *list, ll_data_t item_data)
{
   bool success = insert_node(&list->dummy, list, item_data);

   if (!success)
   {
      list_destroy(list);
      list = NULL;
   }
}

ll_data_t list_pop(list_t *list)
{
   ll_data_t data = unlink_node(list->dummy.prev, list);

   return data;
}

void list_unshift(list_t *list, ll_data_t item_data)
{
   bool success = insert_node(list->dummy.next, list, item_data);

   if (!success)
   {
      list_destroy(list);
      list = NULL;
   }
}

ll_data_t list_shift(list_t *list)
{
   ll_data_t data = unlink_node(list->dummy.next, list);
   
   return data;
}

void list_delete(list_t *list, ll_data_t data)
{
   for (list_node_t *node = list->dummy.next; node != &(list->dummy);
        node = node->next)
   {
      if (node->data == data)
      {  
         unlink_node(node, list);
         break;
      }
   }

}

void list_destroy(list_t *list)
{
   for (list_node_t *node = list->dummy.next; node != &(list->dummy);)
   {
      list_node_t *next = node->next;
      list_shift(list);
      node = next;
   }
   free(list);
}
