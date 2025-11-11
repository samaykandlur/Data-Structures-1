/*Write a C program to simulate a printer queue where tasks arrive randomly and are processed in order.
i.Tasks (with a document ID and name) arrive at random (simulate using random function or user input).
ii.Enqueue each print job.
iii.Dequeue in FIFO order to simulate printing*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5   // max print jobs in queue
#define MAX_NAME_LEN 30

// Structure to hold print job details
typedef struct {
    int docID;
    char docName[MAX_NAME_LEN];
} PrintJob;

PrintJob queue[MAX_QUEUE_SIZE];
int front = 0, rear = 0;

// Queue functions
int isFull() {
    return (rear + 1) % MAX_QUEUE_SIZE == front;
}

int isEmpty() {
    return front == rear;
}

void enqueue(PrintJob job) {
    if (isFull()) {
        printf("Printer queue is full! Cannot add %s (ID: %d)\n", job.docName, job.docID);
        return;
    }
    queue[rear] = job;
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    printf("Added to queue → %s (ID: %d)\n", job.docName, job.docID);
}

PrintJob dequeue() {
    if (isEmpty()) {
        printf("Printer queue is empty!\n");
        exit(1);
    }
    PrintJob job = queue[front];
    front = (front + 1) % MAX_QUEUE_SIZE;
    return job;
}

void displayQueue() {
    if (isEmpty()) {
        printf("[Queue is empty]\n");
        return;
    }
    printf("Current Printer Queue:\n");
    int i = front;
    while (i != rear) {
        printf("→ %s (ID: %d)\n", queue[i].docName, queue[i].docID);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}

int main() {
    srand(time(0)); 
    int choice;

    while (1) {
        printf("\n--- Printer Queue Menu ---\n");
        printf("1. Add Random Print Job\n");
        printf("2. Print Next Document\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            PrintJob job;
            job.docID = rand() % 1000 + 1; // random ID
            sprintf(job.docName, "Document_%d", job.docID);
            enqueue(job);
        } 
        else if (choice == 2) {
            if (!isEmpty()) {
                PrintJob job = dequeue();
                printf(" Printing: %s (ID: %d)\n", job.docName, job.docID);
            } else {
                printf("No documents to print!\n");
            }
        } 
        else if (choice == 3) {
            displayQueue();
        } 
        else if (choice == 4) {
            printf("Exiting Printer Queue Simulation.\n");
            break;
        } 
        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
