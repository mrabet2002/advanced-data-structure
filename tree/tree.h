#include <stdio.h>
#include <stdlib.h>

#ifndef TREE_H
#define TREE_H

typedef struct Node Node;

typedef enum boolean
{
    FALSE,
    TRUE
} boolean;

struct Node
{
    int value;
    Node *left;
    Node *right;
};

// Tree un pointeur vers le node racine.
typedef Node *Tree;

Node *createNode(int);
Tree createTree();
void insert(Tree *, int);
Tree add(int, Tree, Tree);
void print(Tree, int);
void printOrdre(Tree);
void printPreOrdre(Tree);
void printPostOrdre(Tree);
int numNodes(Tree);
int numLeafs(Tree);
boolean isLeaf(Tree);
Node **search(Tree *, int);
boolean remove(Tree *, int);
boolean exists(Tree, int);

#endif