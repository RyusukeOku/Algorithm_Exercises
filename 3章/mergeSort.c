#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

//1 margesort
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
    int a[5] = {43, 93, 57, 5, 2};
    int b[25] = {57, 39, 11, 53, 65, 62, 7, 71, 19, 98, 21, 67, 34, 93, 6, 45, 16, 8, 29, 96, 7, 76, 63, 27, 7};
    int c[125] = {11, 26, 59, 16, 30, 11, 20, 61, 32, 50, 70, 37, 85, 7, 62, 35, 78, 25, 69, 44, 80, 84, 32, 33, 19, 41, 61, 10, 32, 59, 0, 36, 59, 13, 17, 57, 1, 49, 16, 95, 57, 91, 90, 3, 1, 42, 58, 39, 40, 42, 85, 29, 70, 55, 45, 74, 83, 89, 96, 57, 99, 52, 39, 92, 50, 82, 0, 5, 11, 39, 57, 61, 30, 64, 90, 58, 31, 99, 34, 53, 1, 34, 92, 14, 62, 10, 52, 62, 59, 69, 89, 50, 88, 47, 65, 62, 10, 46, 95, 21, 32, 52, 55, 11, 19, 22, 7, 82, 21, 66, 77, 29, 31, 52, 37, 94, 34, 48, 12, 75, 43, 54, 53, 20, 61};
    int sizeOfArrayA = sizeof(a) / sizeof(a[0]);//配列のサイズを取得
    int sizeOfArrayB = sizeof(b) / sizeof(b[0]);
    int sizeOfArrayC = sizeof(c) / sizeof(c[0]);

    long cpu_time, cpu_time1, cpu_time2;
    double sec;

    beforeArray(a, sizeOfArrayA);
    merge_sort(a, 0, sizeOfArrayA);
    afterArray(a, sizeOfArrayA);
    /* CPU時間をチェック */
    cpu_time = clock();
    /* 秒に直す */
    sec = (double)cpu_time / CLOCKS_PER_SEC;
    printf("配列Aをソートするににかかった時間: %f秒\n", sec);

    beforeArray(b, sizeOfArrayB);
    merge_sort(b, 0, sizeOfArrayB);
    afterArray(b, sizeOfArrayB);
    /* CPU時間をチェック */
    cpu_time1 = clock() - cpu_time;
    /* 秒に直す */
    sec = (double)cpu_time1 / CLOCKS_PER_SEC;
    printf("配列Bをソートするのにかかった時間: %f秒\n", sec);

    beforeArray(c, sizeOfArrayC);
    merge_sort(c, 0, sizeOfArrayC);
    afterArray(c, sizeOfArrayC);
    /* CPU時間をチェック */
    cpu_time2 = clock() - cpu_time1 - cpu_time;
    /* 秒に直す */
    sec = (double)cpu_time2 / CLOCKS_PER_SEC;
    printf("配列Cをソートするのにかかった時間: %f秒\n", sec);
    return 0;
}
