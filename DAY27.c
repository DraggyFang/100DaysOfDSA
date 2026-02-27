#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Returns tail of the list and its length
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* getTail(struct Node* head) {
    while (head->next != NULL)
        head = head->next;
    return head;
}

struct Node* insert(struct Node* head, int data) {
    struct Node* node = createNode(data);
    if (head == NULL) return node;
    getTail(head)->next = node;
    return head;
}

struct Node* findIntersection(struct Node* h1, struct Node* h2) {
    int len1 = getLength(h1);
    int len2 = getLength(h2);

    // Advance the longer list
    while (len1 > len2) { h1 = h1->next; len1--; }
    while (len2 > len1) { h2 = h2->next; len2--; }

    // Move both until they meet
    while (h1 != NULL && h2 != NULL) {
        if (h1->data == h2->data)  // value-based intersection
            return h1;
        h1 = h1->next;
        h2 = h2->next;
    }
    return NULL;
}

int main() {
    int n, m, val;

    scanf("%d", &n);
    struct Node* list1 = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        list1 = insert(list1, val);
    }

    scanf("%d", &m);
    struct Node* list2 = NULL;
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        list2 = insert(list2, val);
    }

    struct Node* result = findIntersection(list1, list2);

    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}
