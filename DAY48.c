#include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    // Check if it's a leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recur for left and right subtree
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Example usage
int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes: %d\n", leafCount);

    return 0;
}
