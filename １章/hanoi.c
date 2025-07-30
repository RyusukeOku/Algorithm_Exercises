#include <stdio.h>

void hanoi(int n, char from, char to, char mid) {
    if (n == 1) {
        printf("move disk#1 from %c to %c\n", from, to);
    } else {
        hanoi(n - 1, from, mid, to);
        printf("move disk#%d from %c to %c\n", n, from, to);
        hanoi(n - 1, mid, to, from);
    }
}

int main() {
    int n = 3;
    hanoi(n, 'a', 'c', 'b');
    return 0;
}
