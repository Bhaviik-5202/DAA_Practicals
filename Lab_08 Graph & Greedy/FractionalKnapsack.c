/*
Lab 08 - Cat A: Fractional Knapsack Problem (Greedy Approach)
Time Complexity: O(N^2) using simple sort, or O(N log N)
Space Complexity: O(N)
*/
#include <stdio.h>
#include <time.h>

void fractionalKnapsack(int n, float capacity, float weight[], float value[]) {
    float ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = value[i] / weight[i];
    }

    // Sort items by ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                float temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                temp = value[j];
                value[j] = value[j + 1];
                value[j + 1] = temp;
            }
        }
    }

    float currentWeight = 0.0;
    float totalValue = 0.0;

    printf("\nSelected Items:\n");
    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= capacity) {
            currentWeight += weight[i];
            totalValue += value[i];
            printf("Weight: %.2f, Value: %.2f (100%% taken)\n", weight[i], value[i]);
        } else {
            float remain = capacity - currentWeight;
            if (remain > 0) {
                float fraction = remain / weight[i];
                totalValue += value[i] * fraction;
                printf("Weight: %.2f, Value: %.2f (%.2f%% taken)\n", weight[i], value[i], fraction * 100);
            }
            break;
        }
    }

    printf("Total Maximum Value = %.2f\n", totalValue);
}

int main() {
    int n;
    float capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    float weight[n], value[n];

    printf("Enter weight and value for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &weight[i], &value[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    clock_t start = clock();
    fractionalKnapsack(n, capacity, weight, value);
    clock_t end = clock();

    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution Time = %f Seconds\n", cpu_time);

    return 0;
}
