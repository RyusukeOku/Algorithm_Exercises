#include <stdio.h>

int gcd(int m, int n){
    if (n > 0)
    {
        return gcd(n, m%n);
    }
    else
    {
        return m;
    }
}

int main(){
    int m = 10;
    int n = 25;
    printf("%d", gcd(m, n));
}