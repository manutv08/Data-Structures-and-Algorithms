#ifndef __MYTREES_H_INCLUDED__
#define __MYTREES_H_INCLUDED__

typedef struct node
{
    int data;
    int bf;             //balance factor [AVL tree]
    struct node *left;
    struct node *right;
}Node;

Node* insertBST(int num, Node*);
Node* removeBST(int num, Node*);
void traverseBST(Node *p);


typedef enum{ FALSE, TRUE} bool;
Node *insertAVL(int num, Node *p, bool *heightIncreased);
void traverseAVL(Node *p);
#endif