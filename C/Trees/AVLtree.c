#include<stdio.h>
#include<stdlib.h>
#include"myTrees.h"

Node *insertAVL(int num, Node *p, bool *heightIncreased){
   Node *aptr;
   Node *bptr;
   if(p == NULL) {
      p = (Node *) malloc(sizeof(Node));
      p->data = num;
      p->left = NULL;
      p->right = NULL;
      *heightIncreased = TRUE;
   }
   else if (num < p->data)
   {
       p->left = insertAVL(num,p->left, heightIncreased);
       if(*heightIncreased==TRUE){
         switch (p->bf)
         {
          case -1: /*Right Heavy*/
            p->bf = 0;
            *heightIncreased = FALSE;
            break;
          case 0: /*Balanced*/
            p->bf = 1;
            break;
          case 1: /* Left Heavy */
            aptr = p->left;
            if(aptr->bf == 1)
            {
               printf("Left to Left rotation\n");
               p->left = aptr->right;
               aptr->right = p;

               p->bf =0;
               aptr->bf = 0;

               p = aptr;
            }
            else
            {
               printf("Left to Right rotation\n");
               bptr = aptr->right;
               aptr->right = bptr->left;
               bptr->left = aptr;

               p->left = bptr->right;
               bptr->right = p;

               if(bptr->bf == 1)
               {
                  p->bf = -1;
               }
               else
               {
                  p->bf = 0;
               }
               if(bptr->bf == -1) 
               {
                  aptr->bf = 1;
               }
               else
               {
                  aptr->bf = 0;
               }
               bptr->bf = 0;
               p = bptr;
            }
            *heightIncreased = FALSE;
            break;
          
          default:
             break;
         }
      }
   }
   else if(num > p->data)
   {
       p->right = insertAVL(num,p->right, heightIncreased);
       if(*heightIncreased==TRUE){
         switch (p->bf)
         {
          case 1: /*Left Heavy*/
            p->bf = 0;
            *heightIncreased = FALSE;
            break;
          case 0: /*Balanced*/
            p->bf = -1;
            break;
          case -1: /* Right Heavy */
            aptr = p->right;
            if(aptr->bf == -1)
            {
               printf("Right to Right rotation\n");
               p->right = aptr->left;
               aptr->left = p;

               p->bf =0;
               aptr->bf = 0;

               p = aptr;
            }
            else
            {
               printf("Right to Left rotation\n");
               bptr = aptr->left;
               aptr->left = bptr->right;
               bptr->right = aptr;

               p->right = bptr->left;
               bptr->left = p;

               if(bptr->bf == -1)
               {
                  p->bf = 1;
               }
               else
               {
                  p->bf = 0;
               }
               if(bptr->bf == 1) 
               {
                  aptr->bf = -1;
               }
               else
               {
                  aptr->bf = 0;
               }
               bptr->bf = 0;
               p = bptr;
            }
            *heightIncreased = FALSE;
            break;
          
          default:
             break;
         }
      }

   }
   return p;
}

void traverseAVL(Node *p){
   traverseBST(p);
}
