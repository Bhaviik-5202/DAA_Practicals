/*
Lab 06 - Cat A: Quick Sort
Time Complexity: Best O(N log N), Average O(N log N), Worst O(N^2)
Space Complexity: O(log N) auxiliary stack space
*/
#include <stdio.h>
#include <time.h>
#define SIZE 1000

int pivot(int arr[], int i, int j) {
    int p = arr[i];
    int left = i;
    int right = j;
    
    while (left < right) {
        while (left < j && arr[left] <= p) {
            left++;
        }
        while (arr[right] > p) {
            right--;
        }

        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    int temp = arr[i];
    arr[i] = arr[right];
    arr[right] = temp;
    
    return right;
}

void quickSort(int arr[], int i, int j) {
    if (i < j) {
        int p = pivot(arr, i, j);
        quickSort(arr, i, p - 1);
        quickSort(arr, p + 1, j);
    }
}


int main(void) {
    int arr[SIZE];

    FILE *file = fopen("Worst_1000.txt", "r");
    if (file == NULL) {
        file = fopen("Lab_06 Quick&Merge/Worst_1000.txt", "r");
    }

    if (file == NULL)
    {
        printf("Error Opening Worst_1000.txt\n");
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
    quickSort(arr, 0, SIZE - 1);
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