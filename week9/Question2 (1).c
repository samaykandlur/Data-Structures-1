#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node* createNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* createTree()
{
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);
    if (x == -1)
        return NULL;
    Node *newNode = createNode(x);
    printf("Enter left child of %d\n", x);
    newNode->left = createTree();
    printf("Enter right child of %d\n", x);
    newNode->right = createTree();
    return newNode;
}
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}
void printLevel(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}
void printLevelOrder(Node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        printLevel(root, i);
        printf("\n");
    }
}
int main()
{
    Node *root = NULL;
    printf("Create the binary tree:\n");
    root = createTree();
    printf("\nLevel Order Traversal:\n");
    printLevelOrder(root);
    return 0;
}
