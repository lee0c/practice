#ifndef BTREE_H
#define BTREE_H

/* Tree and node structs */
struct node
{
    int val;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct btree
{
    struct node *root;
};

/* Create an node with given val and parent */
struct node * createNode(int val, struct node *parent);
/* Add a child node to parent or return NULL */
struct node * addChild(int val, struct node *parent);

/* Create an empty btree */
struct btree * createBtree();
/* Create the sample btree */
struct btree * createBtreeSample();

/* Find the given node in the tree */
struct node * find(struct node *n);
/* Find the node with the given value in the tree */
struct node * findByVal(struct btree *b, int val);

/* Print the btree using pre-order traversal */
void printBtree(struct btree *b);
/* Print a node and its left and right children */
void printNode(struct node *n);

/* Free only the btree struct */
void freeBtreeOnly(struct btree *b);
/* Free a btree struct and its nodes */
void freeBtree(struct btree *b);
/* Free a node */
void freeNode(struct node *n);

#endif