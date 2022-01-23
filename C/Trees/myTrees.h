#ifndef __MYTREES_H_INCLUDED__
#define __MYTREES_H_INCLUDED__

#include "myNodes.h"

Node* insertBST(int num, Node*);
Node* removeBST(int num, Node*);


typedef enum{ FALSE, TRUE} bool;
Node *insertAVL(int num, Node *p, bool *heightIncreased);

NodeRB *createNewNode(int num);
NodeRB *insertRedBlack (NodeRB *newp, NodeRB *root);
#endif