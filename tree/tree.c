#include <stdio.h>
#include <stdlib.h>

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

Node *createNode(int value);
Tree createTree();
Tree add(int, Tree, Tree);
void print(Tree);
int numNodes(Tree);
int numLeafs(Tree);
boolean isLeaf(Tree);
boolean search(Tree, int);

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
Tree createTree()
{
    return NULL;
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

void print(Tree tree)
{
    // Si l'arbre est vide rien ne va etre afficher
    if (tree)
    {
        // Affichage de la racine
        printf("%d\n", tree->value);
        if (tree->left)
            print(tree->left);
        if (tree->right)
            print(tree->right);
    }
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

boolean isLeaf(Tree tree){
    return !tree->left && !tree->right;
}

boolean search(Tree tree, int value)
{
    if (!tree)
        return FALSE;
    if (tree->value == value)
        return TRUE;
    return search(tree->left, value) || search(tree->right, value);
}

int main(int argc, char const *argv[])
{
    Tree t1 = createTree(), t2 = createNode(50), t3 = createNode(67);
    t1 = add(20, t1, t2);
    print(t1);
    return 0;
}
