#ifndef NODE_H
#define NODE_H

struct node
{
  int val;
  struct node *next;
};

void freeNode(struct node *n)
{
  if (n->next) { freeNode(n->next); }

  free(n);
}

#endif
