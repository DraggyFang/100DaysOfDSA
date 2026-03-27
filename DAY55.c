#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create Node
struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for BFS
struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;
    while (i < n) {
        struct Node* curr = dequeue();

        // Left child
        if (arr[i] != -1)
            curr->left = createNode(arr[i]);
        enqueue(curr->left);
        i++;

        // Right child
        if (i < n && arr[i] != -1)
            curr->right = createNode(arr[i]);
        enqueue(curr->right);
        i++;
    }
    return root;
}

// Right View
void rightView(struct Node* root) {
    if (!root) return;

    front = rear = -1;
    enqueue(root);

    while (!isEmpty()) {
        int size = rear - front + 1;

        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue();

            // Last node of level
            if (i == size - 1)
                printf("%d ", curr->data);

            if (curr->left) enqueue(curr->left);
            if (curr->right) enqueue(curr->right);
        }
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}
