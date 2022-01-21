#include<stdio.h>
#include "myNodes.h"

void traverse(Node *p){
    if(p != NULL){
        if (p->left != NULL)
        {
            traverse(p->left);
        }

        printf(" %d", p->data);

        if (p->right != NULL)
        {
            traverse(p->right);
        }
    }
    else{
        printf("Treee is empty");
    }
}