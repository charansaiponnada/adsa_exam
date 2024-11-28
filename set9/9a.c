#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}
int height(Node* node) {
    return node ? node->height : 0;
}
int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}
void updateHeight(Node* node) {
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
}
Node* LLRotation(Node* root) {
    Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}
Node* RRRotation(Node* root) {
    Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}
Node* insert(Node* root, int data) {
    if (!root) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    updateHeight(root);
    int balance = getBalance(root);
    if (balance > 1 && data < root->left->data) return LLRotation(root);
    if (balance < -1 && data > root->right->data) return RRRotation(root);
    if (balance > 1 && data > root->left->data) {
        root->left = RRRotation(root->left);
        return LLRotation(root);
    }
    if (balance < -1 && data < root->right->data) {
        root->right = LLRotation(root->right);
        return RRRotation(root);
    }
    return root;
}
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);
    printf("In-order traversal of the AVL tree: ");
    inorder(root);
    printf("\n");
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    Node* result = search(root, key);
    if (result != NULL) {
        printf("Element %d found in the AVL tree.\n", key);
    } else {
        printf("Element %d not found in the AVL tree.\n", key);
    }
    return 0;
}