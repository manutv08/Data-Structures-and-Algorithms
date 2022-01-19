#ifndef __MYTREES_H_INCLUDED__
#define __MYTREES_H_INCLUDED__

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node* insertBST(int num, Node*);
Node* removeBST(int num, Node*);
void traverseBST(Node *p);

#endif