#include <stdio.h>

double fib_tail(double n, double k, double l){
    if (n == 0)
    {
        return k;
    }
    else if (n == 1)
    {
        return k + l;
    }
    else
    {
        fib_tail(n - 1, l, k + l);
    }
}

double fib(double n){
    return fib_tail(n, 1, 0);
}

double main(){
    printf("%f\n", fib(10));
    printf("%f\n", fib(100));
    printf("%f\n", fib(1000));
    return 0;
}