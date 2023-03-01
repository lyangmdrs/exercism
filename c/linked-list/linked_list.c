#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

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

list_t *list_create(void)
{
   list_t *new_list = malloc(sizeof(list_t));
   new_list->first = malloc(sizeof(list_node_t));
   new_list->last = malloc(sizeof(list_node_t));

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
   list_node_t *new_node = malloc(sizeof(list_node_t));

   list->last->prev->next = new_node;
   new_node->prev = list->last->prev;
   list->last->prev = new_node;
   new_node->next = list->last;

   new_node->data = item_data;
   list->count++;
}

ll_data_t list_pop(list_t *list)
{
   list_node_t *node = list->last->prev;   
   ll_data_t data = unlink_node(node, list);

   return data;
}

void list_unshift(list_t *list, ll_data_t item_data)
{
   list_node_t *new_node = malloc(sizeof(list_node_t));
   
   list->first->next->prev = new_node;
   new_node->next = list->first->next;
   list->first->next = new_node;
   new_node->prev = list->first;

   new_node->data = item_data;
   list->count++;
}

ll_data_t list_shift(list_t *list)
{
   list_node_t *node = list->first->next;
   ll_data_t data = unlink_node(node, list);
   
   return data;
}

void list_delete(list_t *list, ll_data_t data)
{
   list_node_t *node = list->last->prev;
  
   while (node->prev)
   {     
      if (node->data == data)
      {
         unlink_node(node, list);
         break;
      }

      node = node->prev;
   }
}

void list_destroy(list_t *list)
{
   struct list_node *node;
   node = list->first->next;

   while (node->next)
   {
      struct list_node *free_node = node;
      node = free_node->next;
      free(free_node);
   }

   free(list->first);
   free(list->last);
   free(list);
}
