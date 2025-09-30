#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int age;
    int priority;
} Patient;

typedef struct Node {
    Patient data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q) {
    return (q->front == NULL);
}

void enqueue(Queue *q, Patient p) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = p;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %s, Age: %d, Priority: %d\n", p.name, p.age, p.priority);
}

Patient dequeue(Queue *q) {
    Patient empty = {"", -1, -1};
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return empty;
    }
    Node *temp = q->front;
    Patient p = temp->data;

    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return p;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    Node *temp = q->front;
    printf("\nCurrent Queue:\n");
    while (temp != NULL) {
        printf("Name: %s, Age: %d, Priority: %d\n",
               temp->data.name, temp->data.age, temp->data.priority);
        temp = temp->next;
    }
}

int main() {
    Queue q;
    initQueue(&q);

    int choice;
    Patient p;

    while (1) {
        printf("Patient Queue Menu\n");
        printf("1. Enqueue patient\n");
        printf("2. Dequeue patient\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter patient name: ");
                fgets(p.name, sizeof(p.name), stdin);
                p.name[strcspn(p.name, "\n")] = '\0';
                printf("Enter age: ");
                scanf("%d", &p.age);
                printf("Enter priority: ");
                scanf("%d", &p.priority);
                enqueue(&q, p);
                break;
            case 2:
                p = dequeue(&q);
                if (p.age != -1)
                    printf("Dequeued: %s, Age: %d, Priority: %d\n", p.name, p.age, p.priority);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
