#include<stdio.h>
#include<stdlib.h>
#include "myTrees.h"

NodeRB *createNewNode(int num)
{
    NodeRB *p = (NodeRB *) malloc(sizeof(NodeRB));
    p->data = num;
    p->left = NULL;
    p->right = NULL;
    p->parent = NULL;
    p->color = red;

    return p;
}

NodeRB *leftRotateRB(NodeRB *root, NodeRB *p)
{
    NodeRB *aptr;
    aptr = p->right;
    p->right = aptr->left;

    if(aptr->left != NULL)
    {
        aptr->left->parent = p;
    }

    if(p->parent == NULL)
    {
        root = aptr;
    }
    else
    {
        if((p->parent)->left == p)
        {
            (p->parent)->left = aptr;
        }
        else
        {
            (p->parent)->right = aptr;
        }
    }
    aptr->parent = p->parent;

    aptr->left = p;
    p->parent = aptr;
    return root;
}

NodeRB *rightRotateRB(NodeRB *root, NodeRB *p)
{
    NodeRB *aptr;
    aptr = p->left;
    p->left = aptr->right;

    if(aptr->right != NULL)
    {
        aptr->right->parent = p;
    }

    if(p->parent == NULL)
    {
        root = aptr;
    }
    else
    {
        if((p->parent)->left == p)
        {
            (p->parent)->left = aptr;
        }
        else
        {
            (p->parent)->right = aptr;
        }
    }
    aptr->parent = p->parent;

    aptr->right = p;
    p->parent = aptr;
    return root;
}

NodeRB* insertTree(NodeRB *newp, NodeRB *p){

   if(p == NULL) {
      p= newp;
   }
   else if (newp->data < p->data)
   {
       p->left = insertTree(newp, p->left);
       p->left->parent = p;
   }
   else if (newp->data > p->data)
   {
       p->right = insertTree(newp, p->right);
       p->right->parent = p;
   }
   else{
       printf("\nItem already in the tree.");
   }
  return p; 
}

NodeRB *insertRedBlack (NodeRB *newp, NodeRB *root)
{
    root = insertTree(newp, root);
    newp->color = red;

    while((newp != root) && (newp->parent->color == red))
    {
        if(newp->parent == (newp->parent)->parent->left)
        {
            NodeRB *newpUncle = (newp->parent)->parent->right;

            if((newpUncle != NULL) && (newpUncle->color == red))
            {
                newp->parent->color = black;
                newpUncle->color = black;
                newp->parent->parent->color = red;
                newp = newp->parent->parent;
            }
            else
            {
                if(newp == newp->parent->right)
                {
                    newp = newp->parent;
                    root = leftRotateRB(root,newp);
                }
                newp->parent->color = black;
                newp->parent->parent->color = red;
                root = rightRotateRB(root, newp->parent->parent);
            }
        }
        else
        {
            NodeRB *newpUncle = (newp->parent)->parent->left;

            if((newpUncle != NULL) && (newpUncle->color == red))
            {
                newp->parent->color = black;
                newpUncle->color = black;
                newp->parent->parent->color = red;
                newp = newp->parent->parent;
            }
            else
            {
                if(newp == newp->parent->left)
                {
                    newp = newp->parent;
                    root = rightRotateRB(root,newp);
                }
                newp->parent->color = black;
                newp->parent->parent->color = red;
               root =  leftRotateRB(root, newp->parent->parent);
            }

        }
    }
    root->color = black;
    return root;
} 
