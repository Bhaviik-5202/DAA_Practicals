/*
Lab 2 - Cat C: Check if a number can be represented as sum of two or more consecutive positive integers
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <time.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int found = 0;
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for(int s = 1; s < n; s++) {
        int sum = 0;

        for(int j = s; j < n; j++) {
            sum += j;

            if(sum == n) {
                found = 1;
                break;
            }

            if(sum > n)
                break;
        }

        if(found)
            break;
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if(found)
        printf("True\n");
    else
        printf("False\n");

    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}