#include <stdio.h>
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

void heapsort(int a[], int size) {
    build_max_heap(a, size);
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                max_heapify(a, i, 0);
            }
        }
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
    heapsort(data_array, i);
    afterArray(data_array, i);
    /* CPU時間をチェック */
    cpu_time = clock();
    /* 秒に直す */
    sec = (double)cpu_time / CLOCKS_PER_SEC;
    printf("ソートするににかかった時間: %f秒\n", sec);

    // メモリを解放
    free(data_array);
}

