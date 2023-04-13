# Advanced Data Structure

---

## Trees

---

**Applications:**

- Recherche : Arbre binaire de recherche

- Prise de déscision : Arbre de déscision

- Compilation (analyse syntaxique (Arbre syntaxique))  

- Algo de compression de données

## Exemple d'arbre binaire : 

<figure style="text-align:center">
  <img
  src="../StructAvancer/assets/images/bTree.png"
  alt="Arbre binaire">
  <figcaption>Arbre binaire 1</figcaption>
</figure>

<!-- ![Arbre binaire!](../StructAvancer/assets/images/bTree.png)
> Arbre 1 -->

## Parcours en profondeur

### Parcours  postfixé

```C++
void print(Tree tree)
{
    // Si l'arbre est vide rien ne va etre afficher
    if (tree)
    {
        // Affichage de la racine
        printf("%d -", tree->value);
        print(tree->left);
        print(tree->right);
    }
}
```
> **Input :** Arbre 1
>
> **Output :** A - B - D - C - E - F -
### Parcours  infixé

```C++
void print(Tree tree)
{
    if (tree)
    {
        print(tree->left);
        printf("%d -", tree->value);
        print(tree->right);
    }
}
```

## Parcours en largeur

```C++
void parcoursLargeur(Tree tree)
{
    File
    if (tree)
    {
        print(tree->left);
        printf("%d\n", tree->value);
        print(tree->right);
    }
    return search(tree->left, value) || search(tree->right, value);
}
```

## Recherche

```C++
Tree *search(Tree *rootPtr, int value)
{
    if (!(*rootPtr))
        return NULL;
    if ((*rootPtr)->value < value)
        return search(&(*rootPtr)->right, value);
    if ((*rootPtr)->value > value)
        return search(&(*rootPtr)->left, value);
    return rootPtr;
}
```