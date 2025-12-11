# Linked-List Queue (LL Queue) 

This document explains the **linked-list implementation of a queue** (dynamic size). 

---

## Key functions (remember these 6)

1. `IsEmpty`  — check if the queue is empty
2. `IsFull`   — not applicable for linked list (always false unless memory exhausted by malloc)
3. `enqueue`  — add element at rear
4. `dequeue`  — remove element from front
5. `peek`     — view front element
6. `display`  — print queue elements

---

## Includes & typedefs (standard)

```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;
```

---

## Node and Queue ADT using `typedef`

Use a node struct and a queue struct that holds `front` and `rear` pointers:

```c
typedef struct Node {
    element data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;
```

Initialize a queue like:

```c
Queue q = { .front = NULL, .rear = NULL };
```

---

## IsEmpty

Returns `1` if queue is empty, `0` otherwise.

```c
int isEmpty(Queue *q) {
    return (q->front == NULL);
}
```

> Note: `isFull` is not required for linked-list queue. A queue is full only when `malloc` fails.

---

## Enqueue (void)

Steps:

1. Allocate a new node with `malloc`.
2. Set `node->data = item` and `node->next = NULL`.
3. If queue is empty, set both `front` and `rear` to the new node.
4. Else link the old `rear->next = node` and update `rear = node`.

```c
void enqueue(Queue *q, element item) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed. Cannot enqueue.\n");
        return;
    }
    temp->data = item;
    temp->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}
```

---

## Dequeue (element return)

Steps:

1. Check `isEmpty()` — if yes, print error/exit.
2. Save pointer to front node, copy data, move `front` to `front->next`.
3. If `front` becomes `NULL`, set `rear = NULL` as well.
4. `free()` the removed node and return the data.

```c
element dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        exit(1);
    }

    Node *temp = q->front;
    element item = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) // queue became empty
        q->rear = NULL;

    free(temp);
    return item;
}
```

---

## Peek (element)

Return the front element without removing it.

```c
element peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No front element.\n");
        exit(1);
    }
    return q->front->data;
}
```

---

## Display

Traverse from `front` to `rear` printing `data`.

```c
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    Node *cur = q->front;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
```

---

## Helper: Free entire queue (useful for cleanup)

```c
void freeQueue(Queue *q) {
    Node *cur = q->front;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    q->front = q->rear = NULL;
}
```

---

## Example `main()`

```c
int main() {
    Queue q = { .front = NULL, .rear = NULL };

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front element: %d\n", peek(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    enqueue(&q, 40);

    printf("Current front: %d\n", peek(&q));
    display(&q);

    freeQueue(&q); // good practice

    return 0;
}
```

---

## Advantages over array implementation

* Dynamic size (no fixed limit)
* No wasted space after many dequeues (no "front keeps moving forward" issue)
* Useful when number of elements is unpredictable

## Disadvantages

* Slightly more memory overhead per element (pointer)
* `malloc`/`free` overhead can be slower than array indexing

---
