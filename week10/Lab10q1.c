#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data; n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int data) {
    if (!root) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

Node* search(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = NULL;
    int choice, val;
    while (1) {
        printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Delete\n7.Find Min\n8.Find Max\n9.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
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
                scanf("%d", &val);
                if (search(root, val)) printf("Found %d\n", val);
                else printf("Not found\n");
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 7:
                {
                    Node* min = findMin(root);
                    if (min) printf("Min: %d\n", min->data);
                    else printf("Tree empty\n");
                }
                break;
            case 8:
                {
                    Node* max = findMax(root);
                    if (max) printf("Max: %d\n", max->data);
                    else printf("Tree empty\n");
                }
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
