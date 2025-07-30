#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max 100

/*スタックを定義*/
typedef struct stack{
    int S[max]; /*スタックを格納する配列*/
    int top; /*top[S]*/
}stack;

/*スタックを初期化する関数*/
void init(stack *p){
    p->top = -1;
    for(int i=0; i<max; i++)
        p->S[i] = 0;
}

void push(stack *p, int i){
    p->top++;
    p->S[p->top] = i;/*スタックの先頭に要素を追加*/
}

int pop(stack *p){
    p->top--;
    return p->S[p->top + 1];
}

void moveDisks(int n, stack *start, stack *goal, stack *mid, char s, char g, char m) {
    if (n <= 0) {
        return;
    }

    // n-1枚のディスクを補助スタックに移動
    moveDisks(n - 1, start, mid, goal, s, m, g);

    // 最後のディスクを目的のスタックに移動
    push(goal, pop(start));
    printf("Move disk from %c to %c\n", s, g);

    // 補助スタックから目的のスタックにn-1枚のディスクを移動
    moveDisks(n - 1, mid, goal, start, m, g, s);
}

int main() {
    int n;
    stack towers[3];
    
    // ユーザーにディスクの数を入力させる
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // スタックを初期化
    for (int i = 0; i < 3; i++) {
        init(&towers[i]);
    }

    // スタックAにディスクを配置
    for (int i = n; i > 0; i--) {
        push(&towers[0], i);
    }

    // ディスクを移動
    moveDisks(n, &towers[0], &towers[2], &towers[1], 'A', 'C', 'B');

    return 0;
}
