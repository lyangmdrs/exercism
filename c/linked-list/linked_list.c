#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

static void unlink_node(list_node_t *node);

struct list_node
{
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list
{
   struct list_node *first, *last;
   size_t count;
};

static void unlink_node(list_node_t *node)
{
   node->next->prev = node->prev;
   node->prev->next = node->next;

   free(node);
}

struct list *list_create(void)
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

size_t list_count(const struct list *list)
{
   return list->count;
}

void list_push(struct list *list, ll_data_t item_data)
{
   list_node_t *new_node = malloc(sizeof(list_node_t));

   list->last->prev->next = new_node;
   new_node->prev = list->last->prev;
   list->last->prev = new_node;
   new_node->next = list->last;

   new_node->data = item_data;
   list->count++;
}

ll_data_t list_pop(struct list *list)
{
   list_node_t *node = list->last->prev;   
   ll_data_t data = node->data;

   unlink_node(node);
   list->count--;

   return data;
}

void list_unshift(struct list *list, ll_data_t item_data)
{
   list_node_t *new_node = malloc(sizeof(list_node_t));
   
   list->first->next->prev = new_node;
   new_node->next = list->first->next;
   list->first->next = new_node;
   new_node->prev = list->first;

   new_node->data = item_data;
   list->count++;
}

ll_data_t list_shift(struct list *list)
{
   list_node_t *node = list->first->next;
   ll_data_t data = node->data;
   
   unlink_node(node);
   list->count--;
   
   return data;
}

void list_delete(struct list *list, ll_data_t data)
{
   list_node_t *node = list->last->prev;
  
   while (node->prev)
   {     
      if (node->data == data)
      {
         unlink_node(node);
         list->count--;
         break;
      }

      node = node->prev;
   }
}

void list_destroy(struct list *list)
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
