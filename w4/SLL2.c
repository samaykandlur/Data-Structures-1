#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node* createNode(int val) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    n->data = val;
    n->next = NULL;
    return n;
}

void insertAtEnd(int val) {
    Node *newNode = createNode(val);
    if (!head) {
        head = newNode;
        printf("%d inserted as the first node.\n", val);
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    printf("%d inserted at the end.\n", val);
}

void insertBefore(int val, int before) {
    if (!head) {
        printf("Cannot insert before %d: list is empty.\n", before);
        return;
    }
    Node *newNode = createNode(val);
    if (head->data == before) {
        newNode->next = head;
        head = newNode;
        printf("%d inserted before %d.\n", val, before);
        return;
    }
    Node *temp = head;
    while (temp->next && temp->next->data != before)
        temp = temp->next;
    if (!temp->next) {
        printf("Value %d not found. Cannot insert %d before it.\n", before, val);
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted before %d.\n", val, before);
}

void insertAfter(int val, int after) {
    Node *temp = head;
    while (temp && temp->data != after)
        temp = temp->next;
    if (!temp) {
        printf("Value %d not found. Cannot insert %d after it.\n", after, val);
        return;
    }
    Node *newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted after %d.\n", val, after);
}

void deleteElement(int val) {
    if (!head) {
        printf("Cannot delete %d: list is empty.\n", val);
        return;
    }
    if (head->data == val) {
        Node *toDelete = head;
        head = head->next;
        free(toDelete);
        printf("Deleted %d from the list.\n", val);
        return;
    }
    Node *temp = head;
    while (temp->next && temp->next->data != val)
        temp = temp->next;
    if (!temp->next) {
        printf("Value %d not found in the list.\n", val);
        return;
    }
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    printf("Deleted %d from the list.\n", val);
}

void traverse() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    printf("List: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseList() {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed successfully.\n");
}

void sortList() {
    if (!head || !head->next) {
        printf("List is already sorted or has one element.\n");
        return;
    }
    int swapped;
    Node *p, *lptr = NULL;
    do {
        swapped = 0;
        p = head;
        while (p->next != lptr) {
            if (p->data > p->next->data) {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                swapped = 1;
            }
            p = p->next;
        }
        lptr = p;
    } while (swapped);
    printf("List sorted in ascending order.\n");
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
    printf("Alternate nodes deleted.\n");
}

void insertSorted(int val) {
    Node *newNode = createNode(val);
    if (!head || head->data >= val) {
        newNode->next = head;
        head = newNode;
        printf("%d inserted as the first node in sorted order.\n", val);
        return;
    }
    Node *temp = head;
    while (temp->next && temp->next->data < val)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted in sorted order.\n", val);
}

void freeList() {
    Node *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void insertAtStart(int val) {
    Node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the start.\n", val);
}


int main() {
    int choice, val, ref;


    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Insert Before\n");
        printf("3. Insert After\n");
        printf("4. Delete Element\n");
        printf("5. Traverse\n");
        printf("6. Reverse List\n");
        printf("7. Sort List\n");
        printf("8. Delete Alternate Nodes\n");
        printf("9. Insert in Sorted Order\n");
        printf("10. Exit\n");
        printf("11. Insert at Start\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 2:
                printf("Enter value to insert and the reference value: ");
                scanf("%d %d", &val, &ref);
                insertBefore(val, ref);
                break;
            case 3:
                printf("Enter value to insert and the reference value: ");
                scanf("%d %d", &val, &ref);
                insertAfter(val, ref);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteElement(val);
                break;
            case 5:
                traverse();
                break;
            case 6:
                reverseList();
                break;
            case 7:
                sortList();
                break;
            case 8:
                deleteAlternate();
                break;
            case 9:
                printf("Enter value to insert in sorted order: ");
                scanf("%d", &val);
                insertSorted(val);
                break;
            case 10:
                freeList();
                printf("Exiting... All memory freed.\n");
                exit(0);
            case 11:
                printf("Enter value to insert at start: ");
                scanf("%d", &val);
                insertAtStart(val);

                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

