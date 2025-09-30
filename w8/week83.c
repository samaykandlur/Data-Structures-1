#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued to queue.\n", value);
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

void displayQueue(Queue* q) {
    Node* temp = q->front;
    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");

                    while(getchar() != '\n');
                    break;
                }
                enqueue(&q, value);
                break;

            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;

            case 3:
                displayQueue(&q);
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
