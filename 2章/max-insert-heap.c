#include <stdio.h>
#include <limits.h>

void heap_increase_key(int a[], int i, int key) {
    if (key < a[i]) {
        printf("新しいキーは現在のキーより小さい");
    }

    a[i] = key;
    int parent = (i - 1) / 2; //親ノードの番号は子ノードの番号を2で割ったときの商

    if (parent >= 0)
    {
        if (a[i] > a[parent])
        {
            int temp = a[i];
            a[i] = a[parent];
            a[parent] = temp;
            heap_increase_key(a, parent, key);
        }
    }
}

void max_insert_heap(int a[], int* size, int key) {
    *size = *size + 1;
    a[*size] = INT_MIN;
    a[*size - 1] = key;

    heap_increase_key(a, *size - 1, key);
}

int main() {
    int a[5] = {9, 5, 3, 2, 4};
    int arraySize = 5;

    max_insert_heap(a, &arraySize, 10);

    for (int i = 0; i < arraySize; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}