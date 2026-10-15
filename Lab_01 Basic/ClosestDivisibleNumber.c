/*
Lab 1 - Cat C: Number closest to n and divisible by m (Iterative & Quotient approaches)
Time Complexity: Approach 1: O(m), Approach 2: O(1)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Approach 1: Naive (Iterative Checking) - O(m) Time
int closestNumberNaive(int n, int m) {
    int absM = abs(m);
    for (int i = 0; i <= absM; i++) {
        int c1 = n - i;
        int c2 = n + i;
        int c1Div = (c1 % m == 0);
        int c2Div = (c2 % m == 0);

        if (c1Div && c2Div) {
            return (abs(c1) >= abs(c2)) ? c1 : c2;
        } else if (c1Div) {
            return c1;
        } else if (c2Div) {
            return c2;
        }
    }
    return n;
}

// Approach 2: Expected (Finding Quotient) - O(1) Time
int closestNumberQuotient(int n, int m) {
    int q = n / m;
    int n1 = m * q;
    int n2 = ((long long)n * m > 0) ? (m * (q + 1)) : (m * (q - 1));

    int d1 = abs(n - n1);
    int d2 = abs(n - n2);

    if (d1 < d2) {
        return n1;
    } else if (d2 < d1) {
        return n2;
    } else {
        return (abs(n1) >= abs(n2)) ? n1 : n2;
    }
}

int main() {
    int n, m;

    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter m : ");
    scanf("%d", &m);

    if (m == 0) {
        printf("m cannot be 0\n");
        return 0;
    }

    clock_t start, end;
    double time_naive, time_quotient;

    start = clock();
    int ans_naive = closestNumberNaive(n, m);
    end = clock();
    time_naive = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    int ans_quotient = closestNumberQuotient(n, m);
    end = clock();
    time_quotient = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Approach 1 (Naive Iterative)   : %d (Time: %f Seconds)\n", ans_naive, time_naive);
    printf("Approach 2 (Expected Quotient) : %d (Time: %f Seconds)\n", ans_quotient, time_quotient);

    return 0;
}