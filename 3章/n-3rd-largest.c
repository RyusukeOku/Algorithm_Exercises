#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//配列をソート
// 配列の要素を交換する補助関数
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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

// 中央値を求めるプログラム
int n3rd(int a[], int n) {
    int n3rd = n / 3;
    randomizedQuicksort(a, 0, n);
    return a[n3rd];
}

int main() {
    int n;
    // ユーザーに要素数を入力してもらう
    printf("配列の要素数を入力してください: ");
    scanf("%d", &n);

    // 入力された要素数に基づいて配列を宣言
    int array[n];

    // 配列に数字を入力してもらう
    printf("数字を入力してください:\n");
    for (int i = 0; i < n; ++i) {
        printf("要素 %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("n/3番目に大きい数字:%d", n3rd(array, n));

    return 0;
}
