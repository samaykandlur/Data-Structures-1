#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;
element q[MAX];

int front = 0, rear = 0;
int isEmpty(){
    return(front == rear);
}

int isFull(){
    return((rear+1)%MAX == front);
}

void addq(element item){
    //check if full

    q[rear] = item;
    rear = (rear+1)%MAX;

    printf("Enqd %d", item);

}

element qd(){
    //check if empty

    element item = q[front];
    front = (front+1)%MAX;
    return item;    
}

element peek(){
    //check if empty

    return q[front];
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", q[i]);
        i = (i + 1) %  MAX;
    }
    printf("\n");
}




