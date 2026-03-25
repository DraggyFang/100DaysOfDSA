#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue node with horizontal distance
struct QNode {
    struct Node* node;
    int hd;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue implementation
struct QNode queue[MAX];
int front = 0, rear = 0;

void enqueue(struct Node* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

struct QNode dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    int result[200][100]; // store nodes
    int count[200] = {0}; // count per vertical
    int offset = 100;     // shift index to avoid negative

    enqueue(root, 0);

    while (!isEmpty()) {
        struct QNode temp = dequeue();
        struct Node* curr = temp.node;
        int hd = temp.hd;

        int index = hd + offset;
        result[index][count[index]++] = curr->data;

        if (curr->left)
            enqueue(curr->left, hd - 1);
        if (curr->right)
            enqueue(curr->right, hd + 1);
    }

    // Print result from leftmost to rightmost
    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
}

// Example usage
int main() {
    // Constructing tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    verticalOrder(root);

    return 0;
}
