/*
Lab 06 - Cat A: Merge Sort
Time Complexity: Best O(N log N), Average O(N log N), Worst O(N log N)
Space Complexity: O(N)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000

static int ans[SIZE];

void merge(int arr[], int lb, int ub, int mid) {
    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j]) {
            ans[k] = arr[i];
            i++;
        } else {
            ans[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        ans[k] = arr[i];
        i++;
        k++;
    }
    while (j <= ub) {
        ans[k] = arr[j];
        j++;
        k++;
    }
    
    for (int idx = lb; idx <= ub; idx++) {
        arr[idx] = ans[idx];
    }
}

void mergeSort(int arr[], int lb, int ub) {
    if (lb >= ub) {
        return;
    }
    
    int mid = lb + (ub - lb) / 2;
    mergeSort(arr, lb, mid);
    mergeSort(arr, mid + 1, ub);
    merge(arr, lb, ub, mid);
}

int main(void) {
    int arr[SIZE];

    FILE *file = fopen("Avg_1000.txt", "r");
    if (file == NULL) {
        file = fopen("Lab_06 Quick&Merge/Avg_1000.txt", "r");
    }

    if (file == NULL)
    {
        printf("Error Opening Avg_1000.txt\n");
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

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    mergeSort(arr, 0, SIZE - 1);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted Array (sample output):\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("... ");
    for (int i = SIZE - 5; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}