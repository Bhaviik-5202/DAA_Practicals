/*
Lab 3 - Cat A: Sort array elements using Insertion Sort and observe CPU time
Time Complexity: Best: O(n), Worst/Average: O(n^2)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <time.h>
#define SIZE 1000

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[SIZE];
    int n;

    FILE *file = fopen("Worst_1000.txt", "r");
    if (file == NULL) {
        file = fopen("Lab_03 Sorting/Worst_1000.txt", "r");
    }

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter number of elements to read from file (up to 1000): ");
    scanf("%d", &n);
    if (n > SIZE || n <= 0) {
        n = SIZE;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    insertionSort(arr, n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nAlgorithm Name    : Insertion Sort\n");
    printf("Number of Elements: %d\n", n);
    printf("Execution Time    : %f Seconds\n", cpu_time_used);

    printf("Sorted Array: ");
    int limit = (n < 20) ? n : 20;
    for (int i = 0; i < limit; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}