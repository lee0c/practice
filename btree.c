#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btree.h"

/* ============================================================================
create
============================================================================ */

struct node * createNode(int val, struct node *parent)
{
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->val = val;
  n->parent = parent;
  return n;
}

struct node * addChild(int val, struct node *parent)
{
  struct node *n = createNode(val, parent);
  if (parent->left) parent->right = n;
  else parent->left = n;
  return n;
}



struct btree * createBtree()
{
  struct btree *b = (struct btree *)malloc(sizeof(struct btree));
  b->root = NULL;
  return b;
}

struct btree * createBtreeSample()
{
  struct btree *b = createBtree();
  b->root = createNode(3, NULL);

  struct node *l  = addChild(5, b->root);
  struct node *r = addChild(1, b->root);

  struct node *ll = addChild(6, l);
  struct node *lr = addChild(2, l);
  struct node *rl = addChild(0, r);
  struct node *rr = addChild(8, r);

  struct node *lrl = addChild(7, lr);
  struct node *lrr = addChild(4, lr);

  return b;
}

/* ============================================================================
search
============================================================================ */

struct node * find(struct btree *b, struct node *n)
{

}

struct node * findByVal(struct btree *b, int val)
{

}


/* ============================================================================
display
============================================================================ */

void printBtree(struct btree *b)
{
  printf("Printing tree...\n");
  if (b->root) printNode(b->root);
  else printf("Empty tree\n");
  printf("Tree printed\n");
}

void printNode(struct node *n)
{
  printf("[%d", n->val);
  if (n->left)  printf(" l:%d", n->left->val);
  if (n->right) printf(" r:%d", n->right->val);
  printf("]\n");

  if (n->left)  printNode(n->left);
  if (n->right) printNode(n->right);
}

/* ============================================================================
delete
============================================================================ */
void freeBtreeOnly(struct btree *b)
{
  free(b);
}

void freeBtree(struct btree *b)
{
  if (b->root) freeNode(b->root);
  free(b);
}

void freeNode(struct node *n)
{
  if (n->left)  freeNode(n->left);
  if (n->right) freeNode(n->right);

  free(n);
}
