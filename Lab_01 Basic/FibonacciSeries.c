/*
Lab 1 - Cat B: Print Fibonacci series for n terms using recursion
Fibonacci Recurrence: F(n) = F(n-1) + F(n-2), F(0)=0, F(1)=1
Time Complexity: O(2^n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <time.h>

int Fibonacci(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    int n;

    printf("Enter Number of Terms: ");
    scanf("%d", &n);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", Fibonacci(i));
    }
    printf("\n");

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}