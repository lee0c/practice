#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/* Node and list structs */
struct node
{
  int val;
  struct node *next;
};

struct list
{
  struct node *head;
};

/* Create an empty list */
struct list * createList();
/* Create a list from a string formatted #,#,#... */
struct list * createListFromString(char *str);

/* Add a value to the end of the list */
void append(struct list *l, int val);
/* Append by passing a pre-created node */
void appendNode(struct list *l, struct node* n);

/* Print a list */
void printList(struct list *l);

/* Free a list struct but not its nodes */
void freeListOnly(struct list *l);
/* Free a list struct and all nodes */
void freeList(struct list *l);
/* Free a node */
void freeNode(struct node *n);

#endif
