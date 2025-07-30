#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max 10

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

/*スタックが空ならtrue，そうでないならfalseを返す*/
bool stackEmpty(stack *p){
    if (p->top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(stack *p, int i){
    if (p->top >= max - 1)
    {
        printf("overflow");/*容量を超えた入力はoverflow*/
    }
    else
    {
        p->top++;
        p->S[p->top] = i;/*スタックの先頭に要素を追加*/
    }
}

int pop(stack *p){
    if (stackEmpty(p))
    {
        printf("underflow");/*スタックが空ならunderflow*/
    }
    else
    {
        p->top--;
        return p->S[p->top + 1];
    }
}

void showStack(stack *p){
    printf("stack:");
    for (int i = p->top; i >= 0; i--)
    {
        printf("\n");
        printf("%d ", p->S[i]);
        printf("\n\n");
    }
}

int main(int argc, const char * argv[]) {
    int sw, n;
    
    stack S;
    init(&S);
    
    while(1){
        printf("0:push 1:pop 2:exit\n:");
        scanf("%d",&sw);
        switch(sw){
            case 0:
            printf("pushする数: ");
            scanf("%d", &n);
            push(&S, n); showStack(&S); break;
                
            case 1: printf("%d\n",pop(&S)); showStack(&S); break;
                
            case 2: exit(0); break;
        }
    }
}