# Circular Linked List (CLL) 


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
9. display

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

The list uses a `head` pointer. In a circular list the last node's `next` points to `head`.

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

If list is empty, new node points to itself. Otherwise insert before head and update last node's next.

```c
void insertAtBeginning(element item) {
    Node *temp = createNode(item);
    if (head == NULL) {
        head = temp;
        head->next = head;
        return;
    }

    Node *cur = head;
    while (cur->next != head) {
        cur = cur->next;
    }

    temp->next = head;
    cur->next = temp;
    head = temp;
}
```

---

## insertAtEnd

If list is empty, same as insertAtBeginning. Otherwise insert after last node and keep head unchanged.

```c
void insertAtEnd(element item) {
    Node *temp = createNode(item);
    if (head == NULL) {
        head = temp;
        head->next = head;
        return;
    }

    Node *cur = head;
    while (cur->next != head) {
        cur = cur->next;
    }

    cur->next = temp;
    temp->next = head;
}
```

---

## insertAtPosition

Position is 1-based. If pos == 1 use insertAtBeginning.

```c
void insertAtPosition(element item, int pos) {
    if (pos == 1) {
        insertAtBeginning(item);
        return;
    }

    Node *cur = head;
    int i = 1;
    while (i < pos - 1 && cur->next != head) {
        cur = cur->next;
        i++;
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

If list empty do nothing. If one node, free and set head NULL. Otherwise remove head and fix last node's next.

```c
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    Node *last = head;
    while (last->next != head) {
        last = last->next;
    }

    Node *temp = head;
    head = head->next;
    last->next = head;
    free(temp);
}
```

---

## deleteAtEnd

If empty do nothing. If one node remove it. Otherwise remove last node and update second-last next to head.

```c
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    Node *cur = head;
    while (cur->next->next != head) {
        cur = cur->next;
    }

    free(cur->next);
    cur->next = head;
}
```

---

## deleteAtPosition

Position is 1-based. If pos == 1 use deleteAtBeginning.

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
    int i = 1;
    while (i < pos - 1 && cur->next != head) {
        cur = cur->next;
        i++;
    }

    if (cur->next == head) {
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

Returns position (1-based) or -1 if not found.

```c
int search(element item) {
    if (head == NULL) return -1;

    Node *cur = head;
    int pos = 1;
    do {
        if (cur->data == item) return pos;
        cur = cur->next;
        pos++;
    } while (cur != head);

    return -1;
}
```

---

## display

Traverse from head and print until back to head.

```c
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *cur = head;
    do {
        printf("%d ", cur->data);
        cur = cur->next;
    } while (cur != head);
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
