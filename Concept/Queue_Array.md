# Queue Using Array
This document explains the Array implementation of a queue.

---

## Essential Queue Functions (6 functions you must remember)

1. **IsEmpty** – checks if the queue is empty
2. **IsFull** – checks if the queue is full
3. **enqueue** – adds an element to the queue
4. **dequeue** – removes an element from the queue
5. **peek** – views the front element without removing it
6. **display** – prints all elements in the queue

---

## Standard Includes & Constants

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 5
```

Using `MAX` makes the queue size easy to change.

---

## Queue Representation Using Array & typedef

We create:

* A typedef for the element type
* A global array of size MAX
* Two indices: `front` and `rear`

```c
typedef int element;

element queue[MAX];
int front = -1, rear = -1;
```

`front = rear = -1` indicates an empty queue.

---

## isEmpty()

Queue is empty if `front == -1`.

```c
int isEmpty() {
    return (front == -1);
}
```

---

## isFull()

Queue is full when `rear == MAX - 1`.

```c
int isFull() {
    return (rear == MAX - 1);
}
```

---

## enqueue(element item)

Steps:

1. Check if full → cannot insert.
2. If empty → set `front = 0`.
3. Increment `rear` and insert item.

```c
void enqueue(element item) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }

    if (isEmpty())
        front = 0;

    queue[++rear] = item;
}
```

---

## dequeue()

Steps:

1. Check if empty → cannot delete.
2. Store the element at `front`.
3. If last element removed → reset to empty state.
4. Else increment `front`.

```c
element dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        exit(1);
    }

    element item = queue[front];

    if (front == rear) {
        front = rear = -1; // queue becomes empty
    } else {
        front++;
    }

    return item;
}
```

---

## peek()

Returns the front element without removing it.

```c
element peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return queue[front];
}
```

---

## display()

Prints all elements from `front` to `rear`.

```c
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

---

##  Example main()

Demonstrates enqueue, dequeue, peek, and display.

```c
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Front element: %d\n", peek());
    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    enqueue(40);

    printf("Current front: %d\n", peek());

    display();

    return 0;
}
```
