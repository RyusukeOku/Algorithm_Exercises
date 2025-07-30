#include <stdio.h>
#include <stdlib.h>

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

//2 quicksort
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

// クイックソート
void quicksort(int a[], int left, int right) {
    int pivot;
    if (left < right) {
        pivot = partition(a, left, right);
        quicksort(a, left, pivot - 1);
        quicksort(a, pivot + 1, right);
    }
}

int main() {
    int a[5] = {43, 93, 57, 5, 2};
    int sizeOfArrayA = sizeof(a) / sizeof(a[0]);//配列のサイズを取得

    beforeArray(a, sizeOfArrayA);
    quicksort(a, 0, sizeOfArrayA);
    afterArray(a, sizeOfArrayA);

    return 0;
}
