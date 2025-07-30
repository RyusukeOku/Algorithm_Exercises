#include <stdio.h>
#include <stdlib.h>

void max_heapify(int a[], int size, int i) {
    int l, r, largest;
    largest = i;
    l = 2 * i + 1;
    r = 2 * i + 2;

    if ((l < size) && (a[l] > a[i])) {
        largest = l;
    }

    if ((r < size) && (a[r] > a[largest])) {
        largest = r;
    }

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, size, largest);
    }
}

void build_max_heap(int a[], int size) {
    for (int s = size / 2 - 1; s >= 0; s--) {
        max_heapify(a, size, s);
    }
}

int heap_extract_max(int a[], int size) {
    if (size < 1) {
        printf("ヒープアンダーフロー");
    }

    int max = a[0];
    a[0] = a[size - 1];

    size = size - 1;

    max_heapify(a, size, 0);

    return max;
}

int main() {
    int a[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int arraySize = sizeof(a) / sizeof(int);
    build_max_heap(a, arraySize);
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }

    printf("\n%d", heap_extract_max(a, arraySize));

    return 0;
}
