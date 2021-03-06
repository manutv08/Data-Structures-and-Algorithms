#include<stdio.h>
#include"myTrees.h"
int main(){

    //Binary Search Tree
    printf("\t\t\tBinary Search Tree\n");
    Node *tree = NULL;

    tree = insertBST(5,tree);
    tree = insertBST(4,tree);
    tree = insertBST(8,tree);
    tree = insertBST(6,tree);
    tree = insertBST(9,tree);

    printf("The tree is: ");
    traverse(tree);
    printf("\n");

    tree = removeBST(6, tree);

    printf("After removing 6 the tree is: ");
    traverse(tree);
    printf("\n\n");

    //AVL Tree
    printf("\t\t\tAVL Search Tree\n");
    tree = NULL;
    bool heightIncreased;

    tree = insertAVL(45, tree, &heightIncreased);
    tree = insertAVL(63, tree, &heightIncreased);
    tree = insertAVL(36, tree, &heightIncreased);
    tree = insertAVL(54, tree, &heightIncreased);
    tree = insertAVL(72, tree, &heightIncreased);
    tree = insertAVL(27, tree, &heightIncreased);
    tree = insertAVL(39, tree, &heightIncreased);
    tree = insertAVL(18, tree, &heightIncreased);

    printf("The AVL tree is: ");
    traverse(tree);
    printf("\n\n");

    //Red Black Tree

    printf("\t\t\tRed Black Tree\n");
    NodeRB *treeRB = NULL;
    int arrayRedBlackTree[] = {10, 18, 7, 15, 16, 30, 25, 40, 60, 2, 1, 70};
    for(int i=0; i < 12; i++)
    {
        NodeRB * newp = createNewNode(arrayRedBlackTree[i]);
         treeRB = insertRedBlack(newp, treeRB);
    }

    printf("The Red Black tree is: ");
    traverse((Node *)treeRB);
    printf("\n\n");
    return 0;
}