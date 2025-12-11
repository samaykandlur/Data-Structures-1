# Stack Using Array

---

## Essential Stack Functions

1. isEmpty – checks if the stack is empty
2. isFull – checks if the stack is full
3. push – adds an element to the top of the stack
4. pop – removes and returns the top element
5. peek – returns the element at the top without removing it
6. display – prints all elements from top to bottom

---

## Standard Includes and Constants

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 5
```

---

## Stack Representation Using Array and typedef

```c
typedef int element;

element stack[MAX];
int top = -1;
```

---

## isEmpty

```c
int isEmpty() {
    return (top == -1);
}
```

---

## isFull

```c
int isFull() {
    return (top == MAX - 1);
}
```

---

## push

```c
void push(element item) {
    if (isFull()) {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = item;
}
```

---

## pop

```c
element pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack[top--];
}
```

---

## peek

```c
element peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack[top];
}
```

---

## display

```c
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
```

---

## Example main

```c
int main() {
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", peek());
    printf("Popped element: %d\n", pop());

    display();

    return 0;
}
```

---
