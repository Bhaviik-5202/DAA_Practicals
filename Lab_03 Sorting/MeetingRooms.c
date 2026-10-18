/*
Lab 3 - Cat C: Determine whether a person can attend all meetings without overlaps
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <time.h>

int main() {
    int n, i, j, temp;
    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int arr[n][2];

    printf("Enter Start and End Time:\n");
    for (i = 0; i < n; i++)
        scanf("%d%d", &arr[i][0], &arr[i][1]);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j][0] > arr[j + 1][0]) {
                temp = arr[j][0];
                arr[j][0] = arr[j + 1][0];
                arr[j + 1][0] = temp;

                temp = arr[j][1];
                arr[j][1] = arr[j + 1][1];
                arr[j + 1][1] = temp;
            }
        }
    }

    int possible = 1;
    for (i = 0; i < n - 1; i++) {
        if (arr[i][1] > arr[i + 1][0]) {
            possible = 0;
            break;
        }
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (possible) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}