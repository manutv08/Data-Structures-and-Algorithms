#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct queue
{
   struct node *front; 
   struct node *rear; 
};

void enqueue(struct queue *queueRef, int item){
    struct node *newp= (struct node*)malloc (sizeof(struct node));
    newp->data = item;
    newp->next = NULL;

    if(queueRef->rear != NULL){
        queueRef->rear->next = newp;
    }
    else{
        queueRef->front = newp;
    }
    queueRef->rear = newp;
}

int dequeue(struct queue *queueRef){
    int item = -1;
    if(queueRef->front != NULL){
        item = queueRef->front->data;
        if(queueRef->front != queueRef->rear){
            queueRef->front = queueRef->front->next;
        }
        else{
            queueRef->front = queueRef->rear = NULL;
        }
    }
    return item;
}

//Radix Sort Function
void radixSort(int array[], int pockets, int n){
    int numDigits;

    //Initializing array of queues
    struct queue *qarray = (struct queue *) calloc(pockets, sizeof(struct queue));
    for (size_t i = 0; i < pockets; i++)
    {
        (qarray+i)->front = NULL;
        (qarray+i)->rear = NULL;
    }

    //Finding Largest element in the given array
    int large=-1;
    for(int i=0; i<n; i++){
        if(array[i] >= large){
            large = array[i];
        }
    }

    //Finding number of digits of the largest element
    numDigits=0;
    while (large > 0)
    {
        large = large/pockets;
        numDigits++;
    }
    
    int index = 0, temp = -1, i,j,k;
    for (i = 0; i < numDigits; i++)
    {
        for (j = 0; j < n; j++)
        {
            temp = array[j];
            for (k = 0; k <= i; k++)
            {
                index = temp%pockets;
                temp = temp/pockets;
            }
            enqueue(qarray+index, array[j]);
        }
        j = 0;

        for ( k = 0; k < pockets; k++)
        {
            do
            {
                temp = dequeue(qarray+k);
                if(temp>-1){
                    array[j]= temp;
                    j++;
                }
            } while (temp != -1);
            
        }
         
    }
    free(qarray);
}