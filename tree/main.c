#include"tree.h"


int main(int argc, char const *argv[])
{
    printf("Start main\n------------------\n\n");
    Tree tree = NULL;
    insert(&tree,100);
    insert(&tree,50);
    insert(&tree,15);
    insert(&tree,200);
    print(tree,0);
    print(tree,1);
    print(tree,-1);
    return 0;
}
