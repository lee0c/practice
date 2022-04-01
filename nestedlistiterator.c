#include <stdio.h>
#include <stdlib.h>

#include "debug.h"

/* Problem statement: */

/* Compile with: 
gcc -Wall nestedlistiterator.c -o nestedlistiterator.o

Toggle debug mode in debug.h
*/

int main (int argc, char* argv[])
{
  if (argc != /* val */)
  {
    printf("Usage: ");
    return EXIT_FAILURE;
  }

/*
  struct NestedIterator *i = nestedIterCreate(nestedList, nestedListSize);
  while (nestedIterHasNext(i)) printf("%d\n", nestedIterNext(i));
  nestedIterFree(i);
*/

  return EXIT_SUCCESS;
}

/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */
struct NestedIterator
{
  struct NestedInteger** list;
  int length, index;
  struct NestedIterator* child;
};

struct NestedIterator *nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize)
{
  struct NestedIterator *iter = (struct NestedIterator *)malloc(sizeof(struct NestedIterator));
  
  iter->list = nestedList;
  iter->length = nestedListSize;
  iter->index = 0;
  iter->child = NULL;

  return iter;
}

bool nestedIterHasNext(struct NestedIterator *iter)
{
  while(1)
  {
    /* If there's a child iterator, ask it first */
    if (iter->child) 
    {
      if (nestedIterHasNext(iter->child)) return true;

      /* If it has nothing next we can delete it */
      nestedIterFree(iter->child);
      iter->child = NULL;
      /* and move on to the next item in the list */
      iter->index++;
    }

    /* If no child, check if we still have items in our list */
    if (iter->index >= iter->length) return false;

    /* If we still have items, check type of next item. Integers are easy to
    manage and guarantee we have another item */
    if (NestedIntegerIsInteger(iter->list[iter-index])) return true;

    /* Lists require we create a child to protect against empty list cases
    such as [1, []] - there would be a list item but no further numbers
    (not actually sure this is possible) */
    struct NestedInteger** nestedList = NestedIntegerGetList(iter->list[iter-index]);
    int nestedListSize = NestedIntegerGetListSize(iter->list[iter-index]);
    iter->child = nestedIterCreate(nestedList, nestedListSize);
  }
}

int nestedIterNext(struct NestedIterator *iter)
{
  if (iter->child) return nestedIterNext(iter->child);

  /* Since we checked in hasNext(), we know this is an int - otherwise
  we would have a child */
  int next = NestedIntegerGetInteger(iter->list[iter->index]);
  iter->index++;
  return next;
}
/** Deallocates memory previously allocated for the iterator */
void nestedIterFree(struct NestedIterator *iter) {
  if (iter->child) nestedIterFree(iter->child);

  free(iter);
}