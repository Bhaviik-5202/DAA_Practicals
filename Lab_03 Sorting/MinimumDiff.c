/*
Lab 3 - Cat B: Find minimum difference between any pair using sorting
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <time.h>

int main() {
    int n, i, j, temp, minDiff;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    minDiff = arr[1] - arr[0];

    for (i = 1; i < n - 1; i++) {
        if (arr[i + 1] - arr[i] < minDiff)
            minDiff = arr[i + 1] - arr[i];
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Minimum Difference = %d\n", minDiff);
    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}