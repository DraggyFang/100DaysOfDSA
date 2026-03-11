#include <stdio.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

int isEmpty(Deque *dq) {
    return dq->size == 0;
}

int isFull(Deque *dq) {
    return dq->size == MAX;
}

void push_front(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }

    dq->arr[dq->front] = value;
    dq->size++;
}

void push_back(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }

    dq->arr[dq->rear] = value;
    dq->size++;
}

void pop_front(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow\n");
        return;
    }

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }

    dq->size--;
}

void pop_back(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow\n");
        return;
    }

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }

    dq->size--;
}

int front(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->arr[dq->front];
}

int back(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

int size(Deque *dq) {
    return dq->size;
}

void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    push_back(&dq, 10);
    push_back(&dq, 20);
    push_front(&dq, 5);
    push_front(&dq, 2);

    display(&dq);

    pop_front(&dq);
    pop_back(&dq);

    display(&dq);

    printf("Front: %d\n", front(&dq));
    printf("Back: %d\n", back(&dq));
    printf("Size: %d\n", size(&dq));

    return 0;
}
