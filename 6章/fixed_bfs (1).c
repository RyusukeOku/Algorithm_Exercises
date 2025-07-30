#include <stdio.h>
#include <stdlib.h>

int nvertices;
int *d;
int *q;
int q_entry, q_exit, q_length;
int steps, depth;
int **amatrix;

void bfsearch(int v1, int v2) {
    int i, u;
    // 深さと経路記録の配列を用意
    int *parent = (int*)malloc(sizeof(int) * nvertices);
    for (i = 0; i < nvertices; i++) {
        d[i] = -1;
        parent[i] = -1;
    }
    d[v1] = 0;
    parent[v1] = v1;

    // 待ち行列の初期化
    q[q_entry++] = v1;
    q_length++;

    steps = depth = 0;
    printf("Starting at vertex#%d ...\n", v1);
    do {
        // 現在の頂点を取り出す
        u = q[q_exit++];
        q_length--;

        // 隣接する頂点を探索
        for (i = 0; i < nvertices; i++) {
            if (amatrix[u][i] && d[i] == -1) {
                // 未訪問の隣接頂点を待ち行列に追加
                d[i] = d[u] + 1;
                parent[i] = u;
                q[q_entry++] = i;
                q_length++;
                steps++;
                if (i == v2) {
                    // 終点に到達
                    depth = d[i];
                    break;
                }
            }
        }
    } while (depth <= 0 && q_length > 0);

    if (depth > 0) {
        printf("Reached vertex#%d at depth=%d after %d steps.\n", v2, depth, steps);
        printf("Path: ");
        int t = v2;
        while (t != v1) {
            printf("%d <- ", t);
            t = parent[t];
        }
        printf("%d\n", v1);
    } else {
        printf("Vertex#%d is unreachable from vertex#%d.\n", v2, v1);
    }

    free(d);
    free(q);
    free(parent);
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

    // グラフのエッジを設定
    amatrix[0][1] = 1;
    amatrix[0][2] = 1;
    amatrix[1][3] = 1;
    amatrix[2][3] = 1;
    amatrix[2][4] = 1;
    amatrix[3][5] = 1;
    amatrix[4][5] = 1;
    amatrix[5][6] = 1;

    // BFSの実行
    bfsearch(0, 4); // 頂点0から頂点4への経路を探索

    // 隣接行列のメモリを解放
    for (int i = 0; i < nvertices; i++) {
        free(amatrix[i]);
    }
    free(amatrix);

    return 0;
}