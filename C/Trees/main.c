#include<stdio.h>
#include"myTrees.h"
void main(){

    //Binary Search Tree
    Node *tree = NULL;

    tree = insertBST(5,tree);
    tree = insertBST(4,tree);
    tree = insertBST(8,tree);
    tree = insertBST(6,tree);
    tree = insertBST(9,tree);

    printf("The tree is: ");
    traverseBST(tree);
    printf("\n");

    tree = removeBST(6, tree);

    printf("After removing 6 the tree is: ");
    traverseBST(tree);
    printf("\n");
}