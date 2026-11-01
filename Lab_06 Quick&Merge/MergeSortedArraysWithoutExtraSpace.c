/*
Lab 06 - Cat B: Merge Two Sorted Arrays Without Extra Space
Time Complexity: O((N + M) * log(N + M))
Space Complexity: O(1)
*/
#include <stdio.h>
#include <time.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void mergeWithoutExtraSpace(int a[], int n, int b[], int m) {
    int i = n - 1;
    int j = 0;

    while (i >= 0 && j < m) {
        if (a[i] > b[j]) {
            swap(&a[i], &b[j]);
            i--;
            j++;
        } else {
            break;
        }
    }

    sort(a, n);
    sort(b, m);
}

int main(void) {
    int n, m;

    printf("Enter size of first array a[]: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int a[n];
    printf("Enter %d sorted elements for array a[]:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter size of second array b[]: ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int b[m];
    printf("Enter %d sorted elements for array b[]:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    clock_t start = clock();
    mergeWithoutExtraSpace(a, n, b, m);
    clock_t end = clock();

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nRearranged array a[]: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nRearranged array b[]: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}
