#include <stdio.h>

/* Factorial without recursion (iterative) */
unsigned long long factIterative(int n) {
    unsigned long long f = 1;
    int i;
    for (i = 1; i <= n; i++)
        f = f * i;
    return f;
}

/* Factorial with recursion */
unsigned long long factRecursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factRecursive(n - 1);
}

int main() {
    int n;

    printf("Enter a non-negative number (max 20): ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 0;
    }
    if (n > 20) {
        printf("Number too large, result will overflow.\n");
        return 0;
    }

    printf("Factorial of %d (without recursion) = %llu\n", n, factIterative(n));
    printf("Factorial of %d (with recursion)    = %llu\n", n, factRecursive(n));

    return 0;
}
