#include<stdio.h>
#include<stdlib.h>
#include"myTrees.h"

Node* insertBST(int num, Node *p){

   if(p == NULL) {
      p= (Node *) malloc(sizeof(Node));
      p->data = num;
      p->left = NULL;
      p->right = NULL;
   }
   else if (num < p->data)
   {
       p->left = insertBST(num,p->left);
   }
   else if (num > p->data)
   {
       p->right = insertBST(num,p->right);
   }
   else{
       printf("\nItem already in the tree.");
   }
  return p; 
}

Node* findMin(Node *p){
    if(p != NULL){
        while (p->left != NULL)
        {
            p = p->left;
        }
    }
       return p; 
}

Node* removeBST(int num, Node *p){
    if(p != NULL){
        if(num < p->data){
            p->left = removeBST(num,p->left);
        }
        else if(num > p->data){
            p->right = removeBST(num,p->right);
        }
        else if(p->left == NULL){
            p = p->right;
        }
        else if(p->right == NULL){
            p = p->left;
        }
        else{
            p->data = findMin(p->right)->data;
            p->right = removeBST(p->data, p->right);
        }
    }
    else{
        printf("\nItem not found");
    }
    return p;
}


void traverseBST(Node *p){
    if(p != NULL){
        if (p->left != NULL)
        {
            traverseBST(p->left);
        }

        printf(" %d", p->data);

        if (p->right != NULL)
        {
            traverseBST(p->right);
        }
    }
    else{
        printf("Treee is empty");
    }
}