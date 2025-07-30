#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

//4 radix sort
int bit(int number, int digit) {
    return (number / digit) % 10;
}

// 配列の最大値を取得する関数
int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 基数ソートを実行する関数
void radixsort(int a[], int size) {
    // 最大値を求める
    int max = getMax(a, size);

    // 各桁についてソート
    for (int digit = 1; max / digit > 0; digit *= 10) {
        int output[size];
        int count[10] = {0};

        // 各桁ごとの出現回数を数える
        for (int i = 0; i < size; i++) {
            count[bit(a[i], digit)]++;
        }

        // count[i] が i の出現回数以上の要素数を持つように調整
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // output 配列を構築
        for (int i = size - 1; i >= 0; i--) {
            output[count[bit(a[i], digit)] - 1] = a[i];
            count[bit(a[i], digit)]--;
        }

        // arr を更新
        for (int i = 0; i < size; i++) {
            a[i] = output[i];
        }
    }
}

int main() {
    int a[5] = {43, 93, 57, 5, 2};
    int sizeOfArrayA = sizeof(a) / sizeof(a[0]);//配列のサイズを取得

    beforeArray(a, sizeOfArrayA);

    radixsort(a, sizeOfArrayA);

    afterArray(a, sizeOfArrayA);

    return 0;
}