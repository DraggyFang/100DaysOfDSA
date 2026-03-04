#include <stdio.h>

#define MAX 100

int main() {
    int stack[MAX];
    int n, m;
    int top = -1;

    // Read number of elements
    scanf("%d", &n);

    // Push elements into stack
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        stack[++top] = x;
    }

    // Number of pops
    scanf("%d", &m);

    // Pop m elements
    for(int i = 0; i < m; i++) {
        if(top >= 0)
            top--;
    }

    // Print remaining elements from top to bottom
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
