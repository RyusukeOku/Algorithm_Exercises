#include <stdio.h>

double fib(double n) {
    if (n <= 1) {
        return n;
    }

    double a = 0, b = 1, sum;
    for (int i = 2; i <= n; i++) {
        sum = a + b;
        a = b;
        b = sum;
    }
    return b;
}

int main() {
    printf("%f\n", fib(10));
    printf("%f\n", fib(100));
    printf("%f\n", fib(1000));

    return 0;
}
