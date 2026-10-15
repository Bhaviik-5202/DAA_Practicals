/*
Lab 1 - Cat A: Sum of numbers from 1 to n using recursion
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <time.h>

int Sum(int n) {
    if (n <= 1) {
        return n;
    }

    return n + Sum(n - 1);
}

int main() {
    int n;

    printf("Enter Number: ");
    scanf("%d", &n);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int ans = Sum(n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sum of Numbers from 1 to %d = %d\n", n, ans);
    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}