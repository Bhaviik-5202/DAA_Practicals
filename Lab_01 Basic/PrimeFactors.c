/*
Lab 1 - Cat B: Print all prime factors of a number
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <time.h>

void primeFactors(int n) {
    int c = 2;

    while (n > 1) {
        if (n % c == 0) {
            printf("%d ", c);
            n /= c;
        } else {
            c++;
        }
    }
}

int main() {
    int n;

    printf("Enter Number: ");
    scanf("%d", &n);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    printf("Prime Factors: ");
    primeFactors(n);
    printf("\n");
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}