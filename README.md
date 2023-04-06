# Advanced Data Structure


## Trees
-----
**Applications:**

1. Recherche : Arbre binaire de recherche

2. Prise de déscision : Arbre de déscision

3. Compilation (analyse syntaxique (Arbre syntaxique))  

4. Algo de compression de données

```C++
boolean search(Tree tree, int value)
{
    if (!tree)
        return FALSE;
    if (tree->value == value)
        return TRUE;
    return search(tree->left, value) || search(tree->right, value);
}