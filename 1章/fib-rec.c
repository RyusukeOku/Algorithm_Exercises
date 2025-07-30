#include <stdio.h>

double fib_rec(double a, double b, double count){
    if (count == 0)
    {
        return b;
    }
    else
    {
        count -= 1;
        return fib_rec((a + b), a, count);
    }
}

double fib(double n){
    return fib_rec(1, 0, n);
}

double main(){
    printf("%f\n", fib(10));
    printf("%f\n", fib(100));
    printf("%f\n", fib(1000));
    return 0;
}
