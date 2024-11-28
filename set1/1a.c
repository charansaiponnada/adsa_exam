#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int height(struct node* node) {
    if (node == NULL)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
int isBalanced(struct node* root) {
    if (root == NULL)
        return 1;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}
struct node* insertNode(struct node* root, int data) {
    if (root == NULL)
        return newNode(data);
    printf("Enter 1 to insert %d to the left of %d, 2 for right: ", data, root->data);
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}
struct node* buildTree() {
    struct node* root = NULL;
    printf("Enter the number of nodes: ");
    int n, data;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value of node %d: ", i + 1);
        scanf("%d", &data);
        if (root == NULL)
            root = newNode(data);
        else
            root = insertNode(root, data);
    }
    return root;
}
int main() {
    struct node* root = buildTree();
    if (isBalanced(root))
        printf("Tree is AVL\n");
    else
        printf("Tree is not AVL\n");
    return 0;
}