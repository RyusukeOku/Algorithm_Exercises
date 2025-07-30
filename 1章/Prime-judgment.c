#include <stdio.h>
#include <math.h>

int isprime(int n){
    int i = 2;
    while (i <= sqrt(n)){
        if (n % i == 0)
        {
            return 0;
        }
        i+=1;
    }
    return 1;
}

int main(){
    int n = 7;
    printf("%d", isprime(n)); //素数なら１、そうでないなら０を出力する
}