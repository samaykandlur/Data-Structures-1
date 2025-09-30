#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* First = NULL;
Node* Last = NULL;

void displayList() {
    if (First == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = First;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != First);
    printf("\n");
}

void insertEndUsingFirst(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (First == NULL) {
        First = Last = newNode;
        newNode->next = First;
    } else {
        Node* temp = First;
        while (temp->next != First) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = First;
        Last = newNode;
    }

    printf("Inserted %d at end using First pointer.\n", data);
    displayList();
}

void insertEndUsingLast(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (Last == NULL) {
        First = Last = newNode;
        newNode->next = First;
    } else {
        Last->next = newNode;
        newNode->next = First;
        Last = newNode;
    }

    printf("Inserted %d at end using Last pointer.\n", data);
    displayList();
}

void deleteBeginningUsingFirst() {
    if (First == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    int deletedData;
    if (First == Last) {
        deletedData = First->data;
        free(First);
        First = Last = NULL;
    } else {
        Node* temp = First;
        deletedData = temp->data;
        First = First->next;
        Last->next = First;
        free(temp);
    }

    printf("Deleted %d from beginning using First pointer.\n", deletedData);
    displayList();
}

void deleteEndUsingFirst() {
    if (First == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    int deletedData;
    if (First == Last) {
        deletedData = First->data;
        free(First);
        First = Last = NULL;
    } else {
        Node* temp = First;
        while (temp->next != Last) {
            temp = temp->next;
        }
        deletedData = Last->data;
        free(Last);
        Last = temp;
        Last->next = First;
    }

    printf("Deleted %d from end using First pointer.\n", deletedData);
    displayList();
}

void deleteBeginningUsingLast() {
    deleteBeginningUsingFirst();
}

void deleteEndUsingLast() {
    if (Last == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    int deletedData;
    if (First == Last) {
        deletedData = Last->data;
        free(Last);
        First = Last = NULL;
    } else {
        Node* temp = First;
        while (temp->next != Last) {
            temp = temp->next;
        }
        deletedData = Last->data;
        free(Last);
        Last = temp;
        Last->next = First;
    }

    printf("Deleted %d from end using Last pointer.\n", deletedData);
    displayList();
}

int main() {
    int choice, data;
    while (1) {
        printf("\nCircular Singly Linked List\n");
        printf("1. Insert at end (using First)\n");
        printf("2. Insert at end (using Last)\n");
        printf("3. Delete from beginning (using First)\n");
        printf("4. Delete from end (using First)\n");
        printf("5. Delete from beginning (using Last)\n");
        printf("6. Delete from end (using Last)\n");
        printf("7. Display list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertEndUsingFirst(data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertEndUsingLast(data);
                break;
            case 3:
                deleteBeginningUsingFirst();
                break;
            case 4:
                deleteEndUsingFirst();
                break;
            case 5:
                deleteBeginningUsingLast();
                break;
            case 6:
                deleteEndUsingLast();
                break;
            case 7:
                displayList();
                break;
            case 0:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
