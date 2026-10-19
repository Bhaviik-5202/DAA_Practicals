/*
Lab 4 - Cat A: Sort array elements using Heap Sort and observe CPU time
Time Complexity: O(n log n) in all cases
Space Complexity: O(1)
*/

#include <stdio.h>
#include <time.h>
#define SIZE 1000

void maxHeapify(int arr[], int n, int i) {

    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeapify(arr, n, largest);   
    }
}

void heapSort(int arr[], int n) {

    for (int i = (n/2) - 1; i >= 0; i--){
        maxHeapify(arr, n, i);
    }

    for (int j = n - 1; j > 0; j--) {
        int temp = arr[0];
        arr[0] = arr[j];
        arr[j] = temp;

        maxHeapify(arr, j, 0);
    }
}

int main() {

    int arr[SIZE];
    
    FILE *file;
    file = fopen("Worst_1000.txt", "r");
    // file = fopen("Best_1000.txt", "r");
    // file = fopen("Avg_1000.txt", "r");

    if (file == NULL) {
        printf("Error, Opening Worst_1000.txt\n");
    }
    // if (file == NULL) {
    //     printf("Error, Opening Best_1000.txt\n");
    // }
    // if (file == NULL) {
    //     printf("Error, Opening Avg_1000.txt\n");
    // }
    
    for (int i = 0; i < SIZE; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
    
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    heapSort(arr, SIZE);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted Array : ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nExecution Time = %f Seconds\n", cpu_time_used);
    
    return 0;
}