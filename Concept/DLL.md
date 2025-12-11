# Doubly Linked List (DLL) 

This document explains Doubly linked-list.
---

## Essential Operations

1. createNode
2. insertAtBeginning
3. insertAtEnd
4. insertAtPosition
5. deleteAtBeginning
6. deleteAtEnd
7. deleteAtPosition
8. search
9. displayForward
10. displayBackward

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
    struct Node *prev;
    struct Node *next;
} Node;
```

The list uses a `head` pointer.

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
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}
```

---

## insertAtBeginning

```c
void insertAtBeginning(element item) {
    Node *temp = createNode(item);

    if (head == NULL) {
        head = temp;
        return;
    }

    temp->next = head;
    head->prev = temp;
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
    temp->prev = cur;
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
    temp->prev = cur;

    if (cur->next != NULL)
        cur->next->prev = temp;

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

    if (head->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    head = head->next;
    head->prev = NULL;
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
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->prev->next = NULL;
    free(cur);
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
    for (int i = 1; i < pos && cur != NULL; i++) {
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Invalid position\n");
        return;
    }

    cur->prev->next = cur->next;

    if (cur->next != NULL)
        cur->next->prev = cur->prev;

    free(cur);
}
```

---

## search

```c
int search(element item) {
    Node *cur = head;
    int pos = 1;

    while (cur != NULL) {
        if (cur->data == item)
            return pos;
        cur = cur->next;
        pos++;
    }

    return -1;
}
```

---

## displayForward

```c
void displayForward() {
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

## displayBackward

```c
void displayBackward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->prev;
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

    displayForward();
    displayBackward();

    deleteAtBeginning();
    deleteAtEnd();
    deleteAtPosition(2);

    displayForward();

    int found = search(20);
    printf("Search result: %d\n", found);

    return 0;
}
```

---
