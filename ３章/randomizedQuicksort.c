#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//3 randomize quick sort
// 配列の要素を交換する補助関数
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//ソート前の配列を表示
void beforeArray(int a[], int size){
    printf("before sort: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//ソート後の配列を表示
void afterArray(int a[], int size){
    printf("after sort: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//partition
int partition (int array[], int left, int right) {
    int i, j, pivot;
    i = left;
    j = right + 1;
    pivot = left;   // 先頭要素をpivotとする

    do {
        do { i++; } while (array[i] < array[pivot]);
        do { j--; } while (array[pivot] < array[j]);
        // pivotより小さいものを左へ、大きいものを右へ
        if (i < j) { swap(&array[i], &array[j]); }
    } while (i < j);

    swap(&array[pivot], &array[j]);   //pivotを更新

    return j;
}

//randomized-partition
int randomizedPartition(int a[], int p, int r){
    srand(time(NULL));

    int i, j, pivot;
    i = p - 1;
    j = r + 1;
    pivot = p + rand()%(r - p + 1);//pivotをランダムに決める
    swap(&a[pivot], &a[r]);

    return partition(a, p, r);
}

//randomized-quicksort
void randomizedQuicksort(int a[], int p, int r){
    int q;
    if (p < r)
    {
        q = randomizedPartition(a, p, r);
        randomizedQuicksort(a, p , q - 1);
        randomizedQuicksort(a, q + 1, r);
    }
}

int main() {
    int b[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    beforeArray(b, 10);
    randomizedQuicksort(b, 0, 10);
    afterArray(b, 10);
    return 0;
}