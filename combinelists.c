#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

/* Problem statement: Given two sorted linked lists, combine into one sorted
linked list by splicing the nodes together 

CURRENTLY BROKEN*/

/* Compile with: 
gcc -Wall combinelists.c linkedlist.c -o combinelists.o
*/

int main (int argc, char* argv[])
{
  if (argc != 3)
  {
    printf("Usage: ./combinelists <l1 separated by commas> <l2 separated by commas>\n");
    return EXIT_FAILURE;
  }

  struct list *l1 = createListFromString(argv[1]);
  struct list *l2 = createListFromString(argv[2]);

  printList(l1);
  printList(l2);

  struct list *l_out = createList();

  struct node *p1 = l1->head;
  struct node *p2 = l2->head;
  struct node *next;

  while (p1 && p2)
  {
    if (p1->val <= p2->val)
    {
      next = p1;
      p1 = p1->next;
    }
    else
    {
      next = p2;
      p2 = p2->next;
    }
    appendNode(l_out, next);
  }

  if (p1) { appendNode(l_out, p1); }
  if (p2) { appendNode(l_out, p2); }

  printList(l_out);

  freeListOnly(l1);
  freeListOnly(l2);
  freeList(l_out);

  return EXIT_SUCCESS;
}
