# Queues - Array Implementation
{for krrish}
Ok so basically in queues you need to remember these 6 functions. 
Exam pov- you can literally paste it onto your paper, they'll give marks. Plus its v easy

Remember the following functions and what they do. Its very essential for you to write these down for every queue-related question. 

1. `IsEmpty` : to check if the queue is empty or not 
2. `IsFull` : to check if it's full or not 
3. `enqueue` : to add elements into the queue
4. `dequeue` : to remove elements from the queue
5. `peek` : to see the element that is at the front of the queue
6. `display` : to display the queue

We'll be using array implementation here.
### Code:

Firstly, you need to write the following cuz it's a standard:
```
#include <stdio.h>
#include <stdlib.h>
```

You also need to write `#define MAX 5`. This makes MAX a constant that you can use anywhere.
 

#### You gotta first create a queue, for that you'll have to:

Use  `typedef` to create a queue.

Here, I have created a queue of 5 elements max.

You initialize the queue's front and rear to -1 

```
typedef int element;

element queue[MAX];
int front = -1, rear = -1;
```



#### IsEmpty and IsFull
This part is the easiest (2marks ez) 

To check if the queue is empty, you check if the front is still equal to `-1` (initial state); if it is, the queue is empty
Else if the queue has reached `MAX - 1`, that means the queue has reached full capacity.

You may ask why `MAX - 1`: it cuz because your queue starts with an element in position `0`

```
int isEmpty(){
    return (front == -1);
}

int isFull(){
    return(rear == MAX -1);
}
```

#### Enqueue (void fn)
1. You check if the queue is full: if the queue is full, you can't enter any more elements
2. You check if the queue is empty: makes it easier to insert your first element.
3. You increment `rear` by `1` add the `item` or `element` into the queue. 
```
void enqueue(element item){
    if(isFull()) return; //check if full

    if(isEmpty()) front = 0; //check if empty: if yes, make front '0' from '-1'

    queue[++rear] = item;  // you increment rear by 1 as you add the item (item is basically your data)
    printf("done");

}
```


#### Dequeue (element fn because you're returning the element) 
1. You check if the queue is empty : because you cant remove anything from an empty queue.
2. You remove the item and store it in `element item` so that you can return it.
3. If the element you removed is the last element in the queue, you set `front = rear = -1` initial empty queue condition.
4. If it's not the last element, you just increment `front`
```
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
```

#### Peak (element fn because you're returning the element) 
This is easier, you just have to return the front element.
1. You check if the queue is empty
2. If not, you return `queue[front]`

```
element peek(){
    if(isEmpty()){
        exit(1);
    }
    return queue[front];
}
```
#### Display 
You display all the elements in the queue
1. You check if the queue is empty: if yes print "its empty"
2. Print all the elements using a for loop starting from `front` all the way up to `rear`

```
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
```

#### Main function
This is to demonstrate enqueue, dequeue, peek, display etc.

```
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    printf("Front element %d\n", peek());
    printf("dequeued element %d\n", dequeue());
    printf("dequeued element %d\n", dequeue());
    enqueue(40);
    printf("%d",peek());
    display();
    return 0;
}
```

### Note: Whenever you find the queue is empty or full, print an error message notifying the same. 

## ALL THE BEST! 
