#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node* createNode(int val) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = val; n->next = NULL;
    return n;
}

void insertBefore(int val, int before) {
    if (!head) { printf("Empty list\n"); return; }
    Node *newNode = createNode(val);
    if (head->data == before) { newNode->next = head; head = newNode; return; }
    Node *temp = head;
    while (temp->next && temp->next->data != before) temp = temp->next;
    if (!temp->next) { printf("Not found\n"); free(newNode); return; }
    newNode->next = temp->next; temp->next = newNode;
}

void insertAfter(int val, int after) {
    Node *temp = head;
    while (temp && temp->data != after) temp = temp->next;
    if (!temp) { printf("Not found\n"); return; }
    Node *newNode = createNode(val);
    newNode->next = temp->next; temp->next = newNode;
}

void deleteElement(int val) {
    if (!head) { printf("Empty list\n"); return; }
    if (head->data == val) { Node *t = head; head = head->next; free(t); return; }
    Node *temp = head;
    while (temp->next && temp->next->data != val) temp = temp->next;
    if (!temp->next) { printf("Not found\n"); return; }
    Node *del = temp->next; temp->next = del->next; free(del);
}

void traverse() {
    Node *temp = head;
    if (!temp) { printf("Empty list\n"); return; }
    while (temp) { printf("%d ", temp->data); temp = temp->next; }
    printf("\n");
}

void reverseList() {
    Node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr; curr = next;
    }
    head = prev;
}

void sortList() {
    if (!head) return;
    int swapped;
    Node *p, *lptr = NULL;
    do {
        swapped = 0; p = head;
        while (p->next != lptr) {
            if (p->data > p->next->data) {
                int t = p->data; p->data = p->next->data; p->next->data = t;
                swapped = 1;
            }
            p = p->next;
        }
        lptr = p;
    } while (swapped);
}

void deleteAlternate() {
    if (!head) return;
    Node *prev = head, *curr = head->next;
    while (prev && curr) {
        prev->next = curr->next;
        free(curr);
        prev = prev->next;
        if (prev) curr = prev->next;
    }
}

void insertSorted(int val) {
    Node *newNode = createNode(val);
    if (!head || head->data >= val) {
        newNode->next = head; head = newNode; return;
    }
    Node *temp = head;
    while (temp->next && temp->next->data < val) temp = temp->next;
    newNode->next = temp->next; temp->next = newNode;
}

int main() {
    int ch, val, ref;
    while (1) {
        printf("\n1.Insert Before \n2.Insert After \n3.Delete \n4.Traverse \n5.Reverse \n6.Sort \n7.Delete Alternate \n8.Insert Sorted \n9.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Val & Before: "); scanf("%d%d", &val, &ref); insertBefore(val, ref); break;
            case 2: printf("Val & After: "); scanf("%d%d", &val, &ref); insertAfter(val, ref); break;
            case 3: printf("Delete Val: "); scanf("%d", &val); deleteElement(val); break;
            case 4: traverse(); break;
            case 5: reverseList(); printf("Reversed\n"); break;
            case 6: sortList(); printf("Sorted\n"); break;
            case 7: deleteAlternate(); printf("Deleted alternate\n"); break;
            case 8: printf("Insert Sorted Val: "); scanf("%d", &val); insertSorted(val); break;
            case 9:
                while (head) { Node *t = head; head = head->next; free(t); }
                exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

