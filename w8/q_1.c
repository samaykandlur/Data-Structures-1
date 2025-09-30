#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int docID;
    char docName[50];
} PrintJob;

typedef struct {
    PrintJob jobs[MAX_QUEUE_SIZE];
    int front;
    int rear;
} PrinterQueue;

void initQueue(PrinterQueue* queue) {
    queue->front = 0;
    queue->rear = -1;
}

int isQueueFull(PrinterQueue* queue) {
    return queue->rear == MAX_QUEUE_SIZE - 1;
}

int isQueueEmpty(PrinterQueue* queue) {
    return queue->front > queue->rear;
}

void enqueue(PrinterQueue* queue, PrintJob job) {
    if (isQueueFull(queue)) {
        printf("Queue is full, cannot enqueue new job\n");
        return;
    }
    queue->jobs[++queue->rear] = job;
}

PrintJob dequeue(PrinterQueue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty, no jobs to dequeue\n");
        exit(1);
    }
    return queue->jobs[queue->front++];
}

int main() {
    PrinterQueue queue;
    initQueue(&queue);

    int jobCount;
    printf("Enter the number of print jobs to add: ");
    scanf("%d", &jobCount);

    if (jobCount > MAX_QUEUE_SIZE) {
        printf("The maximum number of print jobs allowed is %d\n", MAX_QUEUE_SIZE);
        return 1;
    }

    for (int i = 0; i < jobCount; i++) {
        PrintJob newJob;

        printf("Enter document ID for job %d: ", i + 1);
        scanf("%d", &newJob.docID);

        printf("Enter document name for job %d: ", i + 1);
        getchar();  
        fgets(newJob.docName, sizeof(newJob.docName), stdin);
        newJob.docName[strcspn(newJob.docName, "\n")] = 0;  

        enqueue(&queue, newJob);
    }

    printf("\nProcessing print jobs in FIFO order:\n");
    while (!isQueueEmpty(&queue)) {
        PrintJob job = dequeue(&queue);
        printf("Printing: ID=%d, Name=%s\n", job.docID, job.docName);
    }

    return 0;
}

