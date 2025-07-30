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

int insertion(int a[], int size){
    int i, j, key;
    for(j = 1; j < size; j++){
        int key = a[j];
        int i = j - 1;
        while ((i >= 0) && (a[i] > key))
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
}

int main(){
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
    insertion(data_array, i);
    afterArray(data_array, i);
    /* CPU時間をチェック */
    cpu_time = clock();
    /* 秒に直す */
    sec = (double)cpu_time / CLOCKS_PER_SEC;
    printf("ソートするににかかった時間: %f秒\n", sec);

    // メモリを解放
    free(data_array);
}