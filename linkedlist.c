#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

/* ============================================================================
create
============================================================================ */

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

/* ============================================================================
edit
============================================================================ */

void appendNode(struct list *l, struct node* n)
{
  if (!l->head)
  {
    l->head = n;
    return;
  }

  struct node *ptr = l->head;
  while (ptr->next) { ptr = ptr->next; }
  ptr->next = n;
}

/* Add to the end of the list */
void append(struct list *l, int val)
{
  struct node *link = (struct node *)malloc(sizeof(struct node));
  link->val = val;
  link->next = NULL;

  appendNode(l, link);
}

/* ============================================================================
info
============================================================================ */

int length(struct list *l)
{
  struct node *ptr = l->head;
  int len = 0;
  
  while (ptr->next)
  {
    len++;
    ptr = ptr->next;
  }

  return len;
}

/* ============================================================================
display
============================================================================ */

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

/* ============================================================================
delete
============================================================================ */

void freeListOnly(struct list *l)
{
  free(l);
}

void freeList(struct list *l)
{
  if (l->head) { freeNode(l->head); }

  free(l);
}

void freeNode(struct node *n)
{
  if (n->next) { freeNode(n->next); }

  free(n);
}
