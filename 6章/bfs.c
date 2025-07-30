#include <stdio.h>
#include <stdlib.h>

int nvertices;
int **amatrix;

void bfsearch(int v1, int v2) {
    int *d; // 各頂点の始点からの深さ
    int *q; // キュー
    int q_exit, q_entry, q_length; // キューの操作に必要な変数
    int nvertices = 10; // 仮の頂点数（実際のグラフに応じて変更する）
    int steps, depth; // ステップ数と深さ
    int *path; // 経路を記録する配列
    int *parent; // 各頂点の親頂点を記録する配列
    int adj_matrix[10][10] = {0}; // 仮の隣接行列（実際のグラフに応じて変更する）

    // 各配列の初期化
    d = (int*)malloc(sizeof(int) * nvertices);
    q = (int*)malloc(sizeof(int) * nvertices);
    path = (int*)malloc(sizeof(int) * nvertices);
    parent = (int*)malloc(sizeof(int) * nvertices);

    for (int i = 0; i < nvertices; i++) {
        d[i] = -1;
        path[i] = -1;
        parent[i] = -1;
    }
    d[v1] = 0;
    q_exit = q_entry = q_length = 0;
    q[q_entry++] = v1; q_length++;

    steps = depth = 0;
    printf("Starting at vertex#%d ...", v1);

    // BFS のメインループ
    while (q_length > 0) {
        int current = q[q_exit++]; q_length--;

        // 隣接頂点の探索とキューへの追加
        for (int i = 0; i < nvertices; i++) {
            if (adj_matrix[current][i] && d[i] == -1) {
                d[i] = d[current] + 1;
                parent[i] = current;
                q[q_entry++] = i; q_length++;
            }
        }

        steps++;
        if (current == v2) {
            depth = d[current];
            break;
        }
    }

    // 経路の表示
    if (depth > 0) {
        printf("Shortest path to vertex#%d:", v2);
        int t = v2;
        int path_index = 0;
        while (t != -1) {
            path[path_index++] = t;
            t = parent[t];
        }
        for (int i = path_index - 1; i >= 0; i--) {
            printf("%d ", path[i]);
        }
        printf("");
    } else {
        printf("vertex#%d is unreachable from vertex#%d.", v2, v1);
    }

    // メモリの解放
    free(d);
    free(q);
    free(path);
    free(parent);
}


// 隣接行列を定義する関数（実際のグラフに応じて変更）
void create_adj_matrix(int adj_matrix[10][10]) {
    // 例: 頂点0から頂点1, 頂点1から頂点2への有向エッジがある場合
    adj_matrix[0][1] = 1;
    adj_matrix[1][2] = 1;
    // その他のエッジを定義
}

int main() {
    // グラフの頂点数
    nvertices = 7;

    // 隣接行列の初期化
    amatrix = (int**)malloc(sizeof(int*) * nvertices);
    for (int i = 0; i < nvertices; i++) {
        amatrix[i] = (int*)malloc(sizeof(int) * nvertices);
        for (int j = 0; j < nvertices; j++) {
            amatrix[i][j] = 0;
        }
    }

    // ここにグラフのエッジを設定する
    amatrix[0][1] = 1;
    amatrix[0][2] = 1;
    amatrix[1][3] = 1;
    amatrix[2][3] = 1;
    amatrix[2][4] = 1;
    amatrix[3][5] = 1;
    amatrix[4][5] = 1;
    amatrix[5][6] = 1;

    bfsearch(0, 4); // BFS 関数の呼び出し

    return 0;
}