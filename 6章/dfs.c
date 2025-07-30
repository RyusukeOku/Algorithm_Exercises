#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfsearch_rec(int v1, int v2, int dp);
void tab(int steps, int dp);

char *visited;
int *path, *currentPath;
int nvertices;
int **amatrix;
int steps, depth, minDepth;

void printPath(int path[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

void dfsearch(int v1, int v2) {
    int i;

    visited = (char*)malloc(sizeof(char) * nvertices);
    path = (int*)malloc(sizeof(int) * nvertices);
    currentPath = (int*)malloc(sizeof(int) * nvertices);
    for (i = 0; i < nvertices; i++) {
        visited[i] = 0;
    }
    visited[v1] = 1;

    steps = depth = 0;
    minDepth = nvertices + 1;
    printf("Starting at vertex#%d,\n", v1);
    dfsearch_rec(v1, v2, 0);

    if (depth > 0) {
        printf("Shortest path to vertex#%d:\n", v2);
        printPath(path, depth);
    } else {
        printf("Vertex#%d is unreachable from vertex#%d.\n", v2, v1);
    }

    free(visited);
    free(path);
    free(currentPath);
}

void dfsearch_rec(int v1, int v2, int dp) {
    int i;
    currentPath[dp] = v1;

    for (i = 0; i < nvertices; i++) {
        if (amatrix[v1][i] == 1 && visited[i] == 0) {
            if (dp + 1 >= minDepth) continue; // 最短経路より長い場合はスキップ

            visited[i] = 1;
            steps++;
            tab(steps, dp + 1);
            printf("Visiting vertex#%d,\n", i);

            if (i == v2) {
                currentPath[dp + 1] = v2;
                depth = dp + 1;
                if (depth < minDepth) {
                    minDepth = depth;
                    memcpy(path, currentPath, sizeof(int) * (depth + 1));
                }
                return;
            }

            dfsearch_rec(i, v2, dp + 1);
            if (depth > 0 && depth <= minDepth){
                return;
            }

            visited[i] = 0;
            steps++;
            tab(steps, dp);
            printf("Back to vertex#%d,\n", v1);
        }
    }
}

void tab(int steps, int dp) {
    // ステップ数と深さに応じてインデントを出力する関数
    for (int i = 0; i < dp; i++) {
        printf("  ");
    }
}

int main(int argc, char *argv[]) {
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

    // 探索の実行
    dfsearch(0, 6); // 頂点0から頂点6への経路を探索

    // 隣接行列のメモリを解放
    for (int i = 0; i < nvertices; i++) {
        free(amatrix[i]);
    }
    free(amatrix);

    return 0;
}