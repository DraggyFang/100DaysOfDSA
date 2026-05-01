#include <stdio.h>

void bucketSort(float arr[], int n) {
    float buckets[n][n];
    int count[n];

    for (int i = 0; i < n; i++)
        count[i] = 0;

    // Put elements into buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        buckets[bi][count[bi]++] = arr[i];
    }

    // Sort each bucket (Insertion sort)
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < count[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;

            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Concatenate
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < count[i]; j++)
            arr[index++] = buckets[i][j];
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25};
    int n = sizeof(arr)/sizeof(arr[0]);

    bucketSort(arr, n);

    for(int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}
