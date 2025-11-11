#include <stdio.h>
#include <stdlib.h>
#define MAX 3


typedef int element;

typedef struct node{
    element item;
    struct node* link;
}node;

typedef node* QueuePointer;

QueuePointer front[MAX], rear[MAX];

void initQ(){
    for(int i = 0; i<MAX;i++){
        front[i] = rear[i] =    NULL;
    }
}

int isEmpty(QueuePointer f){
    return (f == NULL);
}

void enqueue(int q, element item){
    node *temp = (node*)malloc(sizeof(node));
    if (!temp){printf("Full memory");
    exit(1);}

    temp->item = item;
    temp->link = NULL;

    if(front[q]){
        rear[q]->link = temp;
    }
    else{
        front[q] = temp;
    }
    rear[q] = temp;

}


