#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
} DoublyLinkedList;

DoublyLinkedList* createList();
Node* createNode(int data);
void insertRear(DoublyLinkedList* list, int data);
void displayForward(DoublyLinkedList* list);
void concatenate(DoublyLinkedList* X1, DoublyLinkedList* X2);
void inputList(DoublyLinkedList* list, const char* name);

int main() {
    DoublyLinkedList* X1 = createList();
    DoublyLinkedList* X2 = createList();

    inputList(X1, "X1");
    inputList(X2, "X2");

    printf("List X1 before concatenation: ");
    displayForward(X1);
    printf("List X2 before concatenation: ");
    displayForward(X2);

    concatenate(X1, X2);

    printf("List X1 after concatenation: ");
    displayForward(X1);

    return 0;
}

DoublyLinkedList* createList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertRear(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
}

void displayForward(DoublyLinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void concatenate(DoublyLinkedList* X1, DoublyLinkedList* X2) {
    if (X1->head == NULL) {
        X1->head = X2->head;
        X1->tail = X2->tail;
    } else if (X2->head != NULL) {
        X1->tail->next = X2->head;
        X2->head->prev = X1->tail;
        X1->tail = X2->tail;
    }
    X2->head = NULL;
    X2->tail = NULL;
}

void inputList(DoublyLinkedList* list, const char* name) {
    int n, data;
    printf("Enter number of elements in list %s: ", name);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        insertRear(list, data);
    }
}
