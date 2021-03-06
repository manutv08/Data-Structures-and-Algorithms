#ifndef __MYNODES_H_INCLUDED__
#define __MYNODES_H_INCLUDED__
typedef struct node
{
    int data;
    int bf;             //balance factor [AVL tree]
    struct node *left;
    struct node *right;
}Node;


typedef struct nodeRedBlack
{
    int data;
    enum {black, red} color;
    struct nodeRedBlack *left;
    struct nodeRedBlack *right;
    struct nodeRedBlack *parent;
}NodeRB;

void traverse(Node *p);
#endif