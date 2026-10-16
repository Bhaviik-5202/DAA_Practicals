/*
Lab 2 - Cat B: Rearrange array in alternate positive and negative manner preserving relative order
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <time.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos[n], neg[n];
    int p = 0, q = 0;

    clock_t start = clock();
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            pos[p++] = arr[i];
        } else {
            neg[q++] = arr[i];
        }
    }

    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }
    while (i < p) {
        arr[k++] = pos[i++];
    }
    while (j < q) {
        arr[k++] = neg[j++];
    }

    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Rearranged Array : ");
    for (int idx = 0; idx < n; idx++) {
        printf("%d ", arr[idx]);
    }
    printf("\nExecution Time = %f Seconds\n", cpu_time_used);
    return 0;
}