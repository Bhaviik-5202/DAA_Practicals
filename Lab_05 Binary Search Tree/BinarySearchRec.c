/*
Lab 5 - Cat A: Binary search algorithm using recursive method
Time Complexity: Best: O(1), Worst/Average: O(log n)
Space Complexity: O(log n)
*/

#include <stdio.h>
#include <time.h>

#define SIZE 1000

int binarySearchRec(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binarySearchRec(arr, left, mid - 1, target);
    } else {
        return binarySearchRec(arr, mid + 1, right, target);
    }

}

int main() {
    int arr[SIZE];

    FILE *file = fopen("Best_1000.txt", "r");
    // FILE *file = fopen("Best_10000.txt", "r");
    // FILE *file = fopen("Best_100000.txt", "r");

    if (file == NULL) {
        printf("Error Opening Best_1000.txt\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    int tar;
    printf("Enter Element to Find: ");
    scanf("%d", &tar);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int ans = binarySearchRec(arr, 0, SIZE - 1, tar);
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