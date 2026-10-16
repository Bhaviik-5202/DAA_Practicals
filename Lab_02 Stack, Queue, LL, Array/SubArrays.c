/*
Lab 2 - Cat B: Generate all possible subarrays of a given array
Time Complexity: O(n^3)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <time.h>

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t start, end;
    double cpu_time_used;

    printf("All Possible Subarrays:\n");

    start = clock();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            printf("[ ");

            for (int k = i; k <= j; k++) {
                printf("%d ", arr[k]);
            }

            printf("]\n");
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}