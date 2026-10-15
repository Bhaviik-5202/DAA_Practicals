/*
Lab 1 - Cat A: Calculate power of a number using recursion
Time Complexity: O(exp)
Space Complexity: O(exp)
*/

#include <stdio.h>
#include <time.h>

int Power(int base, int exp) {
    if (exp == 0) {
        return 1;
    }

    return base * Power(base, exp - 1);
}

int main() {
    int base, exp;

    printf("Enter Base Number: ");
    scanf("%d", &base);

    printf("Enter Exponent: ");
    scanf("%d", &exp);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int ans = Power(base, exp);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%d ^ %d = %d\n", base, exp, ans);
    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}