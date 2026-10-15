/*
Lab 1 - Cat A: Factorial of an integer using recursion
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <time.h>

int Factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * Factorial(n - 1);
}

int main() {
    int n;

    printf("Enter Number: ");
    scanf("%d", &n);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int ans = Factorial(n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Factorial of %d = %d\n", n, ans);
    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}