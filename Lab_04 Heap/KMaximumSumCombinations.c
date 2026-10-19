/*
Lab 4 - Cat B: Top k maximum sum combinations from two arrays using Heap Sort
Time Complexity: O(n^2 log n)
Space Complexity: O(n^2)
*/

#include <stdio.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i, temp;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int n, k, i, j;
    int index = 0;

    printf("Enter size of arrays: ");
    scanf("%d", &n);

    int a[n], b[n];

    printf("Enter elements of array A:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter elements of array B:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int sum[n * n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum[index++] = a[i] + b[j];
        }
    }

    heapSort(sum, index);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Top %d Maximum Sums:\n", k);
    for (i = index - 1; i >= index - k; i--)
        printf("%d ", sum[i]);
    printf("\n");

    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}