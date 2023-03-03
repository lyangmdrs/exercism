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
   struct list_node *first, *last;
   size_t count;
};

static ll_data_t unlink_node(list_node_t *node, list_t *list)
{
   ll_data_t data = node->data;
   node->next->prev = node->prev;
   node->prev->next = node->next;
   list->count--;

   free(node);

   return data;
}

static bool insert_node(list_node_t *preceding, list_t *list, ll_data_t item_data)
{
   list_node_t *new_node = malloc(sizeof(list_node_t));

   if (!new_node) return INSERT_NODE_FAIL;
   
   new_node->prev = preceding->prev;
   preceding->prev = new_node;
   new_node->prev->next = new_node;
   new_node->next = preceding;
   new_node->data = item_data;

   list->count++;

   return INSERT_NODE_SUCCESS;
}

list_t *list_create(void)
{
   list_t *new_list = malloc(sizeof(list_t));
   if (!new_list) return NULL;

   static list_node_t dummy_head;
   new_list->first = &dummy_head;
   
   static list_node_t dummy_tail;
   new_list->last = &dummy_tail;

   new_list->first->prev = NULL;
   new_list->first->next = new_list->last;   
   new_list->last->prev = new_list->first;
   new_list->last->next = NULL;
   new_list->count = 0;

   return new_list;
}

size_t list_count(const list_t *list)
{
   return list->count;
}

void list_push(list_t *list, ll_data_t item_data)
{
   bool success = insert_node(list->last, list, item_data);

   if (!success)
   {
      list_destroy(list);
      list = NULL;
   }
}

ll_data_t list_pop(list_t *list)
{
   ll_data_t data = unlink_node(list->last->prev, list);

   return data;
}

void list_unshift(list_t *list, ll_data_t item_data)
{
   bool success = insert_node(list->first->next, list, item_data);

   if (!success)
   {
      list_destroy(list);
      list = NULL;
   }
}

ll_data_t list_shift(list_t *list)
{
   ll_data_t data = unlink_node(list->first->next, list);
   
   return data;
}

void list_delete(list_t *list, ll_data_t data)
{
   list_node_t *node = list->first->next;
  
   while (node->next)
   {     
      if (node->data == data)
      {
         unlink_node(node, list);
         break;
      }

      node = node->next;
   }
}

void list_destroy(list_t *list)
{
   while (list->first->next != list->last)
   {
      list_pop(list);
   }

   free(list);
}
