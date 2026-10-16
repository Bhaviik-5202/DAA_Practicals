/*
Lab 2 - Cat B: Generate all possible subarrays of a given array
Time Complexity: O(n^3)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <time.h>

int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter Size Of Array : ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        printf("Enter Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nAll Possible Subarrays:\n");

    start = clock();
    for(int s = 0; s < n; s++) {
        for(int e = s; e < n; e++) {

            printf("[ ");

            for(int k = s; k <= e; k++) {
                printf("%d ", arr[k]);
            }

            printf("]\n");
        }
    }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTotal Subarrays = %d\n", n * (n + 1) / 2);
    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}