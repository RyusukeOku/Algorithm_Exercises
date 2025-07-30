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

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }
    int l = 0;
    int m = 0;
    for (int k = left; k <= right; k++) {
        if (l < n1 && (m >= n2 || L[l] <= R[m])) {
            a[k] = L[l];
            l++;
        } else {
            a[k] = R[m];
            m++;
        }
    }
}

void merge_sort(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
        merge(a, left, mid, right);
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
    merge_sort(data_array, 0, i);
    afterArray(data_array, i);
    /* CPU時間をチェック */
    cpu_time = clock();
    /* 秒に直す */
    sec = (double)cpu_time / CLOCKS_PER_SEC;
    printf("ソートするににかかった時間: %f秒\n", sec);

    // メモリを解放
    free(data_array);
}
