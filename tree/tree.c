#include "tree.h"

Node *createNode(int value)
{
    // Allocation du noeud qui compose l'arbre
    Node *node = (Node *)malloc(sizeof(Node));
    // Initialistion des valeur de l'arbre allouer en memoire.
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * Initialise un arbre avec la valeur : value
 * @param value la valeur du noeud.
 */
Tree add(int value, Tree t1, Tree t2)
{
    // Creation d'une arbre (Le noeud racin avec la valeur passer en arguments)
    Node *root = createNode(value);
    root->left = t1;
    root->right = t2;
    printf("%d", root->left->value);
    return root;
}

void print(Tree tree, int ordre)
{
    switch (ordre)
    {
    case 0:
        printOrdre(tree);
        break;
    case 1:
        printPostOrdre(tree);
        break;
    case -1:
        printPreOrdre(tree);
        break;
    }
    printf("\n");
}

int numNodes(Tree tree)
{
    if (!tree)
        return 0;
    return 1 + numNodes(tree->left) + numNodes(tree->right);
}

int numLeafs(Tree tree)
{
    if (!tree)
        return 0;
    if (isLeaf(tree))
        return 1;
    return numLeafs(tree->left) + numLeafs(tree->right);
}

boolean isLeaf(Tree tree)
{
    return !tree->left && !tree->right;
}

Node **search(Tree *rootPtr, int value)
{
    if (!(*rootPtr))
        return NULL;
    if ((*rootPtr)->value < value)
        return search(&(*rootPtr)->right, value);
    if ((*rootPtr)->value > value)
        return search(&(*rootPtr)->left, value);
    return rootPtr;
}

boolean remove(Tree *rootPtr, int value)
{
    Node **foundNodePtr = search(rootPtr, value);
    if (!foundNodePtr)
        return FALSE;
    
}

boolean exists(Tree tree, int value)
{
    if (!tree)
        return FALSE;
    if (tree->value == value)
        return TRUE;
    return exists(tree->left, value) || exists(tree->right, value);
}

void insert(Tree *ptr_tree, int value)
{
    if (*ptr_tree == NULL)
    {
        *ptr_tree = createNode(value);
    }
    else
    {
        if ((*ptr_tree)->value <= value)
            insert(&(*ptr_tree)->right, value);
        else
            insert(&(*ptr_tree)->left, value);
    }
}

void printOrdre(Tree tree)
{
    if (tree)
    {
        printOrdre(tree->left);
        printf("%d ", tree->value);
        printOrdre(tree->right);
    }
}

void printPreOrdre(Tree tree)
{
    if (tree)
    {
        printPreOrdre(tree->left);
        printPreOrdre(tree->right);
        printf("%d ", tree->value);
    }
}

void printPostOrdre(Tree tree)
{
    if (tree)
    {
        printf("%d ", tree->value);
        printPostOrdre(tree->left);
        printPostOrdre(tree->right);
    }
}
