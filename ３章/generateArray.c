#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// サイズがnで、0~999までの範囲の中からランダムな数字が入った配列を生成する関数
void generateRandomArray(int b[], int n) {
    // 乱数の初期化
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        // 0から999までのランダムな整数を生成して配列に格納
        b[i] = rand() % 100;
    }
}

// 配列を表示する関数
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main() {
    // 配列のサイズ
    int n = 125; // 例としてサイズ10としますが、必要に応じて変更してください

    // 配列の生成
    int b[n];
    generateRandomArray(b, n);

    // 生成された配列を表示
    printf("Random array: ");
    printArray(b, n);

    return 0;
}