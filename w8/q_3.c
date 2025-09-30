#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct {
    Node *front, *rear;
} Queue;
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}
void enqueue(Queue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
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
    printf("%d enqueued to queue\n", value);
}
int dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}
void displayQueue(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Node *temp = q->front;
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
        printf("Queue Operations Menu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input! Please enter a number.\n");
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                if (scanf("%d", &value) != 1) {
                    while (getchar() != '\n');
                    printf("Invalid input! Please enter an integer.\n");
                } else {
                    enqueue(&q, value);
                }
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1)
                    printf("Dequeued value: %d\n", value);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
