# Singly Linked List (SLL)

This document explains the Singly - linked-list.
---

## Essential Operations

1. createNode – allocate a new node
2. insertAtBeginning
3. insertAtEnd
4. insertAtPosition
5. deleteAtBeginning
6. deleteAtEnd
7. deleteAtPosition
8. search
9. display

These are pretty self-explanatory.
---

## Standard Includes and typedef

```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;
```

---

## Node Definition

```c
typedef struct Node {
    element data;
    struct Node *next;
} Node;
```

`head` will point to the start of the linked list.

```c
Node *head = NULL;
```

---

## createNode

```c
Node* createNode(element item) {
    Node *temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = item;
    temp->next = NULL;
    return temp;
}
```

---

## insertAtBeginning

```c
void insertAtBeginning(element item) {
    Node *temp = createNode(item);
    temp->next = head;
    head = temp;
}
```

---

## insertAtEnd

```c
void insertAtEnd(element item) {
    Node *temp = createNode(item);

    if (head == NULL) {
        head = temp;
        return;
    }

    Node *cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = temp;
}
```

---

## insertAtPosition

```c
void insertAtPosition(element item, int pos) {
    if (pos == 1) {
        insertAtBeginning(item);
        return;
    }

    Node *cur = head;
    for (int i = 1; i < pos - 1 && cur != NULL; i++) {
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Invalid position\n");
        return;
    }

    Node *temp = createNode(item);
    temp->next = cur->next;
    cur->next = temp;
}
```

---

## deleteAtBeginning

```c
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    head = head->next;
    free(temp);
}
```

---

## deleteAtEnd

```c
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    Node *cur = head;
    while (cur->next->next != NULL) {
        cur = cur->next;
    }

    free(cur->next);
    cur->next = NULL;
}
```

---

## deleteAtPosition

```c
void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        deleteAtBeginning();
        return;
    }

    Node *cur = head;
    for (int i = 1; i < pos - 1 && cur != NULL; i++) {
        cur = cur->next;
    }

    if (cur == NULL || cur->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    Node *temp = cur->next;
    cur->next = temp->next;
    free(temp);
}
```

---

## search

```c
int search(element item) {
    Node *cur = head;
    int pos = 1;

    while (cur != NULL) {
        if (cur->data == item) {
            return pos;
        }
        cur = cur->next;
        pos++;
    }

    return -1;
}
```

---

## display

```c
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
```

---

## Example main

```c
int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtPosition(15, 2);

    display();

    deleteAtBeginning();
    deleteAtEnd();
    deleteAtPosition(2);

    display();

    int found = search(20);
    printf("Search result: %d\n", found);

    return 0;
}
```

---
