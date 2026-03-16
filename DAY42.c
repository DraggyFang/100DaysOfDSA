#include <stdio.h>

#define MAX 100

// Queue structure
struct Queue {
    int arr[MAX];
    int front, rear;
};

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Queue functions
void enqueue(struct Queue *q, int x) {
    q->arr[++q->rear] = x;
}

int dequeue(struct Queue *q) {
    return q->arr[q->front++];
}

int isQueueEmpty(struct Queue *q) {
    return q->front > q->rear;
}

// Stack functions
void push(struct Stack *s, int x) {
    s->arr[++s->top] = x;
}

int pop(struct Stack *s) {
    return s->arr[s->top--];
}

int isStackEmpty(struct Stack *s) {
    return s->top == -1;
}

// Reverse Queue using Stack
void reverseQueue(struct Queue *q) {
    struct Stack s;
    s.top = -1;

    while (!isQueueEmpty(q)) {
        push(&s, dequeue(q));
    }

    while (!isStackEmpty(&s)) {
        enqueue(q, pop(&s));
    }
}

int main() {
    int n;
    struct Queue q;

    q.front = 0;
    q.rear = -1;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    reverseQueue(&q);

    while (!isQueueEmpty(&q)) {
        printf("%d ", dequeue(&q));
    }

    return 0;
}
