#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

// static void print_list(struct list *list);
static void unlink_node(list_node_t *node);

struct list_node
{
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list
{
   struct list_node *first, *last;
};

// static void print_list(struct list *list)
// {
//    struct list_node *node_to_print = list->first->next;
//    int node_count = 1;
//    printf("\tPRINT LINKED LIST\n");
//    printf("\tList head at %p\n", (void *)list->first);
//   
//    while (node_to_print->next)
//    {
//       printf("\tData of node #%d: %d (node at %p)\n", node_count, node_to_print->data, (void *)node_to_print);
//      
//       if (node_to_print->next->next == NULL)
//       {
//          break;
//       }
//
//       node_to_print = node_to_print->next;
//       node_count++;
//    }
//   
//    printf("\tList tail at %p\n", (void *)list->last);
//   
// }

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

   // printf("\tLIST CREATED!\n");
   // printf("\tList head at %p\n", (void *)new_list->first);
   // printf("\tList tail at %p\n", (void *)new_list->last);

   return new_list;
}

size_t list_count(const struct list *list)
{
   size_t s = 0;
   if (list) {s = 1;}
   return s;
}

void list_push(struct list *list, ll_data_t item_data)
{
   list_node_t *new_node = malloc(sizeof(list_node_t));

   list->last->prev->next = new_node;
   new_node->prev = list->last->prev;
   list->last->prev = new_node;
   new_node->next = list->last;

   new_node->data = item_data;

   // printf("\tNODE PUSHED!\n");
   // print_list(list);
}

ll_data_t list_pop(struct list *list)
{
   // printf("\tNODE POP!\n");
   
   list_node_t *node = list->last->prev;
   
   // printf("\tPop node at %p with data: %d\n", (void *) node, node->data);
   
   ll_data_t data = node->data;
   // node->next->prev = node->prev;
   // node->prev->next = node->next;
   // free(node);
   unlink_node(node);
   // print_list(list);

   return data;

}

void list_unshift(struct list *list, ll_data_t item_data)
{
   if ((list != NULL) && (item_data)) {}
}

ll_data_t list_shift(struct list *list)
{
   list_node_t *node = list->first->next;
   ll_data_t data = node->data;
   
   unlink_node(node);
   
   return data;
}

void list_delete(struct list *list, ll_data_t data)
{
   if (list) {}

   if (data) {}
}

void list_destroy(struct list *list)
{
   struct list_node *node;
   node = list->first->next;

   // printf("\n\tLIST DESTROY!\n");
   while (node->next)
   {
      struct list_node *free_node = node;
      node = free_node->next;
      // printf("\tFree node at %p with data %d\n", (void *)node, node->data);
      free(free_node);
   }

   // printf("\tFree list head at: %p\n", (void *)list->first);
   free(list->first);

   // printf("\tFree list tail at: %p\n", (void *)list->last);
   free(list->last);

   free(list);

}
