#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <string.h>

#include "node.h"

struct list
{
  struct node *head;
};

void printList(struct list *l)
{
  printf("[");

  struct node *ptr = l->head;
  while (ptr)
  {
    printf("%d", ptr->val);
    if (ptr->next) { printf(","); }
    ptr = ptr->next;
  }

  printf("]\n");
}

/* Add to the end of the list */
void append(struct list *l, int val)
{
  struct node *link = (struct node *)malloc(sizeof(struct node));
  link->val = val;
  link->next = NULL;

  if (!l->head) {
    l->head = link;
    return;
  }

  struct node *ptr = l->head;
  while (ptr->next) { ptr = ptr->next; }
  ptr->next = link;
}

struct list * createList()
{
  struct list *l = (struct list *)malloc(sizeof(struct list));
  return l;
}

struct list * createListFromString(char *str)
{
  struct list *l = createList();
  
  char *num;
  int val;

  num = strtok(str, ",");
  while (num != NULL)
  {
    sscanf(num, "%d", &val);
    append(l, val);

    num = strtok(NULL, ",");
  }

  return l;
}

void freeList(struct list *l)
{
  if (l->head) { freeNode(l->head); }

  free(l);
}

#endif
