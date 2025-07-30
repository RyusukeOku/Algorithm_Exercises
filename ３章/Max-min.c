#include <stdio.h>
//最大値を求める関数
int max(int a[], int n){
    int max_value = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max_value)
        {
            max_value = a[i];
        }
    }

    return max_value;
}
//最小値を求める関数
int min(int a[], int n){
    int min_value = a[0];

    for (int i = 0; i <= n; i++)
    {
        if (a[i] < min_value)
        {
            min_value = a[i];
        }
    }

    return min_value;
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

    printf("最大値：%d\n", max(array, n));
    printf("最小値：%d\n", min(array, n));
    return 0;
}