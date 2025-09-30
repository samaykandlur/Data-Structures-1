#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;
} Node;

Node *head = NULL, *tail = NULL;

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data; n->next = n->prev = NULL;
    return n;
}

void insertRear(int data) {
    Node* n = createNode(data);
    if (!head) head = tail = n;
    else {
        tail->next = n; n->prev = tail; tail = n;
    }
}

void deleteRear() {
    if (!tail) { printf("List empty.\n"); return; }
    Node* temp = tail;
    if (head == tail) head = tail = NULL;
    else { tail = tail->prev; tail->next = NULL; }
    free(temp);
}

void insertAtPos(int data, int pos) {
    if (pos <= 0) return;
    Node* n = createNode(data);
    if (pos == 1) {
        n->next = head;
        if (head) head->prev = n;
        head = n;
        if (!tail) tail = n;
        return;
    }
    Node* cur = head;
    for (int i = 1; i < pos - 1 && cur; i++) cur = cur->next;
    if (!cur) { free(n); printf("Position out of bounds.\n"); return; }
    n->next = cur->next; n->prev = cur;
    if (cur->next) cur->next->prev = n;
    else tail = n;
    cur->next = n;
}

void deleteAtPos(int pos) {
    if (!head || pos <= 0) { printf("Invalid position.\n"); return; }
    Node* cur = head;
    for (int i = 1; i < pos && cur; i++) cur = cur->next;
    if (!cur) { printf("Position out of bounds.\n"); return; }
    if (cur->prev) cur->prev->next = cur->next;
    else head = cur->next;
    if (cur->next) cur->next->prev = cur->prev;
    else tail = cur->prev;
    free(cur);
}

void insertAfter(int val, int data) {
    Node* cur = head;
    while (cur && cur->data != val) cur = cur->next;
    if (!cur) { printf("Value not found.\n"); return; }
    Node* n = createNode(data);
    n->next = cur->next; n->prev = cur;
    if (cur->next) cur->next->prev = n;
    else tail = n;
    cur->next = n;
}

void insertBefore(int val, int data) {
    Node* cur = head;
    while (cur && cur->data != val) cur = cur->next;
    if (!cur) { printf("Value not found.\n"); return; }
    Node* n = createNode(data);
    n->next = cur; n->prev = cur->prev;
    if (cur->prev) cur->prev->next = n;
    else head = n;
    cur->prev = n;
}

void traverseF() {
    for (Node* cur = head; cur; cur = cur->next) printf("%d ", cur->data);
    printf("\n");
}

void traverseR() {
    for (Node* cur = tail; cur; cur = cur->prev) printf("%d ", cur->data);
    printf("\n");
}

int main() {
    int ch, data, pos, val;
    while (1) {
        printf("\n1.InsertRear 2.DeleteRear 3.Insert@Pos 4.Delete@Pos\n");
        printf("5.InsertAfterVal 6.InsertBeforeVal 7.TraverseF 8.TraverseR 9.Exit\n");
        printf("Choice: "); scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Data: "); scanf("%d", &data); insertRear(data); break;
            case 2: deleteRear(); break;
            case 3: printf("Data Pos: "); scanf("%d%d", &data, &pos); insertAtPos(data, pos); break;
            case 4: printf("Pos: "); scanf("%d", &pos); deleteAtPos(pos); break;
            case 5: printf("AfterVal Data: "); scanf("%d%d", &val, &data); insertAfter(val, data); break;
            case 6: printf("BeforeVal Data: "); scanf("%d%d", &val, &data); insertBefore(val, data); break;
            case 7: traverseF(); break;
            case 8: traverseR(); break;
            case 9: return 0;
            default: printf("Invalid.\n");
        }
    }
}
