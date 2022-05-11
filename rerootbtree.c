#include <stdio.h>
#include <stdlib.h>

#include "btree.h"
#include "debug.h"

/* Problem statement: */

/* Compile with: 
gcc -Wall rerootbtree.c -o rerootbtree.o

Toggle debug mode in debug.h
*/

int main (int argc, char* argv[])
{
  if (argc != 1 && argc != 3)
  {
    printf("Usage:\n");
    printf("1:\t./rerootbtree\n");
    printf("2:\t./rerootbtree [root,root_left,root_right,root_left_left,...] leaf\n");
    return EXIT_FAILURE;
  }

  struct btree *b;
  struct node *leaf;

  if (argc == 1)
  {
    /* Manually create a binary tree for testing */
    b = createBtreeSample();
    leaf = b->root->left->right->left;
  }

  if (argc == 3)
  {
    printf("Tree parsing not yet implemented");
    return EXIT_SUCCESS;
  }

  printf("Input:\n");
  printBtree(b);
  printf("\n");

  struct btree *b_new = createBtree();
  b_new->root = leaf;

  struct node *next, *last = NULL;
  struct node *cur = leaf;

  while (cur)
  {
    next = cur->parent;

    if (cur->left  == last) cur->left  = NULL;
    if (cur->right == last) cur->right = NULL;
  
    if (cur->left) cur->right = cur->left;

    cur->left = cur->parent;
    cur->parent = last;

    last = cur;
    cur = next;
  }

  printf("Output:\n");
  printBtree(b_new);

  freeBtree(b_new);
  freeBtreeOnly(b);
  
  return EXIT_SUCCESS;
}
