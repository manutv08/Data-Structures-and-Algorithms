#ifndef __MYNODES_H_INCLUDED__
#define __MYNODES_H_INCLUDED__
typedef struct node
{
    int data;
    int bf;             //balance factor [AVL tree]
    struct node *left;
    struct node *right;
}Node;


void traverse(Node *p);
#endif