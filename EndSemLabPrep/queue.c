#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int element;

element queue[MAX];
int front = -1, rear = -1;

int isEmpty(){
    return (front == -1);
}

int isFull(){
    return(rear == MAX -1);
}


void enqueue(element item){
    if(isFull()) return;

    if(isEmpty()) front = 0;

    queue[++rear] = item;
    printf("done");

}



element dequeue(){

    if(isEmpty()){
        printf("Empty");
        exit(1);
    }

    element item = queue[front];
    if(front == rear){
        front = rear = -1;
    }
    else{
        front ++;
    }
    return item;
}

element peek(){
    if(isEmpty()){
        exit(1);
    }
    return queue[front];
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    printf("Front element %d\n", peek());
    printf("dequeued element %d\n", dequeue());
    printf("dequeued element %d\n", dequeue());
    enqueue(40);
    printf("%d",peek());
    return 0;
}
