/*
Lab 5 - Cat A: Binary search algorithm using iterative method
Time Complexity: Best: O(1), Worst/Average: O(log n)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <time.h>

#define SIZE 1000

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    int arr[SIZE];

    FILE *file = fopen("Best_1000.txt", "r");
    // FILE *file = fopen("Best_10000.txt", "r");
    // FILE *file = fopen("Best_100000.txt", "r");

    if (file == NULL)
    {
        printf("Error Opening Best_1000.txt\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (fscanf(file, "%d", &arr[i]) != 1)
        {
            printf("Error Reading File\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    int tar;
    printf("Enter Element to Find: ");
    scanf("%d", &tar);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int ans = binarySearch(arr, 0, SIZE - 1, tar);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (ans == -1) {
        printf("Element Not Found.\n");
    } else {
        printf("Element Found At Index = %d\n", ans);
    }

    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}