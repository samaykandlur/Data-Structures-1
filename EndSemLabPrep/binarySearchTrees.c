#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* right;
    struct Node* left;
} Node;

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->right = n->left = NULL;
    return n;
}

Node* insert(Node* root, int data) {
    Node* n = createNode(data);
    if (!root) return n;

    Node* parent = NULL;
    Node* current = root;

    while (current != NULL) {
        parent = current;
        if (data > current->data)
            current = current->right;
        else
            current = current->left;
    }

    if (data > parent->data)
        parent->right = n;
    else
        parent->left = n;

    return root;
}

void inorder(Node* root) {
    Node* stack[100];
    int top = -1;
    Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorder(Node* root) {
    if (!root) return;
    Node* stack[100];
    int top = -1;

    stack[++top] = root;
    while (top != -1) {
        Node* n = stack[top--];
        printf("%d ", n->data);

        if (n->right)
            stack[++top] = n->right;
        if (n->left)
            stack[++top] = n->left;
    }
}

void postorder(Node* root) {
    if (!root) return;
    Node* stack1[100];
    Node* stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1) {
        Node* n = stack1[top1--];
        stack2[++top2] = n;

        if (n->left)
            stack1[++top1] = n->left;
        if (n->right)
            stack1[++top1] = n->right;
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

Node* search(Node* root, int key) {
    Node* current = root;
    while (current != NULL) {
        if (key == current->data) return current;
        else if (key > current->data) current = current->right;
        else current = current->left;
    }
    return NULL;
}

Node* findMin(Node* root) {
    if (!root) return NULL;
    Node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* findMax(Node* root) {
    if (!root) return NULL;
    Node* current = root;
    while (current->right != NULL)
        current = current->right;
    return current;
}

Node* deleteNode(Node* root, int key) {
    Node* parent = NULL;
    Node* current = root;

    // Search node
    while (current != NULL && current->data != key) {
        parent = current;
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL)
        return root; // not found

    // Node with two children
    if (current->left != NULL && current->right != NULL) {
        Node* successorParent = current;
        Node* successor = current->right;

        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }

        current->data = successor->data;
        current = successor;
        parent = successorParent;
    }

    // Node with 0 or 1 child
    Node* child = (current->left) ? current->left : current->right;

    if (parent == NULL)
        root = child;
    else if (parent->left == current)
        parent->left = child;
    else
        parent->right = child;

    free(current);
    return root;
}

void printLevelOrder(Node* root) {
    if (!root) return;

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    printf("Level order: ");
    while (front < rear) {
        Node* curr = queue[front++];
        printf("%d ", curr->data);

        if (curr->left)
            queue[rear++] = curr->left;
        if (curr->right)
            queue[rear++] = curr->right;
    }
    printf("\n");
}

int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n");
        printf("5. Search\n6. Delete\n7. Find Minimum\n8. Find Maximum\n9. Level Order\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 2:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            printf("Enter value to search: ");
            scanf("%d", &data);
            if (search(root, data))
                printf("Element %d found.\n", data);
            else
                printf("Element %d not found.\n", data);
            break;

        case 6:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            printf("Node deleted if present.\n");
            break;

        case 7: {
            Node* minNode = findMin(root);
            if (minNode)
                printf("Minimum value: %d\n", minNode->data);
            else
                printf("Tree empty.\n");
            break;
        }

        case 8: {
            Node* maxNode = findMax(root);
            if (maxNode)
                printf("Maximum value: %d\n", maxNode->data);
            else
                printf("Tree empty.\n");
            break;
        }

        case 9:
            printLevelOrder(root);
            break;

        case 10:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
}
