#include <stdio.h>
#include <stdlib.h>

// ナイトの移動可能な8方向
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

// チェス盤の範囲内かを確認する関数
int is_valid(int x, int y, int n) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

// ナイトのグラフを生成する関数
void generate_knight_graph(int n) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            printf("Vertex (%d, %d): ", x, y);
            for (int i = 0; i < 8; i++) {
                int next_x = x + dx[i];
                int next_y = y + dy[i];
                if (is_valid(next_x, next_y, n)) {
                    printf("(%d, %d) ", next_x, next_y);
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int n;

    printf("Enter the size of the chess board (n x n): ");
    scanf("%d", &n);

    generate_knight_graph(n);

    return 0;
}