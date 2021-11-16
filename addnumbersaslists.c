#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "linkedlist.h"

/* Problem statement: Given two numbers represented as linked lists where the
first item is the tens place, the second the hundreds place, and so on, add
them and return the result in the same format. */

/* Compile with: 
gcc -Wall addnumbersaslists.c -o addnumbersaslists.out
*/

int main (int argc, char* argv[])
{
  if (argc != 3)
  {
    printf("Usage: ./addnumbersaslists <l1 separated by commas> <l2 separated by commas>\n");
    return EXIT_FAILURE;
  }

  struct list *l1 = createListFromString(argv[1]);
  struct list *l2 = createListFromString(argv[2]);

  printList(l1);
  printList(l2);

  struct list *l_out = createList();

  struct node *p1 = l1->head;
  struct node *p2 = l2->head;

  int carry, d1, d2, d_out;
  carry = 0;

  while(p1 || p2 || carry)
  {
    /* If there are still digits in l1, set d1 to the next digit and increment
    the pointer */
    if (p1)
    {
      d1 = p1->val;
      p1 = p1->next;
    } else { d1 = 0; }

    /* Same goes for l2 */
    if (p2)
    {
      d2 = p2->val;
      p2 = p2->next;
    } else { d2 = 0; }

    /* Add digits from l1, l2, and potentially carried tens place from last
    iteration */
    d_out = d1 + d2 + carry;
    carry = d_out / 10;
    d_out = d_out % 10;

    append(l_out, d_out);
  }

  printList(l_out);

  freeList(l1);
  freeList(l2);
  freeList(l_out);

  return EXIT_SUCCESS;
}
