#include <stdio.h>
#include <stdlib.h>

// ---------------------------
// Node structure
// ---------------------------
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// ---------------------------
// Create new node
// ---------------------------
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// ---------------------------
// Preorder Traversal (Root → Left → Right)
// ---------------------------
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// ---------------------------
// Inorder Traversal (Left → Root → Right)
// ---------------------------
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// ---------------------------
// Postorder Traversal (Left → Right → Root)
// ---------------------------
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// ---------------------------
// Queue for Level Order Traversal
// ---------------------------
typedef struct Queue {
    Node* data[100];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear == 99) return; // queue full
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = node;
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;
    Node* temp = q->data[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

// ---------------------------
// Level Order Traversal (BFS)
// ---------------------------
void levelOrder(Node* root) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* curr = dequeue(&q);
        printf("%d ", curr->data);

        if (curr->left != NULL)
            enqueue(&q, curr->left);
        if (curr->right != NULL)
            enqueue(&q, curr->right);
    }
}

// ---------------------------
// Main function
// ---------------------------
int main() {
    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Preorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\nLevel Order Traversal: ");
    levelOrder(root);

    printf("\n");

    return 0;
}
