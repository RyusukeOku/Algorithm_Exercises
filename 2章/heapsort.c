#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// 配列の要素を交換する関数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ヒープを構築する関数
void heapify(int arr[], int n, int i) {
    int largest = i;      // 親ノード
    int left_child = 2 * i + 1;   // 左の子ノード
    int right_child = 2 * i + 2;  // 右の子ノード

    // 左の子が親より大きい場合
    if (left_child < n && arr[left_child] > arr[largest]) {
        largest = left_child;
    }

    // 右の子が親より大きい場合
    if (right_child < n && arr[right_child] > arr[largest]) {
        largest = right_child;
    }

    // 親が最大でない場合は交換して再帰呼び出し
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// ヒープソートのメイン関数
void heapSort(int arr[], int n) {
    // ヒープを構築
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // ヒープから要素を1つずつ取り出してソート
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);  // 最大値（根）を配列の末尾と交換
        heapify(arr, i, 0);      // ヒープを再構築
    }
}

int main() {
    // ファイルのポインタを宣言
    FILE *file;
    
    // ファイルを開く
    file = fopen("data3.txt", "r");
    
    // ファイルが開けなかった場合
    if (file == NULL) {
        fprintf(stderr, "ファイルを開けませんでした。\n");
        return 1;
    }

    // 配列のサイズ
    const int array_size = 100000;

    // 配列を動的に確保
    int *data_array = (int *)malloc(array_size * sizeof(int));

    // 配列が確保できなかった場合
    if (data_array == NULL) {
        fprintf(stderr, "メモリを確保できませんでした。\n");
        fclose(file);
        return 1;
    }

    // ファイルからデータを読み込んで配列に格納
    int i = 0;
    while (fscanf(file, "%d", &data_array[i]) == 1) {
        i++;
        // 配列がいっぱいになったら終了
        if (i >= array_size) {
            break;
        }
    }

    // ファイルを閉じる
    fclose(file);

    // 読み込んだデータの要素数を表示
    printf("データの要素数: %d\n", i);

    long cpu_time, cpu_time1, cpu_time2;
    double sec;

    beforeArray(data_array, i);
    heapSort(data_array, i);
    afterArray(data_array, i);
    /* CPU時間をチェック */
    cpu_time = clock();
    /* 秒に直す */
    sec = (double)cpu_time / CLOCKS_PER_SEC;
    printf("ソートするににかかった時間: %f秒\n", sec);

    // メモリを解放
    free(data_array);
}
