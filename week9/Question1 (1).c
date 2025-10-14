#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
typedef struct QNode
{
    Node *data;
    struct QNode *next;
} QNode;
typedef struct
{
    QNode *front, *rear;
} Queue;
void initQueue(Queue *q)
{
    q->front = q->rear = NULL;
}
int isEmpty(Queue *q)
{
    return q->front == NULL;
}
void enqueue(Queue *q, Node *node)
{
    QNode *temp = (QNode*)malloc(sizeof(QNode));
    temp->data = node;
    temp->next = NULL;
    if (q->rear == NULL)
        q->front = q->rear = temp;
    else
    {
        q->rear->next = temp;
        q->rear = temp;
    }
}
Node* dequeue(Queue *q)
{
    if (isEmpty(q))
        return NULL;
    QNode *temp = q->front;
    Node *node = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return node;
}
Node* createNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
typedef struct Stack
{
    Node* arr[100];
    int top;
} Stack;
void initStack(Stack *s)
{
    s->top = -1;
}
int isStackEmpty(Stack *s)
{
    return s->top == -1;
}
void push(Stack *s, Node* node)
{
    s->arr[++(s->top)] = node;
}
Node* pop(Stack *s)
{
    return s->arr[(s->top)--];
}
Node* peek(Stack *s)
{
    return s->arr[s->top];
}
void inorder(Node *root)
{
    Stack s;
    initStack(&s);
    Node *curr = root;
    while (curr != NULL || !isStackEmpty(&s))
    {
        while (curr != NULL)
        {
            push(&s, curr);
            curr = curr->left;
        }
        curr = pop(&s);
        printf("%d ", curr->data);
        curr = curr->right;
    }
}
void preorder(Node *root)
{
    if (root == NULL) return;
    Stack s;
    initStack(&s);
    push(&s, root);
    while (!isStackEmpty(&s))
    {
        Node* node = pop(&s);
        printf("%d ", node->data);
        if (node->right) push(&s, node->right);
        if (node->left) push(&s, node->left);
    }
}
void postorder(Node *root)
{
    if (root == NULL) return;
    Stack s1, s2;
    initStack(&s1);
    initStack(&s2);
    push(&s1, root);
    while (!isStackEmpty(&s1))
    {
        Node *node = pop(&s1);
        push(&s2, node);
        if (node->left) push(&s1, node->left);
        if (node->right) push(&s1, node->right);
    }
    while (!isStackEmpty(&s2))
    {
        Node *node = pop(&s2);
        printf("%d ", node->data);
    }
}
void printParent(Node *root, int val)
{
    if (root == NULL) return;
    if ((root->left && root->left->data == val) ||
        (root->right && root->right->data == val))
    {
        printf("Parent of %d is %d\n", val, root->data);
        return;
    }
    printParent(root->left, val);
    printParent(root->right, val);
}
int findHeight(Node *root)
{
    if (root == NULL) return 0;
    int left = findHeight(root->left);
    int right = findHeight(root->right);
    return (left > right ? left : right) + 1;
}
int printAncestors(Node *root, int val)
{
    if (root == NULL) return 0;
    if (root->data == val) return 1;
    if (printAncestors(root->left, val) || printAncestors(root->right, val))
    {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}
int countLeafNodes(Node *root)
{
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n\n");
    printParent(root, 5);
    printf("Height of tree: %d\n", findHeight(root));
    printf("Ancestors of 5: ");
    printAncestors(root, 5);
    printf("\nLeaf nodes count: %d\n", countLeafNodes(root));
    return 0;
}
